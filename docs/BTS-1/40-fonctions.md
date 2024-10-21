# 04 - Fonctions

<iframe src="https://slides.com/redmo53/organiser-son-code/embed?style=light&byline=hidden&share=hidden" width="576" height="420" title="Organiser son code #1" scrolling="no" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>

## Exercice 1

Déclarer (= proposer un prototype) les fonctions suivantes :

??? tip "Conseils"

    1. Identifier les **entrées** de la fonction. Que va-t-on devoir lui fournir comme valeurs en entrée pour qu'elle puisse fonctionner ? Si ces valeurs viennent d'une autre partie du programme, alors il faut un paramètre par information. Si la fonction les récupérer toute seule (en appelant une autre fonction), pas besoin de paramètres.

    2. Identifier les **sorties** de la fonction. Doit-elle retourner quelquechose **au programme qui l'appelle** ? Si oui, il faut que son type retour soit en adéquation avec la valeur retournée, sinon elle peut ne rien renvoyer.

+ Une fonction qui affiche la date du système (qu'on récupère via une fonction).

??? success "Solution"

    Entrées : Aucune, si on peut récupérer l'heure avec une fonction, on a besoin de rien.
    
    Sorties : On ne nous demande que d'afficher une donnée, donc rien à renvoyer.

    `void afficher_heure();`

+ Une fonction qui affiche la table de multiplication d'un chiffre qui lui est passé en paramètre.

??? success "Solution"

    Entrées : On a besoin du chiffre dont on doit afficher la table, donc un entier.
    
    Sorties : On ne nous demande que d'afficher une donnée, donc rien à renvoyer.

    `void displayMultiplicationTable(int);`

+ Une fonction qui affiche le résultat de la somme de deux entiers passés en paramètres.

??? success "Solution"

    Entrées : On a besoin des deux entiers qu'on doit additionner.
    
    Sorties : On ne nous demande que d'afficher une donnée, donc rien à renvoyer.

    `void affichageSomme(int, int);`

+ Une fonction qui renvoie le résultat de la somme de deux réels passés en paramètres.

??? success "Solution"

    Entrées : On a besoin des deux réels qu'on doit additionner.
    
    Sorties : On doit renvoyer le résultat de la somme de deux réels qui doit donc être... un réel.

    `float add(float, float);`

+ Une fonction qui demande de saisir deux nombres, les multiplie, affiche le résultat et le renvoie.

??? success "Solution"

    Entrées : Si la fonction demande la saisie (scanf) des deux nombres pas besoin de données en entrée.
    
    Sorties : Il faut renvoyer le produit de deux nombres dont on ne connaît pas la nature. Qui peut le plus peut le moins : mettons un `double` ! 

    `double multiplie();`

+ Une fonction qui renvoie le résultat de la division de deux réels passés en paramètres.

??? success "Solution"

    Entrées : On a besoin des deux réels.
    
    Sorties : On doit renvoyer le résultat de la division de deux réels qui doit donc être... un réel.

    `float division(float, float);`

+ Une fonction qui demande à l'utilisateur de saisir une liste de 10 entiers et renvoie le plus grand.

??? success "Solution"

    Entrées : La fonction gère la saisie, besoin de rien en entrée.
    
    Sorties : Le plus grand entier. Si on met un `int`, on s'assurera de lire des `int` dans le corps de la fonction.

    `int getMax();`

+ Une fonction qui renvoie le plus grand des 10 entiers passés en paramètres.

??? success "Solution"

    Entrées : Il nous faut de quoi passer 10 entiers... Pas de tableau pour l'instant (d'ailleurs, qu'est-ce que c'est !!? 🤔), donc 10 `int` !
    
    Sorties : Le plus grand entier qui sera un `int` ici.

    `int getMaxFrom10(int, int, int, int, int, int, int, int, int, int, int);`

## Exercice 2

Définir la fonction `minimum` qui prend en paramètres deux entiers et renvoie le premier s’il est strictement inférieur au second, sinon renvoie le second.

Ecrire un programme de test.

Le prototype :

```c
int minimum(int, int);
```

??? success "Solution"

    ```c
    #include <stdio.h>

    int minimum(int, int);

    int main() {
        
        printf("%d\n", minimum(5, 4));  // doit afficher 4
        printf("%d\n", minimum(7, 20)); // doit afficher 7
        printf("%d\n", minimum(5, 5));  // doit afficher 5
        
        return 0;
    }

    int minimum(int a, int b) {
        if (a < b) {
            return a;
        }
        else {
            return b;
        }
    }
    /*
    // Ecriture en une ligne :
    int minimum(int a, int b) {
        return a < b ? a : b ;
    }
    */
    ```

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

    **Fonction 1** : Si l’exécution ne passe pas dans le `if`, si `b` est égal à 0, il n’y a pas de `return`. Cela ne va pas gêner le compilateur, mais à l’exécution, dans ce cas, n’importe quelle valeur sera renvoyée… 

    **Fonction 2** : Ici, si `b` est égal à 0, on renvoie `"Erreur !"`, qui est une chaîne de caractères, ce qui ne correspond pas au type retour de la fonction. Cette fois, le programme ne compilera pas.

    **Fonction 3** : Cette fonction est correctement déclarée.

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

    ```c
    #include <stdio.h>

    // Déclaration
    int somme(int, int);

    int main() {
        int s, a = 1, b = 3 ;
        s = somme(a, b);
        printf("%d + %d = %d\n", a, b, s);
        return 0;
    }

    // Définition
    int somme(int x, int y) {
        return x + y;
    }
    ```

## Exercice 5

Ecrire une fonction qui, pour des valeurs de a, b et x saisies par l’utilisateur, calcule le résultat de :

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

    ```c
    #include <stdio.h>

    // Déclaration
    int fonction(int, int, int);

    int main() {
        int a, b, x;
        
        printf("Valeurs de a, b, x : ");
        scanf("%d, %d, %d", &a, &b, &x);
        
        printf("= %d\n", fonction(a, b, x));
        
        return 0;
    }

    // Définition
    int fonction(int a, int b, int x) {
        return a*x*x*x + 2*a*x*x + b;
    }
    ```

## Exercice 6

1. Ecrire une fonction `estPair` qui renvoie vrai si le nombre qui lui est passé est… pair 😎.

2. Ecrire une fonction `impairEntreBornes` qui affiche les nombres impairs entre 2 bornes en utilisant la fonction `estPair`.

3. Ecrire un programme de test.

4. Installer l'extension Doxygen Documentation Generator, puis commenter les fonctions en utilisant le format Doxygen (Commencer à taper `/**` 🤩).

??? danger "Aller plus loin"

    Proposer au moins une autre version de la fonction `impairEntreBornes` en utilisant toujours la fonction `estPair`.

??? success "Solution"

    ```c
    #include <stdio.h>

    int estPair(int);
    void impairEntreBornes(int, int);

    int main() {

        impairEntreBornes(1, 100); // affiche de 1, 3, 5... à 99
        impairEntreBornes(-4, 7);  // affiche -3, -1, 1, 3, 5, 7

        return 0;
    }

    /**
    * @brief Dit si la variable x est paire
    * 
    * @param x la variable dont on veut connaître la parité
    * @return int vrai (1) si x est paire, faux(0) sinon. 
    */
    int estPair(int x) {
        return x % 2 == 0;
    }

    
    void impairEntreBornes(int minimum, int maximum) {
        for (int i = minimum; i <= maximum; i++) {
            if (!estPair(i)) {          // i.e.   estPair(x) == 0
                printf("%d\n", i);
            }
        }
    }

    void impairEntreBornes2(int minimum, int maximum) {
        if (estPair(minimum)) {
            minimum ++;
        }
        for (int i = minimum; i <= maximum; i = i + 2) { // de 2 en 2
            printf("%d\n", i);
        }
    }
    ```

## Exercice 7

Ecrire un programme de calculatrice "simple" :

```
> ./exo4.exe
1 + 2
= 3

3 / 4
= 0.750000

55 * 56
= 3080

7 - 12
= -5
```

1. Déclarer les fonctions qui affichent le résultat des 4 opérations : addition, soustraction, multiplication et division.

2. Définir les 4 fonctions.

3. Faire appel aux 4 fonctions dans une fonction principale capable de lire des calculs tant que le programme n’est pas interrompu.

??? danger "Aller plus loin"

    1. Si ce n'est pas le cas, gérer la saisie de nombres à virgule flottante.
    
    2. Proposer un système pour reprendre le résultat du calcul précédent dans le calcul suivant.

??? success "Solution"

    Solution "simple" avec un **if ... else if**

    ```c
    #include <stdio.h>

    void addition(int, int);
    void soustraction(int, int);
    void multiplication(int, int);
    void division(int, int);

    int main() {
        int operand1, operand2;
        char operation;

        while(1) {

            scanf("%d %c %d", &operand1, &operation, &operand2);
            
            if (operation == '+') {
                addition(operand1, operand2);
            }
            else if (operation == '-') {
                soustraction(operand1, operand2);
            }
            else if (operation == '*') {
                multiplication(operand1, operand2);
            }
            else if (operation == '/') {
                division(operand1, operand2);
            }
            else {
                printf("Operation non reconnue :\nOperation autorisee : + - * /\n\n");
            }
        }
        
        return 0;
    }

    void addition(int a, int b) {
        printf("= %d\n\n", a + b);
    }

    void soustraction(int a, int b) {
        printf("= %d\n\n", a - b);
    }

    void multiplication(int a, int b) {
        printf("= %d\n\n", a * b);
    }

    void division(int a, int b) {
        printf("= %f\n\n", (float)a / (float)b);
    }
    ```

    Solution "simple" avec un **switch** (utilisable quand toutes les conditions d'un bloc portent sur les différentes valeurs d'une seule variable).

    ```c
    #include <stdio.h>

    void addition(int, int);
    void soustraction(int, int);
    void multiplication(int, int);
    void division(int, int);

    int main() {
        int operand1, operand2;
        char operation;

        while(1) {
            
            scanf("%d %c %d", &operand1, &operation, &operand2);
            
            switch (operation) {
                case '+' :
                    addition(operand1, operand2);
                    break; // Obligatoire sinon les autres  
                case '-' :
                    soustraction(operand1, operand2);
                    break; 
                case '*' :
                    multiplication(operand1, operand2);
                    break;  
                case '/' :
                    division(operand1, operand2);
                    break;
                default :
                    printf("Operation non reconnue :\nOperation autorisee : + - * /\n\n");
            }
        }
        
        return 0;
    }

    void addition(int a, int b) {
        printf("= %d\n\n", a + b);
    }

    void soustraction(int a, int b) {
        printf("= %d\n\n", a - b);
    }

    void multiplication(int a, int b) {
        printf("= %d\n\n", a * b);
    }

    void division(int a, int b) {
        printf("= %f\n\n", (float)a / (float)b);
    }
    ```

    Solution "Aller plus loin" 💪

    Cette version nécessite des connaissances que vous n'avez pas encore : on stocke la saisie dans une **chaîne de caractères** pour l'analyser puis on utilise **sscanf()** une fonction qui permet de faire un scanf sur une chaîne de caractères.

    ```c
    #include <stdio.h>

    // Les fonctions sont modifiées pour renvoyer le résultat
    float addition(float, float);
    float soustraction(float, float);
    float multiplication(float, float);
    float division(float, float);

    int main() {
        float operand1, operand2;
        char operation;

        // On doit analyser la saisie. Pour faire cela, on a besoin d'un tableau de caractères.
        char saisie[30] = "";

        while(1) {

            // On stocke la saisie dans le tableau...
            scanf("%s", saisie);
            
            // ... et on regarde si le premier caractère saisi est un opérateur
            if (saisie[0] == '+' || saisie[0] == '-' || saisie[0] == '/' || saisie[0] == '*') {
                
                // Si c'est le cas, on ne récupère pas le premier opérand
                sscanf(saisie, "%c %f", &operation, &operand2);
            
            }
            else {

                // Sinon on fait la lecture complète comme dans la version "simple".
                sscanf(saisie, "%f %c %f", &operand1, &operation, &operand2);

            }
            
            switch (operation) {
                case '+' :
                    operand1 = addition(operand1, operand2);
                    break; // Obligatoire sinon les autres  
                case '-' :
                    operand1 = soustraction(operand1, operand2);
                    break; 
                case '*' :
                    operand1 = multiplication(operand1, operand2);
                    break;  
                case '/' :
                    operand1 = division(operand1, operand2);
                    break;
                default :
                    printf("Operation non reconnue :\nOperation autorisee : + - * /\n\n");
                    return -1;
            }
        }
        
        return 0;
    }

    float addition(float a, float b) {
        float r = a + b;
        printf("= %f\n\n", r);
        return r;
    }

    float soustraction(float a, float b) {
        float r = a - b;
        printf("= %f\n\n", r);
        return r;
    }

    float multiplication(float a, float b) {
        float r = a * b;
        printf("= %f\n\n", r);
        return r;
    }

    float division(float a, float b) {
        float r = a / b;
        printf("= %f\n\n", r);
        return r;
    }
    ```
    
    Résultats :

    ```
    > ./exo7.exe
    1 + 2
    = 3.000000

    + 3
    = 6.000000

    * 4
    = 24.000000

    1 + 4
    = 5.000000

    * 5
    = 25.000000

    / 3
    = 8.333333

    * 3.14
    = 26.166666

    5 + 3
    = 8.000000
    ```