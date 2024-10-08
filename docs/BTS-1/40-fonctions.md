# 04 - Fonctions

<iframe src="https://slides.com/redmo53/organiser-son-code/embed?style=light&byline=hidden&share=hidden" width="576" height="420" title="Organiser son code #1" scrolling="no" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>

## Exercice 1

Déclarer les fonctions suivantes :

+ Une fonction qui affiche la date du système (qu'on récupère via une fonction).

+ Une fonction qui affiche la table de multiplication d'un chiffre qui lui est passé en paramètre.

+ Une fonction qui affiche le résultat de la somme de deux entiers passés en paramètres.

+ Une fonction qui renvoie le résultat de la somme de deux réels passés en paramètres.

+ Une fonction qui demande de saisir deux nombres, les multiplie, affiche le résultat et le renvoie.

+ Une fonction qui renvoie le résultat de la division de deux réels passés en paramètres.

+ Une fonction qui demande à l'utilisateur de saisir une liste de 10 entiers et renvoie le plus grand.

+ Une fonction qui renvoie le plus grand des 10 entiers passés en paramètres.

## Exercice 2

Définir la fonction `minimum` qui prend en paramètres deux entiers et renvoie le premier s’il est strictement inférieur au second, sinon renvoie le second.

Ecrire un programme de test.

Le prototype :

```c
int minimum(int, int);
```

??? success "Solution"

    ![](../images/meme/waiting-barney.gif)

## Exercice 3

Indiquer pour chacune des fonctions ci-dessous si elles sont correctement définies et, si ce n’est pas le cas, expliquer l’anomalie.

```c
// Fonction 1
float division (float a, float b) {
    if (b != 0) {
        return a / b;
    }
}

// Fonction 2
float division (float a, float b) {
    if (b != 0) {
        return a / b;
    }
    return "Erreur !";
}

// Fonction 3
float division (float a, float b) {
    if (b != 0) {
        return a / b;
    }
    printf("Erreur !");
    return 0;
}

```

??? success "Solution"

    ![](../images/meme/waiting-zootopia.gif)

## Exercice 4

Soit le programme suivant :

```c
#include <stdio.h>

int main() {
    int s, a = 1, b = 3 ;
    s = somme(a, b);
    printf("%d + %d = %d\n", a, b, s);
    return 0;
}
```

Déclarer et définir la fonction `somme` qui effectue la somme des valeurs passées en arguments.

??? success "Solution"

    ![](../images/meme/waiting-bean.gif)    

## Exercice 5

Ecrire une fonction qui, pour des valeurs de a, b et x données par l’utilisateur, calcule le résultat de :

$$
ax^3 + 2 ax^2 + b
$$

```
> ./exo.exe
Valeurs de a, b, x : 3, 0, 1
= 9
Valeurs de a, b, x : 0, 2, 2
= 2
```

??? success "Solution"

    ![](../images/meme/waiting-kid.gif)
