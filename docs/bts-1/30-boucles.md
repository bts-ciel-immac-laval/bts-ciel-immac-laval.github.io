# 02 - Boucles

## Exercice 1

Ecrire un programme qui affiche tous les nombres de 1 à 1000 avec les trois types de boucles.

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {

        int i;

        // Boucle for
        printf("for :\n");
        for (i = 1; i <= 1000; i++) {   // Faire attention aux bornes
            printf("%d ", i);
        }

        // Boucle while
        printf("\n\nwhile :\n");
        i = 1;                          // Ne pas oublier d'initialiser le compteur avant la boucle
        while (i <= 1000) {
            printf("%d ", i);
            i++;
        }

        // Boucle do...while
        printf("\n\ndo...while :\n");
        i = 1;                          // idem
        do {
            printf("%d ", i);
            i++;
        } while (i <= 1000);

        return 0;
    }
    ```

## Exercice 2

Ecrire un programme qui affiche les nombres pairs de 2 à 100 avec une boucle `for` de deux manières différentes.

??? success "Correction"

    ![](../images/meme/waiting-britney.gif)

## Exercice 3

Ecrire un programme qui demande un nombre positif à l'utilisateur puis affiche le décompte à partir de ce nombre jusqu'à 0 avec les trois types de boucles.

??? success "Correction"

    ![](../images/meme/waiting-pikachu.gif)