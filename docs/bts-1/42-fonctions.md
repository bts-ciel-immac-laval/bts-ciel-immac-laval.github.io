# Récursivité

## Cours

<object class="fullScreenAble" data="../../pdf/cours/bts1/bts1_2425_05_fonctions_recursivite.pdf" type="application/pdf"></object>

## Exercice 1

Voici une fonction en C :

```c
void f(int n) {
    if (n == 0) {
        printf("Partez !");
    }
    else {
        printf("%d\n", n);
        f(n - 1);
    }   
}
```

1) Qu'affiche l'instruction `f(5)` ?

2) Pourquoi dit-on de cette fonction qu'elle est récursive ?

??? success "Solution"
    
    ![Wait for it](../images/meme/waiting-alice.gif)

## Exercice 2

Ecrire une fonction récursive qui affiche les saisies de l’utilisateur en partant de sa dernière saisie jusqu’à la première.

```
> ./exo2.exe
Saisir des chiffres (0 pour arrêter) :
1
2
3
4
5
6
0

OK ! Voici vos saisies en partant de la fin :
6
5
4
3
2
1
```

??? success "Solution"
    
    ![Wait for it](../images/meme/waiting-sonic.gif)
    

## Exercice 3

Ecrire une fonction récursive qui affiche les saisies de l’utilisateur en partant de sa dernière saisie jusqu’à la première en limitant le nombre de saisies à 5.

```
> ./exo.exe
Saisir 5 chiffres
12
298
34
470
5

Et les voici en ordre inverse :
5
470
34
298
12
```

??? success "Solution"
    
    ![Wait for it](../images/meme/waiting-britney.gif)