# Listes chaînées

![chaines](../images/illustration/chaines.jpg)

## Exercice

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

    + `nodeShift` pour retirer le premier noeud d'une liste chaînée.

    + `nodeInsert` pour insérer un noeud à l'indice n d'une liste chaînée.

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
