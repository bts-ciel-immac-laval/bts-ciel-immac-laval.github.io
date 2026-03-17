#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 
#include "dirent.h"
#include <sys/stat.h>
#include "md5.h"

typedef struct Fichier {
    char chemin[255];
    int taille;
    time_t derniere_modification;
    uint8_t checksum[16];
} Fichier;

typedef struct Difference {
    char type;
    char chemin[255];
    char date[20];
} Difference;

typedef struct Options {
    int verbose;
    char dossier_entree[255];
    char dossier_sortie[255];
    int retention;
} Options;

Options recuperer_options(int argc, char ** argv);
void generer_listing(char * chemin, Fichier ** fichiers, int * nb_fichiers);
void print_hash(uint8_t *p);
void sauvegarder_listing(Fichier * listing, int taille);
int filtrer_fichiers_data(const struct dirent * element);
int filtrer_fichiers_csv(const struct dirent * element);
int recuperer_dernier_listing(char * chemin, char * dernier_listing, char * date);
void charger_listing(char * chemin, Fichier ** listing, int * taille);
void nettoyer_fichiers(int nb_fichiers_a_conserver, int (*func)(const struct dirent *), int verbose);
void comparer_listings(Fichier * l1, int t1, char * d1, Fichier * l2, int t2, char * d2, Difference ** d, int * td);
void afficher_listing(Fichier * listing, int taille);
void afficher_differences(Difference * listing, int taille);
int comparer_checksum(uint8_t * a, uint8_t * b);
void exporter_differences(Difference * listing, int taille, char * dossier_export);

int main(int argc, char ** argv) {
    Options options;
    Fichier * listing_courant = NULL, * listing_precedent = NULL;
    Difference * differences = NULL;
    time_t now = time(NULL);
    struct tm * tm = localtime(&now);
    char chemin_listing_precedent[28] = "", date_listing_precedent[20], date_listing_courant[20];
    int taille_listing_courant = 0, taille_listing_precedent = 0, taille_differences = 0;

    // Récupération des options
    options = recuperer_options(argc, argv);

    // Affichage
    if (options.verbose) {
        system("chcp 65001");
        system("cls");
    }
    
    // Génération de la date courante
    sprintf(date_listing_courant, "%02d/%02d/%04d %02d:%02d:%02d", tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_hour, tm->tm_min, tm->tm_sec);
    
    // Chargement du dernier listing
    if (recuperer_dernier_listing(".", chemin_listing_precedent, date_listing_precedent)) {
        charger_listing(chemin_listing_precedent, &listing_precedent, &taille_listing_precedent);
        if (options.verbose) {
            printf("\n[Listing précédent](%s)", date_listing_precedent);
            afficher_listing(listing_precedent, taille_listing_precedent);
        }
    }

    // Génération du listing courant
    generer_listing(options.dossier_entree, &listing_courant, &taille_listing_courant);
    sauvegarder_listing(listing_courant, taille_listing_courant);
    if (options.verbose) {
        printf("\n[Listing précédent]");
        afficher_listing(listing_courant, taille_listing_courant);
    }
    // Purge des fichiers
    if (options.retention != -1) {
        nettoyer_fichiers(options.retention, filtrer_fichiers_data, options.verbose);
    }
    
    // Comparaison des listings
    comparer_listings(listing_precedent, taille_listing_precedent, date_listing_precedent, listing_courant, taille_listing_courant, date_listing_courant, &differences, &taille_differences);
    if (options.verbose) {
        printf("\n[Différences]");
        afficher_differences(differences, taille_differences);
    }

    // Export dans le fichier csv
    exporter_differences(differences, taille_differences, options.dossier_sortie);
    // Purge des fichiers
    if (options.retention != -1) {
        nettoyer_fichiers(options.retention, filtrer_fichiers_csv, options.verbose);
    }

    // Liberation de la mémoire
    free(listing_courant);
    free(listing_precedent);
    free(differences);

    return 0;
}

Options recuperer_options(int argc, char ** argv) {
    Options options = {
        .verbose = 0,
        .dossier_entree = "./Dossiers",
        .dossier_sortie = ".",
        .retention = -1
    };
    char opt;

    /*
    Options :
    -v
    -i dossier_a_surveiller
    -o dossier_export
    -r nb_fichiers_retention
    */ 

    while ((opt = getopt(argc, argv, "vi:o:r:")) != -1) {
        switch (opt) {
            case 'v':
                options.verbose = 1;
                break;
            case 'i':
                strcpy(options.dossier_entree, optarg);
                break;
            case 'o':
                strcpy(options.dossier_sortie, optarg);
                break;
            case 'r':
                options.retention = atoi(optarg);
                break;
            default:
                printf("Usage: %s -v -i dossier_a_surveiller -o dossier_export -r nb_fichiers_retention\n", argv[0]);
                exit(-6);
        }
    }

    return options;
}

/**
 * Génération du listing des fichiers
 */
void generer_listing(char * chemin, Fichier ** fichiers, int * nb_fichiers) {
    
    DIR * dossier = NULL;
    FILE * fichier = NULL;
    struct dirent * element = NULL;
    struct stat stats;
    char cheminElement[PATH_MAX] = "";

    // Ouverture du dossier
    dossier = opendir(chemin);
    if (dossier == NULL) {
        printf("Chemin inconnu : %s", chemin);
        exit(-1);
    }

    // Lister les "éléments" contenus
    while ((element = readdir(dossier)) != NULL) {
        // Ne pas traiter . et ..
        if (strcmp(element->d_name, ".") != 0 && strcmp(element->d_name, "..") != 0) {
            // Définition du chemin de l'élément
            sprintf(cheminElement, "%s\\%s", chemin, element->d_name);
            // Si l'élément est un dossier
            if (element->d_type == DT_DIR) {
                // Appel récursif sur le sous-dossier
                generer_listing(cheminElement, fichiers, nb_fichiers);
            }
            // Ce n'est pas un dossier
            else if (element->d_type == DT_REG) {
                *fichiers = (Fichier *) realloc(*fichiers, (*nb_fichiers + 1) * sizeof(Fichier));
                if (*fichiers == NULL) {
                    perror("Erreur d'agrandissement du listing !");
                    exit(-2);
                } 
                // On sauvegarde le chemin de l'élément
                strcpy((*fichiers)[*nb_fichiers].chemin, cheminElement);
                // Récupération des métadonnées du fichiers
                stat(cheminElement, &stats);
                (*fichiers)[*nb_fichiers].taille = stats.st_size;
                (*fichiers)[*nb_fichiers].derniere_modification = stats.st_mtime;
                // Calcul du checksum
                fichier = fopen(cheminElement, "r");
                if (fichier != NULL) {
                    md5File(fichier, (*fichiers)[*nb_fichiers].checksum);
                }
                *nb_fichiers += 1;
                fclose(fichier);
            }
        }
    }

    // Fermer le dossier
    closedir(dossier);
}

/**
 * Affichage d'un md5
 */
void print_hash(uint8_t *p){
    for(unsigned int i = 0; i < 16; ++i){
        printf("%02x", p[i]);
    }
}

/**
 * Sauvegarde du listing dans un fichier binaire
 */
void sauvegarder_listing(Fichier * listing, int taille) {

    char nom_fichier[28] = "listing_yyyymmddhhiiss.data";
    time_t now_in_s = time(NULL);
    struct tm * now = localtime(&now_in_s);
    FILE * fichier = NULL;

    // Génération du nom de fichier
    sprintf(nom_fichier, "listing_%04d%02d%02d%02d%02d%02d.data", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    // Ouverture du fichier en écriture
    fichier = fopen(nom_fichier, "wb");
    if (fichier == NULL) {
        perror("Erreur lors de la sauvegarde du listing");
        exit(-3);
    }

    // Insertion du nombre de fichiers enregistrés
    fwrite(&taille, sizeof(int), 1, fichier);

    // Ecriture cellule par cellule
    for (int i = 0; i < taille; i++) {
        fwrite(listing + i, sizeof(Fichier), 1, fichier);
    }

    fclose(fichier);
}

/**
 * Filtre les fichiers .data
 */
int filtrer_fichiers_data(const struct dirent * element) {
    char * point = strrchr(element->d_name, '.');
    if (point == NULL) {
        return 0;
    }
    return strcmp(point, ".data") == 0;
}

/**
 * Filtre les fichiers .csv
 */
int filtrer_fichiers_csv(const struct dirent * element) {
    char * point = strrchr(element->d_name, '.');
    if (point == NULL) {
        return 0;
    }
    return strcmp(point, ".csv") == 0;
}

/**
 * Récupérer le listing le plus récent
 */
int recuperer_dernier_listing(char * chemin, char * dernier_listing, char * date) {
    struct dirent ** fichiers;
    int nb_fichiers = 0;
    nb_fichiers = scandir(chemin, &fichiers, filtrer_fichiers_data, alphasort);
    struct tm tm;
    if (nb_fichiers > 0) {
        strcpy(dernier_listing, fichiers[nb_fichiers - 1]->d_name);
        sscanf(fichiers[nb_fichiers - 1]->d_name, "listing_%4d%2d%2d%2d%2d%2d.data", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
        sprintf(date, "%02d/%02d/%04d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon, tm.tm_year, tm.tm_hour, tm.tm_min, tm.tm_sec);
        return 1;
    }
    return 0;
}

/**
 * Supprimer les fichiers en trop
 */
void nettoyer_fichiers(int nb_fichiers_a_conserver, int (*func)(const struct dirent *), int verbose) {
    struct dirent ** fichiers;
    int nb_fichiers = 0, resultat;
    nb_fichiers = scandir(".", &fichiers, func, alphasort);
    if (verbose) {
        printf("\n[Purge]\n");
    }
    for (int i = 0; i < nb_fichiers - nb_fichiers_a_conserver; i++) {
        resultat = remove(fichiers[i]->d_name);
        if (resultat != 0) {
            perror("Erreur lors de la purge des .data");
        }
        else if (verbose) {
            printf("%s supprimé.\n", fichiers[i]->d_name);
        }
    }
}

/**
 * Chargement d'un listing
 */
void charger_listing(char * chemin, Fichier ** listing, int * taille) {
    
    FILE * fichier = NULL;

    // Ouverture du fichier en lecture
    fichier = fopen(chemin, "rb");
    if (fichier == NULL) {
        perror("Erreur lors de la lecture du listing précédent");
        exit(-4);
    }

    // Lecture du nombre de fichiers enregistrés
    fread(taille, sizeof(int), 1, fichier);

    // lecture du tableau complet
    *listing = (Fichier *) calloc(*taille, sizeof(Fichier));
    fread(*listing, sizeof(Fichier), *taille, fichier);

    fclose(fichier);
}

/**
 * Comparaison de deux listings
 */
void comparer_listings(Fichier * l1, int t1, char * d1, Fichier * l2, int t2, char * d2, Difference ** d, int * td) {
    int i1 = 0, i2 = 0, comparaison = 0;
    while(i1 < t1 && i2 < t2) {
        comparaison = strcmp(l1[i1].chemin, l2[i2].chemin);
        // Nouveau fichier
        if (comparaison > 0) {
            *d = (Difference *) realloc(*d, (*td + 1) * sizeof(Difference));
            (*d)[*td].type = 'C';
            strcpy((*d)[*td].chemin, l2[i2].chemin);
            strcpy((*d)[*td].date, d2);
            (*td)++;
            i2++;
        }
        // Fichier supprimé
        else if (comparaison < 0) {
            *d = (Difference *) realloc(*d, (*td + 1) * sizeof(Difference));
            (*d)[*td].type = 'D';
            strcpy((*d)[*td].chemin, l1[i1].chemin);
            strcpy((*d)[*td].date, d1);
            (*td)++;
            i1++;
        }
        // Fichier modifié ?
        else if (l1[i1].taille != l2[i2].taille || l1[i1].derniere_modification != l2[i2].derniere_modification || comparer_checksum(l1[i1].checksum, l2[i2].checksum) != 1) {
            *d = (Difference *) realloc(*d, (*td + 1) * sizeof(Difference));
            (*d)[*td].type = 'U';
            strcpy((*d)[*td].chemin, l1[i1].chemin);
            strcpy((*d)[*td].date, d2);
            (*td)++;
            i1++;
            i2++;
        }
        // Fichiers identiques
        else {
            i1++;
            i2++;
        }
    }
    // S'il reste des fichiers : fichiers supprimés
    while(i1 < t1) {
        *d = (Difference *) realloc(*d, (*td + 1) * sizeof(Difference));
        (*d)[*td].type = 'D';
        strcpy((*d)[*td].chemin, l1[i1].chemin);
        strcpy((*d)[*td].date, d1);
        (*td)++;
        i1++;
    }
    // S'il reste des fichiers : fichiers ajoutés
    while(i2 < t2) {
        *d = (Difference *) realloc(*d, (*td + 1) * sizeof(Difference));
        (*d)[*td].type = 'C';
        strcpy((*d)[*td].chemin, l2[i2].chemin);
        strcpy((*d)[*td].date, d2);
        (*td)++;
        i2++;
    }
}

/**
 * Comparaison de deux checksums
 */
int comparer_checksum(uint8_t * a, uint8_t * b) {
    for (int i = 0; i < 16; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Afficher le contenu d'un listing
 */
void afficher_listing(Fichier * listing, int taille) {
    puts("");
    for (int i = 0; i < taille; i++) {
        printf("%-50s %10d %12d  ", listing[i].chemin, listing[i].taille, listing[i].derniere_modification);
        print_hash(listing[i].checksum);
        printf("\n");
    }
}

/**
 * Afficher le contenu d'un tableau de différences
 */
void afficher_differences(Difference * listing, int taille) {
    puts("");
    if (taille == 0) {
        puts("Aucune différence.");
    }
    for (int i = 0; i < taille; i++) {
        printf("%c %-50s  %s\n", listing[i].type, listing[i].chemin, listing[i].date);
    }
}

/**
 * Export des différences dans un fichier CSV
 */
void exporter_differences(Difference * listing, int taille, char * dossier_export) {

    char chemin_fichier[255] = "";
    time_t now_in_s = time(NULL);
    struct tm * now = localtime(&now_in_s);
    FILE * fichier = NULL;

    // Génération du nom de fichier
    sprintf(chemin_fichier, "%s/delta_%04d%02d%02d%02d%02d%02d.csv", dossier_export, now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    // Ouverture du fichier en écriture
    fichier = fopen(chemin_fichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'export CSV");
        exit(-5);
    }

    // Ecriture ligne à ligne
    for (int i = 0; i < taille; i++) {
        fprintf(fichier, "%c;%s;%s\n", listing[i].type, listing[i].chemin, listing[i].date);
    }

    fclose(fichier);
}