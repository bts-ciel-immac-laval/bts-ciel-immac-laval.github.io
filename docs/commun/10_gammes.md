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

## Pointeurs

??? exo-easy "Ecrire une fonction qui remplace un caractère passé par **adresse** par le suivant dans la table ASCII"

    ```c
    #include <stdio.h>

    void remplacerCharParSuivant(char * c) {
        *c += 1;
    }

    int main() {
        char A = 'A';
        remplacerCharParSuivant(&A);
        printf("A = %c", A);

        return 0;
    }
    ```

??? exo-easy "En exécutant votre programme avec la commande `.\exo.exe test 1 2 3 0 "fin test"`, afficher les éléments présents sur la ligne de commande."

    ```c
    #include <stdio.h>

    int main(int argc, char ** argv) {
        for (int i = 0; i < argc; i++) {
            printf("%d: %s\n", i, argv[i]);
        }

        return 0;
    }
    ```

??? exo-medium "En exécutant votre programme avec la commande `.\exo.exe test 1 2 3 0 "fin test"`, n'afficher que les paramètres numériques passés au programme."

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main(int argc, char ** argv) {
        int temp;
        for (int i = 0; i < argc; i++) {
            temp = atoi(argv[i]);
            //                  ↓ Pour détecter un vrai 0
            if (temp != 0 || strcmp(argv[i], "0") == 0) {
                printf("%d\n", temp);
            }
        }

        return 0;
    }
    ```

## Structures

??? exo-easy "Déclarer une structure `UnEntierEtUnReel` qui permet de stocker un entier et un réel."

    ```c
    struct UnEntierEtUnReel {
        int unEntier;
        float unReel;
    };
    ```

??? exo-easy "Déclarer une structure `UnHorodatageEtDixReels` qui permet de stocker un horodatage (timestamp) et dix réels."

    ```c
    #include <time.h>

    struct UnHorodatageEtDixReels {
        time_t unHorodatage;
        float dixReels[10];
    };
    ```

??? exo-medium "Déclarer au moins deux structures `PersonneX` qui permettent de stocker le prénom, le nom et la date de naissance d'une personne et évaluer la place occupée en mémoire par une variable qui les utiliserait. Vérifier par le code."
    
    ```c
    #include <stdio.h>
    #include <time.h>

    struct Personne1 {
        char prenom[25];
        char nom[25];
        char dateNaissance[10];
    }; // → 25 + 25 + 10 = 60 octets / variable dont plein d'espace inutile dans prenom et nom.

    struct Personne2 {
        char * prenom;
        char * nom;
        time_t dateNaissance;
    }; // → 8 + 8 + 8 = 24 octets / variable + espace exact pour chaque chaîne de caractères qui sera stockée dans le tas.

    int main() {
        
        printf("%d %d", sizeof(struct Personne1), sizeof(struct Personne2)); // → 60 24
        
        return 0;
    }
    ```

??? exo-easy "Initialiser une variable `UnEntierEtUnReel` avec les valeurs `2` et `3.14` et afficher son contenu."

    ```c
    #include <stdio.h>

    struct UnEntierEtUnReel {
        int unEntier;
        float unReel;
    };

    int main() {
        
        struct UnEntierEtUnReel ueeu1 = { 2, 3.14 };

        printf("%d, %.2f", ueeu1.unEntier, ueeu1.unReel);
        
        return 0;
    }
    ```

??? exo-medium "Initialiser une variable `UnEntierEtUnReel` avec les valeurs `3.14` et `2` *dans cet ordre* et afficher son contenu."

    ```c
    #include <stdio.h>

    struct UnEntierEtUnReel {
        int unEntier;
        float unReel;
    };

    int main() {
        
        struct UnEntierEtUnReel ueeu1 = { .unReel = 3.14, .unEntier = 2 };

        printf("%d, %.2f", ueeu1.unEntier, ueeu1.unReel);
        
        return 0;
    }
    ```

??? exo-medium "Initialiser une variable `UnHorodatageEtDixReels` avec l'heure du système et dix valeurs et afficher son contenu."

    ```c
    #include <stdio.h>
    #include <time.h>

    struct UnHorodatageEtDixReels {
        time_t unHorodatage;
        float dixReels[10];
    };

    int main() {
        
        struct UnHorodatageEtDixReels uhedr1 = { time(NULL), { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 } };
        
        printf("Brut : %ld, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f\n", uhedr1.unHorodatage, uhedr1.dixReels[0], uhedr1.dixReels[1], uhedr1.dixReels[2], uhedr1.dixReels[3], uhedr1.dixReels[4], uhedr1.dixReels[5], uhedr1.dixReels[6], uhedr1.dixReels[7], uhedr1.dixReels[8], uhedr1.dixReels[9]);
        
        printf("\nMis en forme :\n");
        struct tm * tmHorodatage = localtime(&uhedr1.unHorodatage);
        printf("%02d/%02d/%04d %02d:%02d:%02d\n",
            tmHorodatage->tm_mday,
            tmHorodatage->tm_mon + 1,
            tmHorodatage->tm_year + 1900,
            tmHorodatage->tm_hour,
            tmHorodatage->tm_min,
            tmHorodatage->tm_sec
        );
        printf("[");
        for (int i = 0; i < 10; i++) {
            printf("%s%.1f", i == 0 ? "" : ", ", uhedr1.dixReels[i]);
        }
        printf("]\n");

        return 0;
    }
    ```

## Allocations dynamiques

??? exo-medium "Ecrire un programme qui prend en paramètre un nombre d'éléments, puis crée un tableau dans le tas à partir de ce nombre, le remplit des nombres de 1 à ce nombre - 1 et l'affiche."

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char ** argv) {
        int nbElements, * tableau;

        // Vérification des paramètres
        if (argc != 2) {
            puts("Erreur de paramètre !");
            return -1;
        }
        
        // Récupération du nombre d'éléments
        nbElements = atoi(argv[1]);
        if (nbElements == 0) {
            puts("Nombre d'éléments incorrect !");
            return -2;
        }

        // Allocation dans le tas
        tableau = (int *) malloc(nbElements * sizeof(int));
        // ou : tableau = (int *) calloc(nbElements, sizeof(int));
        // ou : tableau = (int *) realloc(NULL, nbElements * sizeof(int));

        // Vérification de l'allocation
        if (tableau == NULL) {
            puts("Erreur d'allocation !");
            return -3;
        }
        
        // Remplissage
        for (int i = 0; i < nbElements; i++) {
            tableau[i] = i + 1;
        }

        // Affichage
        for (int i = 0; i < nbElements; i++) {
            printf("%d\n", tableau[i]);
        }

        // L I B E R A T I O N
        free(tableau);

        return 0;
    }
    ```
