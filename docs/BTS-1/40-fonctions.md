# 04 - Fonctions

<iframe src="https://slides.com/redmo53/organiser-son-code/embed?style=light&byline=hidden&share=hidden" width="576" height="420" title="Organiser son code #1" scrolling="no" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>

## Exercice 1

Déclarer (= proposer un prototype) les fonctions suivantes :

??? tip "Conseils"

    1. Identifier les **entrées** de la fonction. Que va-t-on devoir lui fournir comme valeurs en entrée pour qu'elle puisse fonctionner ? Si ces valeurs viennent d'une autre partie du programme, alors il faut un paramètre par information. Si la fonction les récupérer toute seule (en appelant une autre fonction), pas besoin de paramètres.

    2. Identifier les **sorties** de la fonction. Doit-elle retourner quelquechose **au programme qui l'appelle** ? Si oui, il faut que son type retour soit en adéquation avec la valeur retournée, sinon elle peut ne rien renvoyer.

+ Une fonction qui affiche la date du système (qu'on récupère via une fonction).

??? success "Solution"

    `void afficher_heure();`

+ Une fonction qui affiche la table de multiplication d'un chiffre qui lui est passé en paramètre.

??? success "Solution"

    `void displayMultiplicationTable(int);`

+ Une fonction qui affiche le résultat de la somme de deux entiers passés en paramètres.

??? success "Solution"

    `void affichageSomme(int, int);`

+ Une fonction qui renvoie le résultat de la somme de deux réels passés en paramètres.

??? success "Solution"

    `float add(float, float);`

+ Une fonction qui demande de saisir deux nombres, les multiplie, affiche le résultat et le renvoie.

??? success "Solution"

    `int multiplie();`

+ Une fonction qui renvoie le résultat de la division de deux réels passés en paramètres.

??? success "Solution"

    `float division(float, float);`

+ Une fonction qui demande à l'utilisateur de saisir une liste de 10 entiers et renvoie le plus grand.

??? success "Solution"

    `int getMax();`

+ Une fonction qui renvoie le plus grand des 10 entiers passés en paramètres.

??? success "Solution"

    `int getMaxFrom10(int, int, int, int, int, int, int, int, int, int, int);`

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
