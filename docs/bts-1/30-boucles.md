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

    ```c
    #include <stdio.h>

    int main() {

        // Méthode 1 : on compte de 2 en 2
        printf("Methode 1 :\n");
        for (int i = 2; i <= 100; i = i + 2) {
            printf("%3d ", i);
        }

        // Méthode 2 : on compte de 1 en 1 mais on n'affiche que les nombres pairs
        printf("\n\nMethode 2 :\n");
        for (int i = 2; i <= 100; i++) {
            if (i % 2 == 0) {
                printf("%3d ", i);
            }
        }

        return 0;
    }
    ```

## Exercice 3

Ecrire un programme qui demande un nombre positif à l'utilisateur puis affiche le décompte à partir de ce nombre jusqu'à 0 avec les trois types de boucles.

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {

        int start, i;

        // Saisie
        do {
            printf("Saisir un nombre strictement positif : ");
            scanf("%d", &start);
        }
        while (start <= 0);

        // Décompte avec un for
        for (int i = start; i >= 0; i--) {
            printf("%d\n", i);
        }
        
        // Décompte avec un while
        i = start;
        while(i >= 0) {
            printf("%d\n", i);
            i--;
        }

        // Décompte avec un do...while
        i = start;
        do {
            printf("%d\n", i);
            i--;
        }
        while(i >= 0);

        return 0;
    }
    ```


## Exercice en attendant...

Ecrire un programme en C qui affiche les nombres de 1 à 100 (inclus) sauf : 

+   si le nombre est un multiple de 3, il affiche "fi",

+   si le nombre est un multiple de 5, il affiche "foo",

+   si le nombre est un multiple de 3 et de 5, il affiche "fifoo".  

Résultat : 
```
> ./exo4.exe
1
2
fi
4
foo
5
fi
7
8
fi
10
11
fi
13
14
fifoo
16
...
```

## Exercice 4

Ecrire un programme pour gérer la saisie du code à 4 chiffres d'une carte bancaire.

L'utilisateur a 3 essais pour saisir correctement son code.

Si le code est trouvé, afficher "`Code bon`".

Si le code est faux, afficher "`Code faux (X essai(s) restant(s))`" où X est le nombre d'essais restants.

Au sortir de la saisie, si le code est bon, afficher "`Paiement en cours...`", sinon afficher "`Carte bloquée X(`" 

??? success "Correction"

    ```c
    #include <stdio.h>

    #define CODE_A_TROUVER 1234

    int main() {

        int code_utilisateur = -1, tentatives = 0;

        do {
            printf("Votre code : ");
            scanf("%d", &code_utilisateur);
            tentatives++;
            if (code_utilisateur == CODE_A_TROUVER) {
                printf("Code bon\n");
            }
            else {
                printf("Code faux (%d essai(s) restant(s))\n", 3 - tentatives);
            }
        } while (code_utilisateur != CODE_A_TROUVER && tentatives < 3);

        if (code_utilisateur == CODE_A_TROUVER) {
            printf("Paiement en cours...");
        }
        else {
            printf("Carte bloquée X(");
        }

        return 0;
    }
    ```

??? danger "Aller plus loin"

    Pénaliser les erreurs de saisie, en bloquant le programme pendant 5 puis 10 secondes en cas d'erreur.

??? success "Correction"

    ```c
    #include <stdio.h>

    #ifdef _WIN32
    #include <windows.h>
    #endif

    #ifdef linux
    #include <unistd.h>
    #endif

    #define CODE_A_TROUVER 1234

    int main() {

        int code_utilisateur = -1, tentatives = 0, attente = 5;

        do {
            printf("Votre code : ");
            scanf("%d", &code_utilisateur);
            tentatives++;
            if (code_utilisateur == CODE_A_TROUVER) {
                printf("Code bon\n");
            }
            else {
                printf("Code faux (%d essai(s) restant(s))\n", 3 - tentatives);
                
                #ifdef _WIN32
                Sleep(attente * 1000);
                #endif

                #ifdef linux
                usleep(attente * 1000000);
                #endif

                attente += 5;
            }
        } while (code_utilisateur != CODE_A_TROUVER && tentatives < 3);

        if (code_utilisateur == CODE_A_TROUVER) {
            printf("Paiement en cours...");
        }
        else {
            printf("Carte bloquée X(");
        }

        return 0;
    }
    ```

## Exercice 5

Créer un programme `exo5.c` qui demande à l’utilisateur de deviner un nombre entre un 1 et 10 en maximum 3 essais.

```
> ./exo5.exe
Devine un nombre entre 1 et 10 (3 essais max.) !
Essai 1 : 3
Perdu !
Essai 2 : 6
Perdu !
Essai 3 : 7
Perdu ! C'était 8 !

> ./exo5.exe
Devine un nombre entre 1 et 10 (3 essais max.) !
Essai 1 : 4
Perdu !
Essai 2 : 6
Gagné !!!
```

??? success "Correction"

    ![](../images/meme/waiting-moone.gif)

## Exercice 6

Reprendre l’exercice 5 en rendant les bornes (1 - 10) et le nombre de tentatives paramétrables via des constantes.

```
> ./exo6.exe
Devine un nombre entre 1 et 99 (1 essai max.) !
Essai 1 : 3
Perdu ! C'était 83 !

> ./exo6.exe
Devine un nombre entre 34 et 77 (24 essais max.) !
Essai 1 : 44
Perdu !
Essai 2 : 61
Perdu !
Essai 3 : 62
Perdu !
Essai 4 : 63
Perdu !
Essai 5 : 67
Perdu !
Essai 6 : 56
Perdu !
Essai 7 : 51
Perdu !
Essai 8 : 73
Perdu !
Essai 9 : 71
Perdu !
Essai 10 : 36
Gagné !!!
```

??? success "Correction"

    ![](../images/meme/waiting-zootopia.gif)

## Bonus

Dessiner un sapin de Noël formé d'étoiles :

```
> ./sapin.exe
Nombre d'étages : 5

    *
   ***
  *****
 *******
*********
    *
```

Le nombre d'étages est donné par l'utilisateur.

??? success "Correction"

    ![](../images/meme/waiting-sonic.gif)