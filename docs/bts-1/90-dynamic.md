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
        char * texte = NULL;

        texte = (char *) malloc(25 * sizeof(char));
        // texte = (char *) calloc(25, sizeof(char));
        // texte = (char *) realloc(NULL, 25 * sizeof(char));
        if (texte != NULL) {
            strcpy(texte, "hello, world!");
            printf("%p %s\n", texte, texte);
            free(texte);
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
        float * tab = NULL;

        tab = (float *) malloc(100 * sizeof(float));
        // tab = (float *) calloc(100, sizeof(float));
        // tab = (float *) realloc(NULL, 100 * sizeof(float));
        if (tab != NULL) {
            for (int i = 0; i < 100; i++) {
                tab[i] = i * 0.01;
            }
            for (int i = 0; i < 100; i++) {
                printf("%.2f\n", *(tab + i));
            }
            free(tab);
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

    ![waiting...](../images/meme/waiting-sonic.gif)

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        float * tab = NULL;
        int nb = 0;

        // 1. Demandera de saisir la taille n du tableau.
        printf("Nombre d'elements : ");
        scanf("%d", &nb);

        // 2. Allouera la mémoire nécessaire avec la fonction adaptée (penser à gérer le cas ou l’allocation s’avère impossible à effectuer).
        tab = (float *) calloc(nb, sizeof(float));
        if (tab == NULL) {
            puts("Erreur d'allocation dynamique.");
            return -1;
        }

        // 3. Effectuera la saisie des n éléments du tableau.
        for (int i = 0; i < nb; i++) {
            printf("#%02d : ", i + 1);
            scanf("%f", tab + i);
        }

        // 4. Affichera le tableau.
        printf("Voici les elements saisis\n[ ");
        for (int i = 0; i < nb; i++) {
            printf("%.2f ", tab[i]);
        }
        printf("]");

        // 5. Libèrera l’espace mémoire alloué.
        free(tab);
        
        return 0;
    }
    ```

## Exercice 3

On veut pouvoir saisir un tableau d’entiers. Le nombre d’entiers à saisir n’est pas connu à l’avance donc la taille du tableau grandira à chaque saisie.

+   Après la saisie, le tableau sera affiché avec un pointeur et la mémoire sera libérée.

+   Le programme affichera également la taille mémoire allouée.

??? success "Solution"

    ![waiting...](../images/meme/waiting-kid.gif)

    ```c
    
    ```

## Exercice 4

Ecrire un programme qui permet à l'utilisateur de saisir un nombre indéfini de chaînes de caractères (127 caractères maximum). 

Les chaînes sont rangées successivement dans un tableau de pointeurs. 

La fin de la saisie sera signalée par une chaîne vide. 

Le programme sauvegardera les chaînes saisies dans un fichier texte horodaté avant de libérer la mémoire.

??? success "Solution"

    ![waiting...](../images/meme/waiting-barney.gif)

    ```c
    
    ```