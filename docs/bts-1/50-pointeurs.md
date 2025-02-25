# 04 - Pointeurs

## Cours 

![Pointeurs](../pdf/cours/bts1/bts1_08_pointeurs.pdf)

## Exercice 1

Créer une fonction qui permet d’intervertir les valeurs de deux variables qui lui sont fournies en paramètres.

??? success "Solution"

    ```c
    #include <stdio.h>

    void swap(int *, int *);

    int main() {
        int a = 15, b = 42;

        printf("1 > a : %d | b : %d\n", a, b);
        swap(&a, &b);
        printf("4 > a : %d | b : %d\n", a, b);

        return 0;
    }

    void swap(int * x, int * y) {
        printf("2 > a : %d | b : %d\n", *x, *y);
        int z = *x;
        *x = *y;
        *y = z;
        printf("3 > a : %d | b : %d\n", *x, *y);
    }
    ```

## Le passage d'arguments à une fonction

![Passage par adresses](../pdf/cours/bts1/bts1_05_passages.pdf)

## Exercice 2

Créer une fonction qui permet de mettre en majuscule une variable de type `char` passée en paramètre si sa valeur est une lettre de l’alphabet.

??? success "Solution"

    ```c
    #include <stdio.h>

    void uppercase(char *);

    int main() {
        char c = 'a', d = 'k', e= ';';

        printf("c : %c | d : %c | e : %c\n", c, d, e);
        
        uppercase(&c);
        uppercase(&d);
        uppercase(&e);

        printf("c : %c | d : %c | e : %c\n", c, d, e);

        return 0;
    }

    void uppercase(char * p) {
        if (*p >= 97 && *p <= 122) {
            *p -= 32;
        }
    }
    ```

## Exercice 3

Créer une fonction qui joue au bonneteau avec 3 variables qui lui sont fournies.

Proposer à l’utilisateur de retrouver quelle variable contient une valeur.

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    char melange(char *, char *, char *);

    int main() {
        // Passage de la console en utf-8
        system("chcp 65001");
        // Nettoyage de la console
        system("cls");

        // Initialisation de l'aléa
        srand(time(NULL));

        char pot1 = ' ', pot2 = ' ', pot3 = ' ', tour, pot, choix;

        // Présentation
        printf("\nᕙ(`▽´)ᕗ\n\n");
        printf("Approchez, approchez, mesdames et messieurs !\n");
        printf("Voici trois gobelets vides...\n");
        printf(" _   _   _\n/ \\ / \\ / \\ \n\n");

        // Départ
        system("pause");
        system("cls");
        printf("\n(ಠ_ಠ)\n\n\n");
        printf("Je place une balle sous le gobelet n°%hhd\n", melange(&pot1, &pot2, &pot3));
        printf(" _   _   _\n/%c\\ /%c\\ /%c\\ \n\n", pot1, pot2, pot3);
        system("pause");

        // Mélange 1
        system("cls");
        printf("\n(ಠ_ಠ)\n\nSuivez mes mains... si vous le pouvez !\n");
        tour = rand() % 5 + 5;
        for (int i = 0; i < tour; i++) {
            printf("Je mélange...\n");
            melange(&pot1, &pot2, &pot3);
        }
        printf("La balle est maintenant ici :\n");
        printf(" _   _   _\n/%c\\ /%c\\ /%c\\ \n\n", pot1, pot2, pot3);
        system("pause");

        // Mélange 2
        system("cls");
        printf("\n(⇀‸↼‶)\n\nAttention maintenant, ça va très vite !\n");
        tour = rand() % 5 + 5;
        for (int i = 0; i < tour; i++) {
            printf("Je mélange...\n");
            pot = melange(&pot1, &pot2, &pot3);
        }
        printf("\n");
        system("pause");

        // Au joueur !
        system("cls");
        printf("\n(◉‿◉)\n\nOù est la balle ?\nSous le pot 1, 2 ou 3 ???\n");
        printf(" _   _   _\n/ \\ / \\ / \\ \n\nNuméro du pot : ");
        scanf("%hhd", &choix);
        
        system("cls");
        if (choix == pot) {
            printf("\n(╥﹏╥)\n\nNoooooooooooooon!\nComment as-tu fait ? Tu as triché !\n");
            printf(" _   _   _\n/%c\\ /%c\\ /%c\\ \n\n", pot1, pot2, pot3);
        }
        else {
            printf("\n¯\\_( ͡° ͜ʖ ͡°)_/¯\n\n\nDommage !\n");
            printf(" _   _   _\n/%c\\ /%c\\ /%c\\ \n\n", pot1, pot2, pot3);
        }

        return 0;
    }

    char melange(char * a, char * b, char * c) {
        char hasard = rand() % 3 + 1;
        *a = ' ';
        *b = ' ';
        *c = ' ';
        switch(hasard) {
            case 1 : 
                *a = 'o';
                break;
            case 2 : 
                *b = 'o';
                break;
            case 3 : 
                *c = 'o';
                break;
        }
        return hasard;
    }
    ```