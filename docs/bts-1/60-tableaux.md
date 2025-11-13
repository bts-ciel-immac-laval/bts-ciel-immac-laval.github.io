# 05 - Tableaux

## Cours

![Tableaux](../pdf/cours/bts1/bts1_09_tableaux_1.pdf)

## Exercice 1

Ecrire un programme `exo1.c` qui permet de 

1. Saisir 3 entiers et de les stocker dans un tableau,

2. Afficher les 3 entiers avec un seul printf.

```
> ./exo1.exe
Saisir un entier : 2
Saisir un entier : 6
Saisir un entier : 3

Les entiers sont 2, 6, 3
```

??? danger "Aller plus loin"
    
    Refaire l’exercice en notation pointeur 👿

??? success "Solution"
    
    En écriture tableau :

    ```c
    #include <stdio.h>

    int main() {
        int mon_beau_tableau[3];

        for (int i = 0; i < 3; i++) {
            printf("Saisir un entier : ");
            scanf("%d", &mon_beau_tableau[i]);
        }

        printf("\nLes entiers sont %d, %d et %d"
                , mon_beau_tableau[0]
                , mon_beau_tableau[1]
                , mon_beau_tableau[2]);

        return 0;
    }
    ```
    
    En écriture pointeur :

    ```c
    #include <stdio.h>

    int main() {
        int mon_beau_tableau[3];

        for (int i = 0; i < 3; i++) {
            printf("Saisir un entier : ");
            scanf("%d", mon_beau_tableau + i);
        }

        printf("\nLes entiers sont %d, %d et %d"
                , * mon_beau_tableau
                , *(mon_beau_tableau + 1)
                , *(mon_beau_tableau + 2));

        return 0;
    }
    ```

## Exercice 2

Ecrire un programme `exo2.c` qui :

1. demande à l’utilisateur de saisir 5 notes qu'il stocke dans un tableau,

2. affiche les notes saisies

3. qui affiche la moyenne des notes saisies.

```
> ./exo_2.exe
Saisir 5 notes :
#1 : 12
#2 : 5.5
#3 : 14
#4 : 16.5
#5 : 19

Les notes saisies sont : 12.0, 5.5, 14.0, 16.5, 19.0.

La moyenne est de 13.4.
```

??? danger "Aller plus loin 1"

    Utiliser 3 boucles différentes pour chaque action (for, while et do/while).

??? danger "Aller plus loin 2"

    Refaire l’exercice en notation pointeur 😈

??? danger "Aller plus loin 3"
    
    Déplacer le calcul de la moyenne dans une fonction.

??? success "Solution"
    
    ```c
    #include <stdio.h>

    float moyenne(float *, int);

    int main() {
    float notes[5];

    // Saisie (boucle for + écriture pointeur)
    printf("Saisir 5 notes :\n");
    for (int i = 0; i < 5; i++) {
        printf("#%d : ", i + 1);
        scanf("%f", notes + i);
    }

    // Affichage (boucle while + écriture tableau)
    int i = 0;
    printf("\nLes notes saisies sont : ");
    while (i < 5) {
        printf(" %.1f%c", notes[i], i < 4 ? ',' : '.');
        i++;
    }

    // Moyenne (boucle do/while + écriture pointeur + fonction)
    printf("\n\nLa moyenne est de %.1f.", moyenne(notes, 5));

    return 0;
    }

    // On passe le pointeur vers le premier élément + la taille du tableau
    float moyenne(float * tab, int tailleTab) {
    int i = 0;
    float somme = 0;
    do {
        somme += *(tab + i);
        i++;
    } while(i < tailleTab);
    return somme / tailleTab;
    }
    ```

## Exercice 3

Ecrire un programme `exo_3.c` qui stocke les multiples de 5 de 0 à 255 dans un tableau puis les affiche en ordre inverse à partir du tableau.

??? success "Solution"
    
    ![WaitForIt](../images/meme/waiting-barney.gif)
