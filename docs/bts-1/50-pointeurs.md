# 04 - Pointeurs

## Cours 

<object class="fullScreenAble" data="../../pdf/cours/bts1/bts1_08_pointeurs.pdf" type="application/pdf"></object>

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

<object class="fullScreenAble" data="../../pdf/cours/bts1/bts1_05_passages.pdf" type="application/pdf"></object>

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
