# 03 - Boucles

## Exercice 1

Ecrire un programme qui affiche tous les nombres de 1 à 1000 avec les trois types de boucles.

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int i;

        for (i = 1; i <= 1000; i++) {
            printf("%d\n", i);
        }

        i = 1;
        while (i <= 1000) {
            printf("%d\n", i);
            i = i + 1;
        }
        
        i = 1;
        do {
            printf("%d\n", i);
            i = i + 1;
        }
        while (i <= 1000);

        return 0;

    }
    ```

## Exercice 2

Ecrire un programme qui affiche les nombres pairs de 2 à 100 avec une boucle `for` de deux manières différentes.

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        
        // Solution 1 : + économe en temps processeur -> 50 opérations
        for (int i = 2; i <= 100; i = i + 2) {
            printf("%d\n", i);
        }

        // Solution 2 : - économe en temps processeur -> 150 opérations
        for (int i = 2; i <= 100; i++) {
            if (i % 2 == 0) {
                printf("%d\n", i);
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

        int start;

        printf("Depart : ");
        scanf("%d", &start);

        while (start >= 0) {
            printf("%d\n", start--);
        }

        return 0;
    }
    ```

## Exercice 4

Ecrire un programme en C qui affiche les nombres de 1 à 100 (inclus) sauf : 
•	si le nombre est un multiple de 3, il affiche "fi",
•	si le nombre est un multiple de 5, il affiche "foo",
•	si le nombre est un multiple de 3 et de 5, il affiche "fifoo".

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

??? success "Correction"

    Plusieurs solutions sont possibles, plus ou moins performantes, en voici 2 performantes et élégantes (faciles à lire) :

    ```c
    #include <stdio.h>

    int main() {

        for (int i = 1; i <= 100; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                printf("fifoo\n");
            }
            else if (i % 3 == 0) {
                printf("fi\n");
            }
            else if (i % 5 == 0) {
                printf("foo\n");
            }
            else {
                printf("%d\n", i);
            }
        }

        return 0;
    }
    ```

    ```c
    #include <stdio.h>

    int main() {

        for (int i = 1; i <= 100; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                printf("fifoo\n");
                continue;
            }
            if (i % 3 == 0) {
                printf("fi\n");
                continue;
            }
            if (i % 5 == 0) {
                printf("foo\n");
                continue;
            }
            printf("%d\n", i);
        }

        return 0;
    }
    ```

## Exercice 5

Ecrire un programme pour gérer la saisie du code d'une carte bancaire.

L'utilisateur a 3 essais pour saisir correctement son code.

Si le code est trouvé, afficher "`Code bon`".

Si le code est faux, afficher "`Code faux (X essai(s) restant(s))`" où X est le nombre d'essais restants.

Au sortir de la saisie, si le code est bon, afficher "`Paiement en cours...`", sinon afficher "`Carte bloquée X(`" 

??? success "Correction"

    ```c
    
    ```

## Exercice 6

Créer un programme `exo6.c` qui demande à l’utilisateur de deviner un nombre entre un 1 et 10 en maximum 3 essais.

```
> ./exo6.exe
Devine un nombre entre 1 et 10 (3 essais max.) !
Essai 1 : 3
Perdu !
Essai 2 : 6
Perdu !
Essai 3 : 7
Perdu ! C'était 8 !

> ./exo6.exe
Devine un nombre entre 1 et 10 (3 essais max.) !
Essai 1 : 4
Perdu !
Essai 2 : 6
Gagné !!!
```

??? success "Correction"

    ```c
    
    ```

## Exercice 7

Reprendre l’exercice 6 en rendant les bornes (1 - 10) et le nombre de tentatives paramétrables via des constantes.

```
> ./exo7.exe
Devine un nombre entre 1 et 99 (1 essai max.) !
Essai 1 : 3
Perdu ! C'était 83 !

> ./exo7.exe
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

    ```c
    
    ```

## Exercice 8

Compléter le programme `exo8.c` pour afficher les nombres de `000` à `999` en untilisant une variable pour gérer les unités, une pour les dizaines et une pour les centaines.

```c
#include <stdio.h>

int main() {

    int u, d, c;

    printf("%d%d%d\n", c, d, u);

    return 0;
}
```

??? danger "Aller plus loin"

    Faire en sorte que le programme mette 10 secondes à afficher les nombres.

??? success "Correction"

    ```c
    
    ```
