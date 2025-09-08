# Projet Thelma

Développons un programme pour aider une écolière de CE1 à réviser ses tables !

## Thèmes abordés

![Thelma](../images/cours/bts-1/10/thelma.png){ align=right }

+   variables, 
+   conditions, 
+   boucles, 
+   I/O, 
+   fichiers, 
+   aléatoire, 
+   fonctions, 
+   chrono

## Avancement

Programme par défaut en C :

```c
#include <stdio.h>              // La bibliothèque qui permet d'utiliser printf.

int main() {                    // La fonction principale, le point d'entrée du programme.
    printf("hello, world!");    // Affiche "hello, world!" dans la sortie standard.
    return 0;                   // R.A.S., on signale à l'OS que tout s'est bien passé.
}
```

1. Afficher un calcul et son résultat

    1. En “dur”

    ```c
    printf("1 + 1 = 2");  
    printf("1 + 1 = 42");  
    ```

    2. En calculant vraiment
    ```c
    printf("%d + %d = %d\n", 1, 1, 1 + 1);
    ```


2. Afficher une table

    1. Avec 10 printf

    ```c
    printf("%d + %d = %d\n", 1, 0, 1 + 0);
    printf("%d + %d = %d\n", 1, 1, 1 + 1);
    printf("%d + %d = %d\n", 1, 2, 1 + 2);
    printf("%d + %d = %d\n", 1, 3, 1 + 3);
    printf("%d + %d = %d\n", 1, 4, 1 + 4);
    printf("%d + %d = %d\n", 1, 5, 1 + 5);
    printf("%d + %d = %d\n", 1, 6, 1 + 6);
    printf("%d + %d = %d\n", 1, 7, 1 + 7);
    printf("%d + %d = %d\n", 1, 8, 1 + 8);
    printf("%d + %d = %d\n", 1, 9, 1 + 9);
    ```

    2. Avec une boucle

    ```c
    // Avec une boucle while (tant que)
    int n2 = 0;    
    while (n2 < 10) {
        printf("1 + %d = %2d\n", n2, 1 + n2);
        n2 = n2 + 1;
    }

    // Avec une boucle for (pour)
    for (n2 = 0; n2 < 10; n2 = n2 + 1) {
        printf("1 + %d = %2d\n", n2, 1 + n2);
    }
    ```

    3. Laisser le choix à l'utilisateur
    ```c
    ```

3. Afficher toutes les tables

    1. Pour un opérateur en "dur"

    ```c
    int n1 = 1, n2 = 0;

    // Boucles imbriquées
    // La première permet de passer de table en table
    while (n1 < 10) {
        printf("Table de %d\n----------\n", n1);
        
        // La seconde (déjà vue) affiche chaque table
        while (n2 < 10) {
            printf("%d + %d = %2d\n", n1, n2, n1 + n2);
            n2 = n2 + 1;
        }

        n1 = n1 + 1;
        n2 = 0;
        printf("\n");
    }
    ```

    2. Pour un opérateur au choix 

    ```c
    
    ```
    
4. Poser une question à l’utilisateur

    ```c
    
    ```
    
5. Poser une suite de questions à l’utilisateur

    1. Compter les points (réponses fausses acceptées)

    ```c
    
    ```
    
    2. Ne pas passer à la suivante tant que la réponse est fausse

    ```c
    
    ```
    
6. Créer un quiz aléatoire sur une table

    1. 2 x 4 = ?

    ```c
    
    ```
    
    2. 2 + ? = 5

    ```c
    
    ```
    
7. Créer un quiz aléatoire en laissant le choix à l’utilisateur des opérateurs et des tables

    ```c
    
    ```
    
8. Créer un quiz chronométré

    ```c
    
    ```
    
9. Créer un quiz minuté ?

    ```c
    
    ```
    
10. Créer un quiz qui donne les réponses juste après chaque question ou à la fin de toutes les questions 

    ```c
    
    ```
    
11. Créer un top
    1. En mémoire

    ```c
    
    ```
    
    2. Sauvegardé

    ```c
    
    ```
    
12. Créer un menu

    ```c
    
    ```
    
13. Tester
    
14. Livrer