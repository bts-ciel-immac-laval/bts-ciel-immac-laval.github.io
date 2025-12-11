# Variables statiques

## Cours

![Gestions des variables](../pdf/cours/bts1/bts1_2425_05_fonctions_gestion_variables.pdf)

## Exercice 1

Ecrire une fonction qui compte combien de fois elle a été exécutée et renvoie ce nombre. 

Créer un programme de test qui la lance 4096 fois.

??? success "Solution"
    
    ![waitForIt](../images/meme/waiting-britney.gif)
    
## Exercice 2

Ecrire une fonction qui calcule le temps écoulé depuis sa dernière exécution (dans le même programme 😅).

Créer un programme de test qui l’appelle plusieurs fois de suite en faisant des "pauses" entre 2 appels.

??? success "Solution"
    
    ![waitForIt](../images/meme/waiting-zootopia.gif)

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
    
    ![waitForIt](../images/meme/waiting-bean.gif)