# Projet Charlie

![charlie](../images/illustration/charlie.jpg)

Lorsqu'un pirate s'introduit dans un serveur hébergeant un (ou des) site(s) web, son objectif n'est pas de "détruire" le serveur, mais d'y ajouter des scripts (ou de modifier des scripts existants) pour nuire à l'activité du site web (en diffusant de la propagande par exemple...).

![pirate](../images/illustration/pirate.jpg){ align=right }

En supplément de mesures anti-intusion, on vous demande de développer un programme capable de comparer l'état d'un dossier entre deux exécutions.

Le programme doit fournir une liste des fichiers ajoutés, modifiés ou supprimés depuis la précédente exécution du programme.

Pour éviter les faux positifs, on créera une liste d'exclusion.

Optionnellement, le programme gèrera son historique de rapport en le purgeant régulièrement (durée de rétention paramétrable).

## Analyse / Conception

Les techniques que nous devons maîtriser :

- [x] Parcourir un dossier

    - [x] Lister les fichiers contenus dans un dossier

    ??? note "Utilisation de dirent.h"

        ```c
        #include <stdio.h>
        #include <string.h> 
        // La bibliothèque qui permet d'explorer un dossier dans le système de fichier
        #include "dirent.h"

        int main() {
            DIR * dossier = NULL;
            struct dirent * element = NULL;

            // Ouverture du dossier
            dossier = opendir("[chemin (relatif ou absolu) du dossier à explorer]");
            if (dossier == NULL) {
                puts("Chemin inconnu !");
                return - 1;
            }

            // Lister les "éléments" contenus
            while ((element = readdir(dossier)) != NULL) {
                // Affichage du nom de l'élément
                puts(element->d_name);
            }

            // Fermer le dossier
            closedir(dossier);

            return 0;
        }
        ```
        
    - [x] Naviguer en profondeur dans l'arborescence
     
    ??? note "Appel récursif d'une fonction"

        ```c
        #include <stdio.h>
        #include <string.h> 
        #include <stdlib.h> 
        // La bibliothèque qui permet d'explorer un dossier dans le système de fichier
        #include "dirent.h"
        
        void ls(char * chemin);
        
        int main() {
            ls("[Chemin (relatif ou absolu) du dossier racine]");
            return 0;
        }
        
        // Liste les éléments contenus dans un dossier
        void ls(char * chemin) {
            DIR * dossier = NULL;
            struct dirent * element = NULL;
            char cheminElement[PATH_MAX] = "";
        
            // Ouverture du dossier
            dossier = opendir(chemin);
            if (dossier == NULL) {
                puts("Chemin inconnu !");
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
                        // Appel récursif de ls sur le sous-dossier
                        ls(cheminElement);
                    }
                    // Ce n'est pas un dossier
                    else {
                        // On affiche le chemin de l'élément
                        puts(cheminElement);
                    }
                }
            }
        
            // Fermer le dossier
            closedir(dossier);
        }
        ```

- [x] Détecter la modification d'un fichier

    - [x] Récupérer la date de dernière modification d'un fichier
    
    - [x] Récupérer la taille d'un fichier
     
    ??? note "Recupérer les métadonnées d'un fichier"

        ```c
        #include <stdio.h>
        // La bibliothèque pour afficher les informations d'un fichier
        #include <sys/stat.h>
        
        int main() {
            // La structure qui contiendra les informations du fichier
            struct stat stats;
            
            // Récupération des métadonnées du fichiers
            stat("[Chemin vers le fichier]", &stats);
        
            // Affichage du poids et de la date de dernère modification (en secondes)
            printf("%d, %d", stats.st_size, stats.st_mtime);
            
            return 0;
        }
        ```
    
    - [x] Calculer un checksum d'un fichier

    ??? note "Calculer le checksum md5 d'un fichier"

        La bibliothèque md5.h est à télécharger dans la partie Ressources en bas de page.

        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <stdint.h>

        #include "md5.h"

        void print_hash(uint8_t *p){
            for(unsigned int i = 0; i < 16; ++i){
                printf("%02x", p[i]);
            }
            printf("\n");
        }

        // On passera le chemin du fichier en ligne de commande
        int main(int argc, char ** argv){
            uint8_t result[16];
            if (argc == 2) {
                FILE * f = fopen(argv[1], "r");
                if (f != NULL) {
                    md5File(f, result);
                    print_hash(result);
                }
            }
            return 0;
        }
        ```
    
- [x] Générer un tableau avec les informations (données structurées)
    
- [x] Sauvegarder le tableau entre deux exécutions

    - [x] Sauvegarder un fichier binaire

    ??? note "Ecrire dans un fichier binaire"

        ```c
        #include <stdio.h>
        #include <string.h>

        int main() {

            // Ouverture en écriture binaire
            FILE * f = fopen("test.data", "wb");
            if (f == NULL) {
                puts("Impossible d'ouvrir le fichier test.data");
                return -1;
            }

            int i = 42;
            char string[25] = "test";
            float pi = 3.14;

            // Ecriture : on doit indiquer la taille de chaque éléments à écrire
            fwrite(&i, sizeof(int), 1, f);
            fwrite(string, sizeof(char), 25, f);
            fwrite(&pi, sizeof(float), 1, f);

            fclose(f);

            return 0;
        }
        ```

    - [x] Trouver une convention de nommage (si plusieurs dossiers surveillés)

    ??? note "Lire dans un fichier binaire"

        ```c
        #include <stdio.h>

        int main() {

            // Ouverture en lecture binaire
            FILE * f = fopen("test.data", "rb");
            if (f == NULL) {
                puts("Impossible d'ouvrir le fichier test.data");
                return -1;
            }

            int i = 0;
            char string[25] = "";
            float pi = 0;
            
            // Lecture : on doit indiquer la taille de chaque éléments à lire, 
            // ce qui implique de connaitre l'organisation du fichier et, donc,
            // une réflexion sur les éléments de taille dynamique.

            fread(&i, sizeof(int), 1, f);
            fread(string, sizeof(char), 25, f);
            fread(&pi, sizeof(float), 1, f);

            printf("%d %s %f", i, string, pi);

            fclose(f);

            return 0;
        }
        ```

- [x] Comparer deux tableaux

    - [x] Détecter un ajout

    - [x] Détecter une suppression

    - [x] Détecter une modification

- [x] Générer le rapport

    - [x] Ecrire un fichier au format CSV

- [ ] Gérer la purge des fichiers

    - [ ] Supprimer un fichier

- [ ] Gérer une liste d'exclusion


## Ressources

[:material-file-download: Télécharger dirent.h](../files/bts1/dirent.h){ .md-button .md-button--primary }

[:material-file-download: Télécharger une arborescence de test](../files/bts1/arborescence.zip){ .md-button .md-button--primary }

[:material-file-download: Télécharger md5.h](../files/bts1/md5.h){ .md-button .md-button--primary }
