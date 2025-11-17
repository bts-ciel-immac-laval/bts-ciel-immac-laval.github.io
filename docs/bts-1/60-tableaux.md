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
    
    ```c
    #include <stdio.h>

    int main() {

        int tab [52];

        // 3 méthodes de remplissage différentes possibles (parmi d'autres)
        
        // Méthode 1 (la plus simple, mais on n'y pense pas forcément du 1er coup)
        for (int i = 0; i < 52; i++) {
            tab[i] = i * 5;
        }

        // Méthode 2
        for (int i = 0, n = 0; i < 52; i++, n += 5) {
            tab[i] = n;
        }

        // Méthode 3
        for (int n = 0, * p = tab; n < 256; n += 5, p++) {
            *p = n;
        }

        // Affichage à l'envers
        for (int i = 51; i >= 0; i--) {
            printf("%d", tab[i]);
        }

        return 0;
    }
    ```

## Exercice 4

Dans un programme `exo_4.c` :

1. Initialiser un tableau avec le nombre de jours de chaque mois (31 jours en janvier, 28 en février...).

2. En se servant de ce tableau, écrire un programme qui affiche le numéro du jour dans l'année d'une date saisie (format `JJ/MM`) sans tenir compte des années bissextiles 😅

```
Saisir une date : 07/09
C'est le 250ème jour de l'année !
```

??? question "Avez-vous pensé à tout ?"
    
    +   Avez-vous pensé à l'affichage du premier jour de l'année ?

    +   Est-ce que votre programme accepte la date 30/02 ou 32/13 ?

??? success "Solution"
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {

        system("chcp 65001");
        system("cls");
        
        int nbJoursParMois[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
            nbJours = 0, jour = 0, mois = 0;

        // Saisie
        do {
            printf("Saisir une date (JJ/MM) : ");
            scanf("%2d/%2d", &jour, &mois);
        }
        while (mois < 1 || mois > 12 || jour < 1 || jour > nbJoursParMois[mois - 1]);

        // Comptage
        for (int i = 0; i < mois - 1; i++) {
            nbJours += nbJoursParMois[i];
        }
        nbJours += jour;

        // Affichage
        printf("C'est le %d%s jour de l'année !", nbJours, nbJours == 1 ? "er" : "ème");

        return 0;
    }
    ```

## Exercice 5

Reprendre le code de l'exercice 4 dans un programme `exo_5.c`, permettre la saisie de date au format `JJ/MM/AAAA` **ET** gérer le cas des années bissextiles !

```
Saisir une date : 07/09/2024
C'était le 251ème jour de l'année 2024 !
```

??? success "Solution"
    
    ![WaitForIt](../images/meme/waiting-britney.gif)

## Exercice 6

Créer un programme `exo_6.c` contenant :

+   une fonction `remplirTableau` qui peut remplir n'importe quel tableau d'entiers avec des entiers consécutives à partir d'une valeur passée en paramètre.

+   une fonction `afficherTableau` qui peut afficher n'importe quel tableau d'entiers de la manière suivante : [taille] : valeur1, valeur2...

+   une fonction `fusionnerTableau` qui peut fusionner deux tableaux d'entiers l'un à la suite de l'autre dans un troisième tableau.

+   une fonction principale qui :

    +   crée deux tableaux de tailles différentes (utiliser des constantes pour pouvoir modifier la taille des tableaux à volonté (du prof… 😈)),

    +   puis les remplit chacun avec des chiffres consécutifs,

    +   les affiche

    +   enfin les fusionne dans un seul nouveau tableau
    
    +   avant de l'afficher.

Exemple d'exécution :

```
Premier tableau [4] : 1, 2, 3, 4
Deuxième tableau [3] : 5, 6, 7
Tableau fusionné [7] : 1, 2, 3, 4, 5, 6, 7
```

??? success "Solution"

    ![WaitForIt](../images/meme/rickroll-roll.gif)