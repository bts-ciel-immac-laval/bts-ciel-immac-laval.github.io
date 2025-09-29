---
icon: material/music
---

# Les gammes

Voici quelques mini-exercices pour s'entraîner aux basiques de la programmation en C/C++.

## Variables

??? exo-easy "Déclarer et afficher une variable permettant de stocker le résultat de `42 * 42`"

    ```c
    #include <stdio.h>

    int main() {

        short milleSeptCentSoixanteQuatre = 42 * 42;

        printf("%hd", milleSeptCentSoixanteQuatre);

        return 0;
    }
    ```

??? exo-easy "Déclarer et afficher une variable permettant de stocker le résultat de `42 * 10000.0`"

    ```c
    #include <stdio.h>

    int main() {

        float quarante_deux_milliemes = 42 / 10000.0;

        printf("%.f", quarante_deux_milliemes);

        return 0;
    }
    ```

??? exo-medium "Déclarer et afficher une variable permettant de stocker le résultat de `42 / 10000000.0`"

    ```c
    #include <stdio.h>

    int main() {

        float quarante_deux_dix_millioniemes = 42 / 10000000.0;

        printf("%.7f", quarante_deux_dix_millioniemes);

        return 0;
    }
    ```

??? exo-medium "Déclarer et afficher une variable permettant de stocker le [PIB de la Roumanie](https://fr.wikipedia.org/wiki/%C3%89conomie_de_la_Roumanie) :flag_ro:."

    ```c
    #include <stdio.h>

    int main() {

        long long pib_roumanie = 286509000000;

        printf("%lld", pib_roumanie);

        return 0;
    }
    ```

??? exo-medium "Déclarer et afficher une variable permettant de stocker le PIB des îles Tuvalu :flag_tv:."

    ```c
    #include <stdio.h>

    int main() {

        int pib_tuvalu = 47270000;

        printf("%d", pib_tuvalu);

        return 0;
    }
    ```

??? exo-medium "Déclarer et afficher une variable permettant de stocker le résultat de `sqrt(pow(42, 2) + pow(15, 3))`."

    ```c
    #include <stdio.h>
    #include <math.h>

    int main() {

        float hypotenuse = sqrt(pow(42, 2) + pow(15, 3));

        printf("%f", hypotenuse);

        return 0;
    }
    ```

??? exo-medium "Déclarer et afficher une variable permettant de stocker le résultat de `toupper('a')`."

    ```c    
    #include <stdio.h>
    #include <ctype.h>

    int main() {

        char a = toupper('a');

        printf("%c", a);

        return 0;
    }
    ```

??? exo-easy "Ecrire un programme qui demande la saisie d'un entier et l'affiche."

    ```c
    #include <stdio.h>

    int main() {

        int entier;

        scanf("%d", &entier);

        printf("%d", entier);

        return 0;
    }
    ```

??? exo-medium "Ecrire un programme qui demande la saisie d'un caractère et affiche sa valeur numérique dans la table ASCII en décimal et en héxadécimal."

    ```c
    #include <stdio.h>

    int main() {

        char caractere;

        scanf("%c", &caractere);

        printf("%hhd, %x", caractere, caractere);

        return 0;
    }
    ```

## Conditions

??? exo-easy "Ecrire un programme qui demande l'âge de l'utilisateur puis indique s'il est majeur ou non."

    ```c
    #include <stdio.h>

    int main() {

        int age;

        printf("Quel est votre age ?\n");

        scanf("%d", &age);

        if (age >= 18) {
            printf("Vous etes majeur.");
        }
        else {
            printf("Vous n'etes pas majeur.");
        }

        return 0;
    }
    ```

??? exo-easy "Ecrire un programme qui demande un entier à l'utilisateur puis lui indique s'il est pair, si c'est un multiple de 3 ou les deux."

    ```c
    #include <stdio.h>

    int main() {

        int entier;

        printf("Saisir un entier : ");

        scanf("%d", &entier);

        if (entier % 2 == 0 && entier % 3 == 0) {
            printf("%d est pair et multiple de 3.", entier);
        }
        else if (entier % 2 == 0) {
            printf("%d est pair.", entier);
        }
        else if (entier % 3 == 0) {
            printf("%d est multiple de 3.", entier);
        }

        return 0;
    }
    ```

## Boucles

??? exo-easy "Ecrire un programme qui affiche les nombres de 1 à 100 inclus (avec un for et un while)."

    ```c
    #include <stdio.h>

    int main() {

        for (int i = 1; i <= 100; i++) {
            printf("%d ", i);
        }

        return 0;
    }
    ```

    ```c
    #include <stdio.h>

    int main() {

        int i = 1;
        while (i <= 100) {
            printf("%d ", i);
            i++;
        }

        return 0;
    }
    ```

??? exo-easy "Ecrire un programme qui affiche les nombres de 0 à 99 inclus (avec un for et un while)."

    ```c
    #include <stdio.h>

    int main() {

        for (int i = 0; i <= 99; i++) {
            printf("%d ", i);
        }

        return 0;
    }
    ```

    ```c
    #include <stdio.h>

    int main() {

        int i = 0;
        while (i <= 99) {
            printf("%d ", i);
            i++;
        }

        return 0;
    }
    ```

??? exo-medium "Ecrire un programme qui affiche les nombres impairs entre de 35 à 54 inclus (avec un for et un while)."

    ```c
    #include <stdio.h>

    int main() {

        for (int i = 35; i <= 54; i += 2) {
            printf("%d ", i);
        }

        return 0;
    }
    ```

    ```c
    #include <stdio.h>

    int main() {

        int i = 35;
        while (i <= 54) {
            printf("%d ", i);
            i += 2;
        }

        return 0;
    }
    ```

??? exo-medium "Ecrire un programme qui affiche un décompte de 59 à 0 (avec un for et un while)."

    ```c
    #include <stdio.h>

    int main() {

        for (int i = 59; i >= 0; i--) {
            printf("%d ", i);
        }

        return 0;
    }
    ```

    ```c
    #include <stdio.h>

    int main() {

        int i = 59;
        while (i >= 0) {
            printf("%d ", i);
            i--;
        }

        return 0;
    }
    ```

??? exo-medium "Ecrire un programme qui calcule le factoriel d'un nombre saisi par l'utilisateur (maximum 20!).<br>Rappel : $ n! = n * n - 1 * ... * 2 * 1 $ et $0! = 1$"

    ```c
    #include <stdio.h>

    int main() {

        int nombre;
        long long factoriel = 1;

        printf("Saisir un nombre : ");
        scanf("%d", &nombre);

        if (nombre > 20) {
            printf("Desole, je ne peux pas caluler plus que 20!");
            return -1;
        }

        for(int i = nombre; i > 1; i--) {
            factoriel *= i;
        }

        printf("%d! = %lld", nombre, factoriel);

        return 0;
    }
    ```

??? exo-hard "Ecrire un programme qui demande à l'utilisateur de deviner un nombre choisi aléatoirement entre 1 et 10. Le nombre de tentatives est affiché à la fin."

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main() {

        srand(time(NULL));

        int entier = 0, entierATrouver = rand() % 10 + 1, tentatives = 0;        

        printf("Devine un nombre entre 1 et 10 :\n");

        while (entier != entierATrouver) {
            tentatives++;
            printf("Essai %d : ", tentatives);
            scanf("%d", &entier);
        }

        printf("Bravo ! Tu as trouve %d en %d coup(s) !", entierATrouver, tentatives);

        return 0;
    }
    ```

??? exo-hard "Ecrire un programme qui affiche un décompte de 30 secondes."

    ```c
    #include <stdio.h>
    #include <time.h>

    int main() {
        
        time_t current = time(NULL);
        time_t previous = current, stop = current + 30;
        int remaining = 30;

        while ((current = time(NULL)) <= stop) {
            if (current - previous == 1) {
                previous = current;
                remaining--;
                printf("%d\n", remaining);
            }
        }
        
        return 0;
    }
    ```
