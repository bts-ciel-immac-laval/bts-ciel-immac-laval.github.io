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
        char c = 'a';
        uppercase(&c);
        printf("%c", c); // A
        return 0;
    }

    void uppercase(char * p) {
        // Vérifier que p est une lettre minuscule
        if (*p >= 'a' && *p <= 'z') {
            // Passer la lettre en majuscule
            *p = *p - 32;
        }
    }
    ```

## Exercice 3

Créer une fonction qui joue au bonneteau avec 3 variables qui lui sont fournies.

Proposer à l’utilisateur de retrouver quelle variable contient une valeur.

??? success "Solution"

    Version qui suffit amplement :

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void bonneteau(int *, int *, int *);

    int main() {
        int a = 0, b = 0, c = 0;
        char variable;
        
        // Initialisation de la génération aléatoire
        srand(time(NULL));

        // Dissimulation d'une valeur dans une des trois variables
        // On donne les adresses de a, b et c comme ça la fonction 
        // va pouvoir directement écrire dedans.
        bonneteau(&a, &b, &c);
        
        // Question à l'utilisateur
        printf("Dans quelle variable se cache la valeur [a, b ou c] ?\n");
        while (variable != 'a' && variable != 'b' && variable != 'c') {
            printf("> ");
            variable = getchar();
            getchar(); // Pour consommer le \n qui traine dans le tampon...
        }

        // Réponse
        printf("a: %d | b: %d | c: %d", a, b, c);
        if ((variable == 'a' && a == 1) || (variable == 'b' && b == 1) || (variable == 'c' && c == 1)) {
            printf("Bravo !!!\n");
        }
        else {
            printf("Perdu !!!\n");
        }
        
        return 0;
    }

    void bonneteau(int * x, int * y, int * z) {
        // Génération d'un nombre aléatoire 
        // puis on récupère le reste de la division par 3
        // ce qui donne un chiffre entre 0 et 2
        switch(rand() % 3) {
            // Si c'est 0 on met 1 dans la première variable
            case 0 :
                *x = 1;
                break;
            // Si c'est 1 on met 1 dans la deuxième variable
            case 1 :
                *y = 1;
                break;
            // Si c'est 2 on met 1 dans la troisième variable
            case 2 :
                *z = 1;
                break;
        }
    }
    ```

    Version de crâneur 😏 :

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

## Exercice 4

Créer une fonction qui demande à l'utilisateur de saisir 10 valeurs puis renvoie la plus petite ET la plus grande des valeurs saisies

??? info "Pour démarrer si je suis perdu"

    ```c
    #include <stdio.h>

    // Déclarer la fonction de saisie
    // Elle doit renvoyer deux valeurs ce qui n'est pas possible avec un return...
    ...

    int main() {

        int max, min;

        // Faire appel à la fonction
        ...

        // Affichage des valeurs minimale et maximale
        printf("Min : %d / Max : %d", min, max);

        return 0;
    }

    // Définir la fonction de saisie
    ... {
        // Pour bien démarrer un algo de recherche de minimum ou de maximum,
        // il faut initialiser la valeur minimum ou maximum avec la première
        // valeur de la liste

        // Ensuite on demande à l'utilisateur de saisir les valeurs une par une...

            // et on les compare à la valeur minimum ou maximum...

            // si la valeur saisie est plus petite que la valeur minimum
            // alors elle devient la nouvelle valeur minimum

            // si la valeur saisie est plus grande que la valeur maximum
            // alors elle devient la nouvelle valeur maximum
    }
    ```

??? success "Solution"

    ![waitforit](../images/meme/waiting-alice.gif)