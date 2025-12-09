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

    Solution en mode tableau de caractères :

    ```c
    #include <stdio.h>

    int main() {
        char input[] = "It's gonna be legend... wait for it... dary!";
        int count = 0;

        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'a') {
                count++;
            }
        }
        printf("Il y a %d 'a' dans la phrase \"%s\".", count, input);

        return 0;
    }
    ```

    Solution en utilisant les fonctions de string.h :
    
    ```c
    #include <stdio.h>
    #include <string.h>

    int main() {
        char input[] = "It's gonna be legend... wait for it... dary!";
        char * p = input;
        int count = 0;
        
        while(p != NULL && *p != '\0') {
            p = strchr(p, 'a');
            if (p != NULL) {
                count++;
                p++;
            }
        }
        printf("%d", count);

        return 0;
    }
    ```

## Exercice 11

Reprendre l'exercice 10 dans un nouveau programme exo_11.c :

1. En rendant le **caractère** et la **chaîne** saisissables par l'utilisateur.

2. En recherchant minuscule et majuscule du caractère saisi pour les 26 lettres non accentuées.

??? success "Solution"

    ![barney](../images/meme/waiting-kid.gif)

## Exercice 12 - Chiffrage de César

Proposer un programme permettant de chiffrer et déchiffrer un message grâce au [chiffrage de César](https://fr.wikipedia.org/wiki/Chiffrement_par_d%C3%A9calage){target="_blank"}.

```
> cryptage.exe
Message : Salut, comment allez-vous ?
Décalage : 1
Résultat : 1tbmvudpnnfoubmmfawpvt
```

!!! warning "La permutation est cyclique !"

    ex : `'z' + 2 = 'b'` !

```
> decryptage.exe
Message : 1tbmvudpnnfoubmmfawpvt
Résultat : salutcommentallezvous
```
![cesar](../images/cours/bts-1/70/cesar.jpg)

!!! abstract "Avez-vous pensé à tout ?"

    + [ ] Fonction de nettoyage du texte :

        + [ ] Supprime les espaces
        
        + [ ] Supprime les caractères non alphabétiques

        + [ ] Remplace les caractères accentués par leur équivalent non-accentué

        + [ ] Transforme les caractères alphabétiques en minuscules

    + [ ] Fonction de chiffrage :

        + [ ] Permute les caractères de manière cyclique

    + [ ] Fonction de déchiffrage :

        + [ ] Permute les caractères de manière cyclique

    + [ ] Aller plus loin

        + [ ] Offusquer la clé dans le message de manière efficace

        + [ ] On peut passer le message et le décalage via la ligne de commande
        
        + [ ] Proposer un chiffrage par décalage plus robuste à une attaque brute force

## Passer des informations via la ligne de commande

### Cours

![argc_argv](../pdf/cours/bts1/bts1_10_argc-argv.pdf)

### Tester

Le programme ci-dessous permet de lister les arguments sur la ligne de commande :

```c
#include <stdio.h>

int main(int argc, char ** argv) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%d : %s\n", i, argv[i]);
    }
    return 0;
}
```

Tester et vérifier les exemples donnés dans le cours.

En utilisation courante, on teste toujours la variable `argc` (le nombre d'arguments sur la ligne de commande) pour valider qu'il y a bien le minimum d'arguments attendus.

Par exemple, si mon programme a besoin d'au moins une valeur de la ligne de commande, on affiche une erreur et on arrête le programme :

```c
#include <stdio.h>

int main(int argc, char ** argv) {
    
    // Vérification
    if (argc < 2) {
        // Message d'erreur 
        puts("ERREUR : programme.exe valeur_attendue [valeurs optionnelles]");
        // Sortie avec un code d'erreur
        return -1;
    }

    return 0;
}
```