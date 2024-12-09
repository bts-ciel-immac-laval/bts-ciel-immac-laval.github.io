# Les chaînes de caractères

## Exercice 8

Ecrire un programme exo_8.c qui affiche le deuxième, le quatrième et le septième caractère d'une chaîne saisie au clavier (10 caractères maximum).

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <string.h>

    int main() {
        char input[11] = "";

        printf("Saisir une chaine de 10 caracteres : ");

        while (strlen(input) != 10) {
            gets(input);
        }

        printf("Caracteres  n°2 : %c, n°4 : %c et n°7 : %c\n", input[1], input[3], input[6]);

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

    ![Minute paillon...](../images/meme/waiting-kid.gif) 

## Exercice 10

Ecrire un programme exo_10.c qui affiche le nombre de fois où le caractère 'a' est présent dans la chaîne "It's gonna be legend... wait for it... dary!".

??? success "Solution"

    ![Minute paillon...](../images/meme/waiting-barney.gif)
    

## Exercice 11

Reprendre l'exercice 11 dans un nouveau programme exo_10.c :

1. En rendant le **caractère** et la **chaîne** saisissables par l'utilisateur.

2. En recherchant minuscule et majuscule du caractère saisi pour les 26 lettres non accentuées.

??? success "Solution"

    ![Minute paillon...](../images/meme/oups-kristen.gif)