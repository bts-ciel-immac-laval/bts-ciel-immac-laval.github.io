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

    ```c
    
    ```

## Exercice 5

Ecrire un programme pour gérer la saisie du code d'une carte bancaire.

L'utilisateur a 3 essais pour saisir correctement son code.

Si le code est trouvé, afficher "Code bon".

Si le code est faux, afficher "Code faux (X essai(s) restant(s))" où X est le nombre d'essais restants.

Au sortir de la saisie, si le code est bon, afficher "Paiement en cours...", sinon afficher "Carte bloquée X(" 

??? success "Correction"

    ```c
    
    ```