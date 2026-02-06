## Exercice 3 - File

De manière à ce que le programme gérant une **file** ci-après affiche :

```
> ./file.exe
File (1/7) :   1 → [     ][     ][     ][     ][     ][     ][   1 ]
File (2/7) :   2 → [     ][     ][     ][     ][     ][   2 ][   1 ]
File (3/7) :   3 → [     ][     ][     ][     ][   3 ][   2 ][   1 ]
File (4/7) :   4 → [     ][     ][     ][   4 ][   3 ][   2 ][   1 ]
File (5/7) :   5 → [     ][     ][   5 ][   4 ][   3 ][   2 ][   1 ]
File (6/7) :   6 → [     ][   6 ][   5 ][   4 ][   3 ][   2 ][   1 ]
File (7/7) :   7 → [   7 ][   6 ][   5 ][   4 ][   3 ][   2 ][   1 ]
File (6/7) :       [     ][   7 ][   6 ][   5 ][   4 ][   3 ][   2 ] → 1
File (5/7) :       [     ][     ][   7 ][   6 ][   5 ][   4 ][   3 ] → 2
File (4/7) :       [     ][     ][     ][   7 ][   6 ][   5 ][   4 ] → 3
File (3/7) :       [     ][     ][     ][     ][   7 ][   6 ][   5 ] → 4
File (4/7) :  42 → [     ][     ][     ][  42 ][   7 ][   6 ][   5 ]
File (5/7) :  13 → [     ][     ][  13 ][  42 ][   7 ][   6 ][   5 ]
File (4/7) :       [     ][     ][     ][  13 ][  42 ][   7 ][   6 ] → 5
File (3/7) :       [     ][     ][     ][     ][  13 ][  42 ][   7 ] → 6
File (2/7) :       [     ][     ][     ][     ][     ][  13 ][  42 ] → 7
File (1/7) :       [     ][     ][     ][     ][     ][     ][  13 ] → 42
File (0/7) :       [     ][     ][     ][     ][     ][     ][     ] → 13
File (1/7) : 123 → [     ][     ][     ][     ][     ][     ][ 123 ]
File (2/7) :  45 → [     ][     ][     ][     ][     ][  45 ][ 123 ]
```

Compléter les fonctions suivantes :

+ `queueCreate`

+ `queueIsEmpty`

+ `queueIsFull`

+ `queueEnqueue`

+ `queueDequeue`

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element * next;
    struct Element * prev;
} Element;

typedef struct Queue {
    int length;
    int maxLength;
    struct Element * first;
    struct Element * last;
} Queue;

Queue * queueCreate(int);
bool queueIsEmpty(Queue *);
bool queueIsFull(Queue *);
bool queueEnqueue(Queue *, int);
bool queueDequeue(Queue *, int *);
void queueDisplayInput(Queue *, int);
void queueDisplayOutput(Queue *, int);

int main() {
    Queue * s = queueCreate(7);
    int value;
    
    system("chcp 65001");
    system("cls");

    for (int i = 1; !queueIsFull(s); i++) {
        queueEnqueue(s, i);
        queueDisplayInput(s, i);
    }

    for (int i = 1; i < 5; i++) {
        queueDequeue(s, &value);
        queueDisplayOutput(s, value);
    }

    queueEnqueue(s, 42);
    queueDisplayInput(s, 42);
    queueEnqueue(s, 13);
    queueDisplayInput(s, 13);

    while (!queueIsEmpty(s)) {
        queueDequeue(s, &value);
        queueDisplayOutput(s, value);
    }

    queueEnqueue(s, 123);
    queueDisplayInput(s, 123);
    queueEnqueue(s, 45);
    queueDisplayInput(s, 45);

    return 0;
}

/**
 * @brief Crée une nouvelle file dans le tas.
 * 
 * @param maxLength Le nombre maximal d'éléments dans la file.
 * @return Stack* - La file créée.
 */
Queue * queueCreate(int maxLength) {

    return NULL;
}

/**
 * @brief Permet de savoir si la file est vide.
 * 
 * @param s (Stack *) La file à étudier.
 * @return true - La file est vide.
 * @return false - La file n'est pas vide ! (OO')
 */
bool queueIsEmpty(Queue * s) {

    return false;
}

/**
 * @brief Permet de savoir si la file est... pleine !
 * 
 * @param s (Stack *) La file à étudier.
 * @return true - La file est pleine.
 * @return false - La file n'est pas pleine ! Mais non ?!! Mais si !
 */
bool queueIsFull(Queue * s) {
    
    return false;
}

/**
 * @brief Enfile un nouvel élément dans la file.
 * 
 * @param s (Queue *) La file sur laquelle on travaille.
 * @param value (int) La valeur de l'élément à enfiler.
 * @return true - L'enfilement a réussi.
 * @return false - Il n'y a plus de place !!!
 */
bool queueEnqueue(Queue * s, int value) {
    
    return false;
}

/**
 * @brief Défile un élément de la file.
 * 
 * @param s (Queue *) La file sur laquelle on travaille.
 * @param value (int *, sortie) La valeur de l'élément défilé
 * @return true - Le défilement s'est bien déroulé.
 * @return false - La file était vide... 
 */
bool queueDequeue(Queue * s, int * value) {
    
    return false;
}

/**
 * @brief Affiche la file suite à un enfilement.
 * 
 * @param s (Queue *) La file à afficher.
 * @param input (int) La valeur de l'élément enfilé.
 */
void queueDisplayInput(Queue * s, int input) {
    printf("File (%d/%d) : %3d → ", s->length, s->maxLength, input);
    for (int i = 0; i < s->maxLength - s->length; i++) {
        printf("[     ]");
    }
    for (Element * e = s->first; e != NULL; e = e->next) {
        printf("[ %3d ]", e->value);
    }
    printf("\n");
}

/**
 * @brief Affiche la file suite à un défilement.
 * 
 * @param s (Queue *) La file à afficher.
 * @param output (int) La valeur de l'élément défilé.
 */
void queueDisplayOutput(Queue * s, int output) {
    printf("File (%d/%d) :       ", s->length, s->maxLength);
    for (int i = 0; i < s->maxLength - s->length; i++) {
        printf("[     ]");
    }
    for (Element * e = s->first; e != NULL; e = e->next) {
        printf("[ %3d ]", e->value);
    }
    printf(" → %d\n", output);
}
```