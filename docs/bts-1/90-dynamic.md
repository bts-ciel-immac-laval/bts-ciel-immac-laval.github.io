# Allocation dynamique

![cubes](../images/illustration/cubes.jpg)

## Cours

[:material-presentation-play: Afficher le cours :octicons-link-external-24:](https://slides.com/redmo53/optimiser-la-memoire/fullscreen){ .md-button .md-button--primary target="_blank" }

## Exercice 1

Afin de réaliser la saisie une chaîne de caractères, on désire allouer dynamiquement de la mémoire. La taille de cette chaîne sera de 25 caractères. Ecrire la ligne de code nécessaire à cette allocation :

1. avec la fonction `malloc`
 
2. avec la fonction `calloc`
        
3. avec la fonction `realloc`

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main() {
        char * ma_chaine = NULL;

        //                      malloc ↓ avec un paramètre
        ma_chaine = (char *) malloc(26 * sizeof(char));
        if (ma_chaine != NULL) {
            printf("malloc  : %p : %s\n", ma_chaine, ma_chaine);
            strcpy(ma_chaine, "abcdefghijklmnopqrstuvwxy");
            printf("strcpy  : %p : %s\n", ma_chaine, ma_chaine);
            free(ma_chaine);
            printf("free    : %p : %s\n", ma_chaine, ma_chaine);
            // On notera que libération ne signifie pas nettoyage de la zone !
        }

        //                     calloc ↓ avec deux paramètres
        ma_chaine = (char *) calloc(26, sizeof(char));
        if (ma_chaine != NULL) {
            printf("calloc  : %p : %s\n", ma_chaine, ma_chaine);
            strcpy(ma_chaine, "abcdefghijklmnopqrstuvwxy");
            printf("strcpy  : %p : %s\n", ma_chaine, ma_chaine);
            free(ma_chaine);
            printf("free    : %p : %s\n", ma_chaine, ma_chaine);
        }

        //            ↓  On n'oublie pas de réinitialiser à NULL sinon on essaie de réallouer un espace libéré !
        ma_chaine = NULL;
        ma_chaine = (char *) realloc(ma_chaine, 26);
        if (ma_chaine != NULL) {
            printf("realloc : %p : %s\n", ma_chaine, ma_chaine);
            strcpy(ma_chaine, "abcdefghijklmnopqrstuvwxy");
            printf("strcpy  : %p : %s\n", ma_chaine, ma_chaine);
            free(ma_chaine);
            printf("free    : %p : %s\n", ma_chaine, ma_chaine);
        }

        return 0;
    }
    ```

Refaire l’exercice avec un tableau de 100 `float`.

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        float * mes_floats = NULL;

        //                         malloc ↓ avec un paramètre
        mes_floats = (float *) malloc(100 * sizeof(float));
        if (mes_floats != NULL) {
            for (int i = 0; i < 100; i++) {
                mes_floats[i] = (i + 1) * 0.01;
            }
            for (int i = 0; i < 100; i++) {
                printf("%.2f ", mes_floats[i]);
            }
            printf("\n\n");
            free(mes_floats);
        }

        //                        calloc ↓ avec deux paramètres
        mes_floats = (float *) calloc(100, sizeof(float));
        if (mes_floats != NULL) {
            // Si on n'en remplit que la moitié...
            for (int i = 0; i < 50; i++) {
                mes_floats[i] = (i + 1) * 0.01;
            }
            // ...l'autre moitié est initialisé à 0 avec calloc !
            for (int i = 0; i < 100; i++) {
                printf("%.2f ", mes_floats[i]);
            }
            printf("\n\n");
            free(mes_floats);
        }

        //            ↓  On n'oublie pas de réinitialiser à NULL sinon on essaie de réallouer un espace libéré !
        mes_floats = NULL;
        mes_floats = (float *) realloc(mes_floats, 100 * sizeof(float));
        if (mes_floats != NULL) {
            for (int i = 0; i < 100; i++) {
                mes_floats[i] = (i + 1) * 0.01;
            }
            for (int i = 0; i < 100; i++) {
                printf("%.2f ", mes_floats[i]);
            }
            printf("\n\n");
            free(mes_floats);
        }

        return 0;
    }
    ```

## Exercice 2

Ecrire un programme permettant de saisir un tableau de nombres décimaux. Ce programme allouera la mémoire pour ce tableau dynamiquement. Le programme :

1.  Demandera de saisir la taille n du tableau.

2.  Allouera la mémoire nécessaire avec la fonction adaptée (penser à gérer le cas ou l’allocation s’avère impossible à effectuer).

3.  Effectuera la saisie des n éléments du tableau.

4.  Affichera le tableau.

5.  Libèrera l’espace mémoire alloué.


??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int taille = 0;
        float * tableau = NULL;

        system("chcp 65001");
        system("cls");

        // Saisie du nombre d'éléments
        printf("Nombre d'éléments : ");
        scanf("%d", &taille);
        if (taille <= 0) {
            puts("Le nombre d'éléments doit être strictement positif !!!");
            return -1;
        }

        // Création du tableau
        tableau = (float *) calloc(taille, sizeof(float));
        // ou : tableau = (float *) malloc(taille * sizeof(float));
        // ou : tableau = (float *) realloc(NULL, taille * sizeof(float));
        if (tableau == NULL) {
            puts("Erreur lors de l'allocation de mémoire...");
            return -2;
        }

        // Saisie des éléments
        printf("\nSaisie des %d éléments :\n", taille);
        for (int i = 0; i < taille; i++) {
            printf("#%02d : ", i + 1);
            scanf("%f", tableau + i);
        }

        // Affichage
        printf("\nAffichage des %d éléments :\n", taille);
        for (int i = 0; i < taille; i++) {
            printf("%s%.2f", i == 0 ? "" : ", ", tableau[i]);
        }

        // Libération de la mémoire
        free(tableau);

        return 0;
    }
    ```

## Exercice 3

On veut pouvoir saisir un tableau d’entiers. Le nombre d’entiers à saisir n’est pas connu à l’avance donc la taille du tableau grandira à chaque saisie.

+   Après la saisie, le tableau sera affiché avec un pointeur et la mémoire sera libérée.

+   Le programme affichera également la taille mémoire allouée.

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int taille = 0;
        int * tableau = NULL;
        char saisie[10];

        system("chcp 65001");
        system("cls");

        // Saisie des valeurs
        puts("Saisir les entiers (saisie vide = fin de saisie) :");
        // On ne peut détecter une saisie vide qu'en lisant des chaines de caractères
        do {
            printf("#%02d: ", taille + 1);
            // On stocke donc les saisies dans une chaine de caractères...
            gets(saisie);
            // ...et on vérifie si elle est vide.
            if (saisie[0] != '\0') {
                // S'il y a une valeur, on agrandit le tableau...
                tableau = (int *) realloc(tableau, ++taille * sizeof(int));
                if (tableau == NULL) {
                    puts("Erreur d'allocation !!!");
                    return -1;
                }
                // ...et on stocke dans la dernière case la valeaur saisie convertie en entier.
                tableau[taille - 1] = atoi(saisie);
            }
        }
        while (saisie[0] != '\0');

        // Affichage
        printf("Eléments saisis :\n[");
        for (int i = 0; i < taille; i++) {
            printf("%s%d", i == 0 ? "" : ", ", tableau[i]);
        }
        printf("]\n");

        // Mémoire allouée
        printf("Taille mémoire allouée : %d\n", taille * sizeof(int));

        // Libération de la mémoire
        free(tableau);

        return 0;
    }
    ```

## Exercice 4

Ecrire un programme qui permet à l'utilisateur de saisir un nombre indéfini de chaînes de caractères (127 caractères maximum). 

Les chaînes sont rangées successivement dans un tableau de pointeurs. 

La fin de la saisie sera signalée par une chaîne vide. 

Le programme sauvegardera les chaînes saisies dans un fichier texte horodaté avant de libérer la mémoire.

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    int main() {

        char ** tableau = NULL;
        int nbSaisies = 0;
        char saisie[128] = "", nomFichier[20] = "";
        time_t timestamp;
        struct tm horodatage;
        FILE * fichier = NULL;

        system("chcp 65001");
        system("cls");

        puts("Saisir les chaines de caractères (saisie vide pour arrêter) :");
        do {
            gets(saisie);
            // Quelquechose a été saisi...
            if (saisie[0] != '\0') {
                // Agrandir tableau pour pouvoir y stocker le pointeur vers la nouvelle
                // zone du tas où on va stocker la nouvelle chaîne saisie
                tableau = (char **) realloc(tableau, ++nbSaisies * sizeof(char *));
                if (tableau == NULL) {
                    puts("Erreur d'allocation !");
                    return -1;
                }
                
                // Réserver un espace pour stocker la nouvelle chaîne saisie
                // et stocker le pointeur vers cette zone à la fin de tableau
                tableau[nbSaisies - 1] = (char *) malloc((strlen(saisie) + 1) * sizeof(char));
                if (tableau[nbSaisies - 1] == NULL) {
                    puts("Erreur d'allocation !");
                    return -2;
                }
                
                // Copier dans la nouvelle zone la nouvelle chaîne saisie
                strcpy(tableau[nbSaisies - 1], saisie);
            }
        }
        while (saisie[0] != '\0');

        // Génération du nom de fichier horodaté
        timestamp = time(NULL);
        horodatage = *localtime(&timestamp);
        sprintf(nomFichier, "%04d%02d%02d%02d%02d%02d.txt", 
            horodatage.tm_year + 1900,
            horodatage.tm_mon + 1,
            horodatage.tm_mday,
            horodatage.tm_hour,
            horodatage.tm_min,
            horodatage.tm_sec
        );

        // Création du fichier
        fichier = fopen(nomFichier, "w");
        if (fichier == NULL) {
            puts("Erreur lors de la création du fichier");
            return -3;
        }

        // Ecriture dans le fichier et libération des zones mémoires des chaines saisies
        for (int i = 0; i < nbSaisies; i++) {
            fprintf(fichier, "%s\n", tableau[i]);
            free(tableau[i]);
        }

        // Libération du tableau
        free(tableau);

        // Fermeture du fichier
        fclose(fichier);

        return 0;
    }
    ```