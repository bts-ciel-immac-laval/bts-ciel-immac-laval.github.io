#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h> 
#include "dirent.h"
#include <sys/stat.h>
#include "md5.h"

typedef struct fichier {
    char chemin[255];
    int taille;
    time_t derniere_modification;
    uint8_t checksum[16];
} fichier;

typedef struct difference {
    char type;
    char chemin[255];
    char date[20];
} difference;

void generer_listing(char * chemin, fichier * fichiers, int * nb_fichiers);
void print_hash(uint8_t *p);
void sauvegarder_listing(fichier * listing, int taille);
int filtrer_fichiers_data(const struct dirent * element);
int recuperer_dernier_listing(char * chemin, char * dernier_listing, char * date);
void charger_listing(char * chemin, fichier * listing, int * taille);
void comparer_listings(fichier * l1, int t1, char * d1, fichier * l2, int t2, char * d2, difference * d, int * td);
void afficher_listing(fichier * listing, int taille);
void afficher_differences(difference * listing, int taille);
int comparer_checksum(uint8_t * a, uint8_t * b);
void exporter_differences(difference * listing, int taille);

int main() {
    fichier listing_courant[100], listing_precedent[100];
    difference differences[100];
    time_t now = time(NULL);
    struct tm * tm = localtime(&now);
    char chemin_listing_precedent[28] = "", date_listing_precedent[20], date_listing_courant[20];
    int taille_listing_courant = 0, taille_listing_precedent = 0, taille_differences = 0;
    sprintf(date_listing_courant, "%02d/%02d/%04d %02d:%02d:%02d", tm->tm_mday, tm->tm_mon, tm->tm_year, tm->tm_hour, tm->tm_min, tm->tm_sec);
    
    if (recuperer_dernier_listing(".", chemin_listing_precedent, date_listing_precedent)) {
        charger_listing(chemin_listing_precedent, listing_precedent, &taille_listing_precedent);
    }

    generer_listing("./Dossiers", listing_courant, &taille_listing_courant);
    sauvegarder_listing(listing_courant, taille_listing_courant);
    
    // afficher_listing(listing_precedent, taille_listing_precedent);
    // afficher_listing(listing_courant, taille_listing_courant);
    
    comparer_listings(listing_precedent, taille_listing_precedent, date_listing_precedent, listing_courant, taille_listing_courant, date_listing_courant, differences, &taille_differences);
    // afficher_differences(differences, taille_differences);

    exporter_differences(differences, taille_differences);

    return 0;
}

/**
 * Génération du listing des fichiers
 */
void generer_listing(char * chemin, fichier * fichiers, int * nb_fichiers) {
    
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
                // On sauvegarde le chemin de l'élément
                strcpy(fichiers[*nb_fichiers].chemin, cheminElement);
                // Récupération des métadonnées du fichiers
                stat(cheminElement, &stats);
                fichiers[*nb_fichiers].taille = stats.st_size;
                fichiers[*nb_fichiers].derniere_modification = stats.st_mtime;
                // Calcul du checksum
                fichier = fopen(cheminElement, "r");
                if (fichier != NULL) {
                    md5File(fichier, fichiers[*nb_fichiers].checksum);
                }
                *nb_fichiers += 1;
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
void sauvegarder_listing(fichier * listing, int taille) {

    char nom_fichier[28] = "listing_yyyymmddhhiiss.data";
    time_t now_in_s = time(NULL);
    struct tm * now = localtime(&now_in_s);
    FILE * fichier = NULL;

    // Génération du nom de fichier
    sprintf(nom_fichier, "listing_%04d%02d%02d%02d%02d%02d.data", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    /* A COMPLETER */
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
 * Chargement d'un listing
 */
void charger_listing(char * chemin, fichier * listing, int * taille) {
    
    FILE * fichier = NULL;
    
    /* A COMPLETER */
}

/**
 * Comparaison de deux listings
 */
void comparer_listings(fichier * l1, int t1, char * d1, fichier * l2, int t2, char * d2, difference * d, int * td) {
    int i1 = 0, i2 = 0, comparaison = 0;
    while(i1 < t1 && i2 < t2) {
        comparaison = strcmp(l1[i1].chemin, l2[i2].chemin);
        // Nouveau fichier
        if (comparaison > 0) {
            d[*td].type = 'C';
            strcpy(d[*td].chemin, l2[i2].chemin);
            strcpy(d[*td].date, d2);
            (*td)++;
            i2++;
        }
        // Fichier supprimé
        else if (comparaison < 0) {
            d[*td].type = 'D';
            strcpy(d[*td].chemin, l1[i1].chemin);
            strcpy(d[*td].date, d1);
            (*td)++;
            i1++;
        }
        // Fichier modifié ?
        else if (l1[i1].taille != l2[i2].taille || l1[i1].derniere_modification != l2[i2].derniere_modification || comparer_checksum(l1[i1].checksum, l2[i2].checksum) != 1) {
            d[*td].type = 'U';
            strcpy(d[*td].chemin, l1[i1].chemin);
            strcpy(d[*td].date, d2);
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
        d[*td].type = 'D';
        strcpy(d[*td].chemin, l1[i1].chemin);
        strcpy(d[*td].date, d1);
        (*td)++;
        i1++;
    }
    // S'il reste des fichiers : fichiers ajoutés
    while(i2 < t2) {
        d[*td].type = 'C';
        strcpy(d[*td].chemin, l2[i2].chemin);
        strcpy(d[*td].date, d2);
        (*td)++;
        i2++;
    }
}

/**
 * Comparaison de deux checksums
 */
int comparer_checksum(uint8_t * a, uint8_t * b) {
    
    /* A COMPLETER */

}

/**
 * Afficher le contenu d'un listing
 */
void afficher_listing(fichier * listing, int taille) {
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
void afficher_differences(difference * listing, int taille) {
    puts("");
    for (int i = 0; i < taille; i++) {
        printf("%c %-50s %12d\n", listing[i].type, listing[i].chemin, listing[i].date);
    }
}

/**
 * Export des différences dans un fichier CSV
 */
void exporter_differences(difference * listing, int taille) {

    char nom_fichier[25] = "delta_yyyymmddhhiiss.csv";
    time_t now_in_s = time(NULL);
    struct tm * now = localtime(&now_in_s);
    FILE * fichier = NULL;

    // Génération du nom de fichier
    sprintf(nom_fichier, "delta_%04d%02d%02d%02d%02d%02d.csv", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);

    /* A COMPLETER */
}