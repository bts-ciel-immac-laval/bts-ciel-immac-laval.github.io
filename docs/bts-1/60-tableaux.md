# 05 - Tableaux

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
    
    En notation tableau : 

    ```c
    #include <stdio.h>

    int main() {
        
        int mon_beau_tableau[3];

        // Lecture
        printf("Saisir un entier : ");
        scanf("%d", &mon_beau_tableau[0]);
        printf("Saisir un entier : ");
        scanf("%d", &mon_beau_tableau[1]);
        printf("Saisir un entier : ");
        scanf("%d", &mon_beau_tableau[2]);

        // Affichage
        printf("Les entiers sont %d, %d, %d", 
                mon_beau_tableau[0], 
                mon_beau_tableau[1], 
                mon_beau_tableau[2]
        );

        return 0;
    }
    ```

    En notation pointeur :

    ```c
    #include <stdio.h>

    int main() {
        
        int mon_beau_tableau[3];

        // Lecture
        printf("Saisir un entier : ");
        scanf("%d", mon_beau_tableau);
        printf("Saisir un entier : ");
        scanf("%d", mon_beau_tableau + 1);
        printf("Saisir un entier : ");
        scanf("%d", mon_beau_tableau + 2);

        // Affichage
        printf("Les entiers sont %d, %d, %d", 
                *mon_beau_tableau, 
                *(mon_beau_tableau + 1), 
                *(mon_beau_tableau + 2)
        );

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
    
    Solution "simple" :

    ```c
    #include <stdio.h>

    int main() {
        
        float notes[5], moyenne = 0;

        // Lecture
        printf("Saisir 5 notes :\n");
        for (int i = 0; i < 5; i++) {
            printf("%d: ", i + 1);
            scanf("%f", &notes[i]);
        }

        // Affichage
        printf("\nLes notes saisies sont : ");
        for (int i = 0; i < 5; i++) {
            if (i != 0) {
                printf(", ");
            }
            printf("%.1f", notes[i]);
        }
        printf(".\n\n");

        // Moyenne
        for (int i = 0; i < 5; i++) {
            moyenne += notes[i];
        }
        moyenne /= 5;
        printf("La moyenne est de %.1f.", moyenne);

        return 0;
    }
    ```

    Aller plus loin 1 : 

    ```c
    #include <stdio.h>

    int main() {
        
        float notes[5], moyenne = 0;
        int i;

        // Lecture
        printf("Saisir 5 notes :\n");
        for (int i = 0; i < 5; i++) {
            printf("%d: ", i + 1);
            scanf("%f", &notes[i]);
        }

        // Affichage
        printf("\nLes notes saisies sont : ");
        i = 0;
        while (i < 5) {
            if (i != 0) {
                printf(", ");
            }
            printf("%.1f", notes[i]);
            i++;
        }
        printf(".\n\n");

        // Moyenne
        i = 0;
        do {
            moyenne += notes[i++];
        }
        while (i < 5);
        moyenne /= 5;
        printf("La moyenne est de %.1f.", moyenne);

        return 0;
    }
    ```

    Aller plus loin 2 : 

    ```c
    #include <stdio.h>

    int main() {
        
        float notes[5], moyenne = 0;

        // Lecture
        printf("Saisir 5 notes :\n");
        for (int i = 0; i < 5; i++) {
            printf("%d: ", i + 1);
            scanf("%f", notes + i);
        }

        // Affichage
        printf("\nLes notes saisies sont : ");
        for (int i = 0; i < 5; i++) {
            if (i != 0) {
                printf(", ");
            }
            printf("%.1f", *(notes + i));
        }
        printf(".\n\n");

        // Moyenne
        for (int i = 0; i < 5; i++) {
            moyenne += *(notes + i);
        }
        moyenne /= 5;
        printf("La moyenne est de %.1f.", moyenne);

        return 0;
    }
    ```

    Aller plus loin 3 : 

    ```c
    #include <stdio.h>
    
    #define TAILLE 5

    float moyenne(float *, int);

    int main() {
        
        float notes[TAILLE];

        // Lecture
        printf("Saisir %d notes :\n", TAILLE);
        for (int i = 0; i < TAILLE; i++) {
            printf("%d: ", i + 1);
            scanf("%f", notes + i);
        }

        // Affichage
        printf("\nLes notes saisies sont : ");
        for (int i = 0; i < TAILLE; i++) {
            if (i != 0) {
                printf(", ");
            }
            printf("%.1f", *(notes + i));
        }
        printf(".\n\n");

        // Moyenne
        printf("La moyenne est de %.1f.", moyenne(notes, TAILLE));

        return 0;
    }

    float moyenne(float * tab, int taille) {
        float moyenne = 0;
        for (int i = 0; i < taille; i++) {
            moyenne += tab[i];
        }
        moyenne /= taille;
        return moyenne;
    }
    ```

## Exercice 3

Ecrire un programme `exo_3.c` qui stocke les multiples de 5 de 0 à 255 dans un tableau puis les affiche en ordre inverse à partir du tableau.

??? success "Solution"
    
    Solution avec 2 indices

    ```c
    #include <stdio.h>

    int main() {

        // 52 valeurs à stocker
        int multiplesDe5[52];
        
        // Parcours de tous les nombres de 0 à 255
        // j va servire d'indice pour le tableau multiplesDe5
        for (int i = 0, j = 0; i <= 255; i++) {
            // Si i est multiple de 5...
            if (i % 5 == 0) {
                // ...on le stocke dans le tableau
                multiplesDe5[j] = i;
                j++;
            }
        }

        // Affichage en ordre inverse
        for (int i = 51; i >= 0; i--)
        {
            printf("%d\n", multiplesDe5[i]);
        }
        
        return 0;
    }
    ```

    Solution avec un pointeur

    ```c
    #include <stdio.h>

    int main() {

        // 52 valeurs à stocker
        int multiplesDe5[52];
        int * p = multiplesDe5;
        
        // Parcours de tous les nombres de 0 à 255
        for (int i = 0; i <= 255; i++) {
            // Si i est multiple de 5...
            if (i % 5 == 0) {
                // ...on le stocke dans le tableau
                *(p) = i;
                p++;
            }
        }

        // Affichage en ordre inverse
        do {
            p--;
            printf("%d\n", *p);
        } while (p != multiplesDe5);
        
        return 0;
    }
    ```

## Exercice 4

Dans un programme `exo_4.c` :

1. Initialiser un tableau avec le nombre de jours de chaque mois (31 jours en janvier, 28 en février...).

2. En se servant de ce tableau, écrire un programme qui affiche le numéro du jour dans l'année d'une date saisie (format `JJ/MM`) sans tenir compte des années bissextiles :)

```
Saisir une date : 07/09
C'est le 250ème jour de l'année !
```

??? question "Avez-vous pensé à tout ?"
    
    Avez-vous pensé à l'affichage du premier jour de l'année ?   

??? success "Solution"
    
    ![Minute papillon !](../images/meme/waiting-moone.gif) 

## Exercice 5

Reprendre le code de l'exercice 4 dans un programme `exo_5.c`, permettre la saisie de date au format `JJ/MM/AAAA` et gérer le cas des années bissextiles !

```
Saisir une date : 07/09/2020
C'était le 251ème jour de l'année 2024 !
```

??? success "Solution"
    
    ![Minute papillon !](../images/meme/waiting-sonic.gif)

## Exercice 6

Créer un programme `exo_6.c` qui :

+ crée deux tableaux de tailles différentes (utiliser des constantes pour pouvoir modifier la taille des tableaux à volonté (du prof…)),

+ puis les remplit chacun avec des chiffres consécutifs,

+ enfin les fusionne dans un seul nouveau tableau.

```
Premier tableau [4] : 1, 2, 3, 4
Deuxième tableau [3] : 5, 6, 7
Tableau fusionné [7] : 1, 2, 3, 4, 5, 6, 7
```

Déplacer le remplissage et la fusion dans des fonctions.

??? success "Solution"
    
    ![Minute papillon !](../images/meme/waiting-alice.gif)