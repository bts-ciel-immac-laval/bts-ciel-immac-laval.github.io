# Listes chaînées

![chaines](../images/illustration/chaines.jpg)

## Exercice 1

Créer dans l'ordre les fonctions suivantes :

1. Première étape

    + `nodeCreate` pour créer un noeud en lui affectant une valeur.

    + `nodeDisplay` pour afficher un noeud.

    + `nodesFree` pour libérer une liste chaînée.

2. Deuxième étape

    + `nodePush` pour ajouter un noeud à la fin d'une liste chaînée.

    + `nodesCount` pour compter le nombre de noeuds d'une liste chaînée.

    + `nodeAt` pour récupérer le noeud d'indice n dans une liste chaînée.

3. Troisième étape

    + `nodeDelete` pour supprimer le noeud d'indice n dans une liste chaînée.

    + `nodesDisplay` pour afficher les valeurs d'une liste chaînée.

4. Quatrième étape

    + `nodeShift` pour ajouter un noeud à la première place d'une liste chaînée.

    + `nodeInsert` pour insérer un noeud à l'indice n d'une liste chaînée (mais pas la première 😅).

afin que le programme suivant :

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

int main() {
    Node * n1 = nodeCreate(8);
    nodeDisplay(n1);

    nodePush(n1, 15);
    nodePush(n1, 22);
    nodePush(n1, 23);
    nodePush(n1, 42);

    printf("\nTaille : %d\n", nodesCount(n1));

    nodeDisplay(nodeAt(n1, 1));
    nodeDisplay(nodeAt(n1, 5));

    n1 = nodeDelete(n1, 2);
    nodesDisplay(n1);

    n1 = nodeShift(n1, 4);
    nodesDisplay(n1);

    nodeInsert(n1, 3, 16);
    nodesDisplay(n1);

    nodesFree(n1);

    return 0;
}

```

affiche le résultat suivant :

```
> ./a.exe
8

Taille : 5
15
NULL

Taille : 4
 0: 8
 1: 15
 2: 23
 3: 42

Taille : 5
 0: 4
 1: 8
 2: 15
 3: 23
 4: 42

Taille : 6
 0: 4
 1: 8
 2: 15
 3: 16
 4: 23
 5: 42

```

??? success "Solution intermédiaire - 1^ère^, 2^ème^ et 3^ème^ étapes"

    ```c
    Node * nodeCreate(int value) {
        Node * newNode = (Node *) malloc(sizeof(Node));
        if (newNode == NULL) {
            puts("Erreur d'allocation !");
            exit(-1);
        }
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }

    void nodeDisplay(Node * n) {
        if (n != NULL) {
            printf("%d\n", n->value);
        }
        else {
            printf("NULL\n");
        }
    }

    void nodesFree(Node * n) {
        Node * temp;
        while (n != NULL) {
            temp = n->next;
            free(n);
            n = temp;
        }
    }

    void nodePush(Node * n, int value) {
        Node * newNode = nodeCreate(value);
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = newNode;
    }

    int nodesCount(Node *n) {
        int count = 0;
        while (n != NULL) {
            count++;
            n = n->next;
        }
        return count;
    }

    Node * nodeAt(Node * n, int i) {
        for (int j = 0; j < i; j++) {
            n = n->next;
        }
        return i < 0 ? NULL : n;
    }

    Node * nodeDelete(Node * n, int i) {
        Node * temp, * next;

        if (i == 0 && n != NULL) {
            temp = n->next;
            free(n);
            return temp;
        }
        
        temp = nodeAt(n, i - 1);
        if (temp != NULL && temp->next != NULL) {
            next = temp->next;
            temp->next = next->next;
            free(next);
        }
        return n;
    }

    void nodesDisplay(Node *n) {
        printf("\nTaille : %d\n", nodesCount(n));
        for (int i = 0; n != NULL; i++, n = n->next) {
            printf("%2d: %2d\n", i, n->value);
        }
    }
    ```
