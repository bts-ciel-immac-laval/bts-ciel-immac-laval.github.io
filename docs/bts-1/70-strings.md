# Les chaînes de caractères

![Chaînes de caractères](../pdf/cours/bts1/bts1_09_tableaux_2.pdf)

## Exercice 8

Ecrire un programme exo_8.c qui affiche le deuxième, le quatrième et le septième caractères d'une chaîne de 10 caractères saisie au clavier.

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <string.h>

    int main() {
        char input[11] = "";

        // Demander la saisie d'une chaine de 10 caractères
        do {
            puts("Saisir une chaine de 10 caracteres :");
            gets(input);
        }
        while(strlen(input) != 10);

        // Afficher les 2ème, 4ème et 7ème caractères
        printf("\n%c %c %c\n", input[1], input[3], input[6]);

        return 0;
    }
    ```

## Exercice 9

Ecrire un programme exo_9.c qui :

1.  d'abord, crée une chaîne de caractères (20 caractères maximum),

2.  puis, y stocke la saisie de l'utilisateur lue caractère par caractère jusqu'à ce que la chaîne soit remplie,

    ??? warning "Oh oh... 😣"

        Des difficultés à lire successivement des caractères ?

        Qu'est-ce qu'on a dit **en cours** sur `scanf` et sa mémoire tampon (buffer) ?

3.  ensuite, affiche la chaîne,

4.  finalement, affiche la chaîne en ordre inverse.

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>
    #include <string.h>

    int main() {
        char input[21] = "", key;
        
        // Saisie avec getch
        for (int i = 0; i < 20; i++) {
            do {
                key = getch();
                printf("%c\n", key);
            }
            while (!(key >= 'A' && key <= 'Z') && !(key >= 'a' && key <= 'z'));
            // Stockage dans la chaine
            input[i] = key;
        }
        input[20] = '\0';

        // Affichage à l'endroit
        printf("%s\n", input);

        // Affichage à l'envers
        for (int i = 19; i >= 0; i--) {
            printf("%c", input[i]);
        }
        printf("\n");

        return 0;
    }
    ```

## Exercice 10

Ecrire un programme exo_10.c qui affiche le nombre de fois où le caractère 'a' est présent dans la chaîne "It's gonna be legend... wait for it... dary!".

??? success "Solution"

    ![barney](../images/meme/waiting-barney.gif)

## Exercice 11

Reprendre l'exercice 10 dans un nouveau programme exo_11.c :

1. En rendant le **caractère** et la **chaîne** saisissables par l'utilisateur.

2. En recherchant minuscule et majuscule du caractère saisi pour les 26 lettres non accentuées.

??? success "Solution"

    ![barney](../images/meme/waiting-kid.gif)