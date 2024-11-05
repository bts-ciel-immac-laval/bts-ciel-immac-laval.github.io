# Variables statiques

## Cours

<object data="../../pdf/cours/bts1/bts1_2425_05_fonctions_gestion_variables.pdf" type="application/pdf">
    <embed src="../../pdf/cours/bts1/bts1_2425_05_fonctions_gestion_variables.pdf" type="application/pdf" />
</object>

## Exercice 1

Ecrire une fonction qui compte combien de fois elle a été exécutée et renvoie ce nombre. 

Créer un programme de test qui la lance 4096 fois.

??? success "Solution"
    
    ```c
    #include <stdio.h>

    int iCountMyself();

    int main() {
        int count = 0;

        do {
            count = iCountMyself();
            
            // printf("%d\n", count); // <- Pour visualiser les appels 👍
        }
        while (count != 4096);

        printf("Et voila : %d fois !\n", count);

        return 0;
    }

    int iCountMyself() {
        // Déclaration de la variable statique initialisée à 0 lors du premier appel...
        static int count = 0; 
        
        // ... mais qui va garder sa valeur entre 2 appels de la fonction !
        // Seule l'instruction suivante sera exécutée à chaque appel suivant.
        return ++count;
    }
    ```
    
## Exercice 2

Ecrire une fonction qui calcule le temps passé entre 2 exécutions (dans le même programme…).

Créer un programme de test qui l’appelle plusieurs fois de suite en faisant des “pauses” entre 2 appels.

??? success "Solution"
    
    ![Wait for it](../images/meme/waiting-kid.gif)

## Exercice 3

Calculer la somme des saisies successives d’un utilisateur à l’aide d’une fonction utilisant une variable statique.

```
> ./exo3.exe
1
= 1
2
= 3
3
= 6
588
= 594
```

??? danger "Aller plus loin"
    
    Remettre le compteur à 0 si on saisit 0.
    
    Modifier la fonction et le programme de test pour répondre à ce besoin.
    
    ```
    > ./exo3.exe
    1
    = 1
    2
    = 3
    3
    = 6
    0
    = 0
    32
    = 32
    ```

??? success "Solution"
    
    ![Wait for it](../images/meme/waiting-bean.gif)