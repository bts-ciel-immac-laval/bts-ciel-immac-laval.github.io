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

Ecrire une fonction récursive qui demande à l'utilisateur de saisir des chiffres tant qu'il ne saisit pas un zéro, puis lui affiche les chiffres saisis du dernier au premier.

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
    
    ```c
    #include <stdio.h>

    void f();

    int main() {
        printf("Saisir des chiffres (0 pour arreter) :\n");
        f();
        return 0;
    }

    void f() {
        int saisie;
        
        // Saisie
        scanf("%d", &saisie);

        // si saisie == 0 -> STOP
        if (saisie == 0) {
            printf("\nOK ! Voici vos saisies en partant de la fin :\n");
        }
        // sinon on rappelle f puis on affiche 
        else {
            f();
            printf("%d\n", saisie);
        }
    }
    ```
    

## Exercice 3

Réécrire la fonction récursive de l'exercice 2 en limitant le nombre de saisies à 5.

```
> ./exo.exe
Saisir 5 chiffres :
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
    
    ```c
    #include <stdio.h>

    void f(int);

    int main() {
        printf("Saisir 5 chiffres :\n");
        f(5);
        return 0;
    }

    void f(int i) {
        int saisie;
        
        // Si i == 0 -> STOP !
        if (i == 0) {
            printf("\nOK ! Voici vos saisies en partant de la fin :\n");
        }
        else {
            // Saisie
            scanf("%d", &saisie);
            f(i - 1);
            // Affichage
            printf("%d\n", saisie);
        }
    }
    ```