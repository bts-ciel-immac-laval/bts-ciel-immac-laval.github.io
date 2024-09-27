# 02 - Premiers programmes

## Récapitulatif

``` mermaid
%%{init: {'theme':'neutral'}}%%
mindmap
  root((Langage C))
    Compilateur
        langage compilé != langage interprété
            Python, PHP
        4 étapes
            1 - Pré-processeur
                Suppression des commentaires
                Récupération du contenu des bibliothèques
            2 - Compilateur
                Traduction en assembleur
            3 - Assemblage
                Traduction en binaire
            4 - Editeur de liens
                Récupération des bibliothèques pré-compilées
                Ajout des routines pour l'exécution
    Variables
        Types
            Entiers
                char 1 octet
                short 2 octets
                int 4 octets
                long 4 octets
                long long 8 octets
            Réels
                ["float 
                (précision à 6 chiffres)"]
                double
        Identificateur
    Fonctions
        Principale main
            Point d'entrée du programme
        Bibliothèques 
            #include
            stdio.h
                ["printf()"]
                ["scanf()"]
            math.h
                ["sqrt()"]
    Opérateurs
        Arithmétiques
        Relationnels
        Logiques
        Affectation composée
        Incrémentaux
        Taille
        Adresse
    Logique
        if...else if...else
```

## Exercice 1

Créer un programme `exo1.c` qui demande à l'utilisateur son année de naissance et lui donne son âge.

```
> exo1.exe
Annee de naissance : 1984
Vous avez 38 ans !
```

> On sera plus précis dans l'exercice 3

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int annee;

        printf("Annee de naissance : ");
        scanf("%d", &annee);
        //          🡑 on oublie pas le &, sinon gare à l'erreur de segmentation !
        //                                                               🡑 C'est ce qui arrive quand 
        //                                                                 on écrit dans une zone 
        //                                                                 mémoire qui ne nous est pas 
        //                                                                 allouée ⛔

        printf("Vous avez %d ans !", 2024 - annee);

        return 0;
    }
    ```

## Exercice 2

Créer un programme `exo2.c` qui demande à l'utilisateur son année, puis son mois, puis son jour de naissance et lui souhaite un joyeux anniversaire **si** c'est aujourd'hui.

> Réfléchir sur le papier

> La date du jour doit être définie dans des constantes.

```
// Si nous sommes le 13/09 😄

> exo2.exe
Annee de naissance : 1984
Mois de naissance : 9
Jour de naissance : 13
Joyeux anniversaire !

> exo2.exe
Annee de naissance : 1984
Mois de naissance : 9
Jour de naissance : 7
Joyeux non-anniversaire !
```

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int year, month, day;
        const int today_year  = 2023, 
                  today_month = 9, 
                  today_day   = 26;

        printf("Annee de naissance : ");
        scanf("%d", &year);
        printf("Mois de naissance : ");
        scanf("%d", &month);
        printf("Jour de naissance : ");
        scanf("%d", &day);

        if (day == today_day && month == today_month) {
            printf("Joyeux anniversaire !");
        }
        else {
            printf("Joyeux non-anniversaire !");
        }

        return 0;
    }
    ```

## Exercice 3

Créer un programme exo3.c qui demande à l'utilisateur son année, puis son mois, puis son jour de naissance et lui donne son âge plus précisément qu'à l'exercice 1.

```
> ./exo3.exe
Année de naissance : 1984
Mois de naissance : 12
Jour de naissance : 25
Vous avez 37 ans !

> ./exo3.exe
Année de naissance : 1984
Mois de naissance : 9
Jour de naissance : 7
Vous avez 38 ans !
```

??? success "Correction"
    
    Solution détaillée :

    ```c
    #include <stdio.h>

    int main() {
        int year, month, day;
        const int TODAY_YEAR = 2024, 
                TODAY_MONTH = 9, 
                TODAY_DAY = 17;

        printf("Annee de naissance : ");
        scanf("%d", &year);
        printf("Mois de naissance : ");
        scanf("%d", &month);
        printf("Jour de naissance : ");
        scanf("%d", &day);

        // L'anniversaire de l'utilisateur est déjà passé : 
        // (Mois avant le mois actuel)
        if (month < TODAY_MONTH) {
            printf("Vous avez %d ans !", TODAY_YEAR - year);
        }

        // (Ce mois-ci mais avant aujourd'hui ou aujourd'hui)
        else if (month == TODAY_MONTH && day <= TODAY_DAY) {
            printf("Vous avez %d ans !", TODAY_YEAR - year);
        }

        // L'anniversaire n'est pas encore passé :
        else {
            printf("Vous avez %d ans !", TODAY_YEAR - year - 1);
        }

        return 0;
    }
    ```

    Solution condensée :

    ```c
    #include <stdio.h>

    int main() {
        int year, month, day;
        const int TODAY_YEAR = 2024, 
                TODAY_MONTH = 9, 
                TODAY_DAY = 17;

        printf("Annee de naissance : ");
        scanf("%d", &year);
        printf("Mois de naissance : ");
        scanf("%d", &month);
        printf("Jour de naissance : ");
        scanf("%d", &day);
        
        if (month < TODAY_MONTH || (month == TODAY_MONTH && day <= TODAY_DAY)) {
            printf("Vous avez %d ans !", TODAY_YEAR - year);
        }
        else {
            printf("Vous avez %d ans !", TODAY_YEAR - year - 1);
        }

        return 0;
    }
    ```

## Exercice sur papier 1

Soit le programme suivant :

```c
#include <stdio.h>

int main() {
    int a = 0, b = 1, c = 2, d = 3;
    
    a = 5;                  // a:      b:     c:     d:
    a + b;                  // a:      b:     c:     d:
    c = a + b;              // a:      b:     c:     d:
    d = a - (2 * d - b);    // a:      b:     c:     d: 
    c = a + b * -c + 1;     // a:      b:     c:     d:
    a = b = c;              // a:      b:     c:     d:
    
    return 0;
}
```

Définir sur papier les valeurs stockées dans les variables a, b, c et d à la fin de chaque instruction.

> Les priorité des calculs sont les mêmes qu'en mathématiques

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int a = 0, b = 1, c = 2, d = 3;
        
        a = 5;                  // a: 5    b: 1   c: 2   d: 3
        a + b;                  // a: 5    b: 1   c: 2   d: 3
        c = a + b;              // a: 5    b: 1   c: 6   d: 3
        d = a - (2 * d - b);    // a: 5    b: 1   c: 6   d: 0
        c = a + b * -c + 1;     // a: 5    b: 1   c: 0   d: 0
        a = b = c;              // a: 0    b: 0   c: 0   d: 0
        
        return 0;
    }
    ```

## Exercice sur papier 2

Le programme suivant ne fonctionne pas... Pourquoi ?

```c
#include <stio.h>

main() {
    int jour = 0, mois = 0 annee = 0;

    printf("Donner un jour (1-31) : );
    scanf("%d", &jour);
    
    printf("Donner un mois (1-12) : ");
    scanf("%d", mois);

    printf("Donner un année (0-2021) : ")
    scanf("%d", &annee);
    
    print("La date saisie est : %02d/%02d/%04d", jour, mois, annee);

    return 0;
}
```

??? success "Correction"

    ```c
    #include <stdio.h> // et non stio

    int main() { // et non main() tout court
        int jour = 0, mois = 0, annee = 0; // Il manquait une virgule

        printf("Donner un jour (1-31) : "); // Chaine de caractère à fermer
        scanf("%d", &jour);

        printf("Donner un mois (1-12) : ");
        scanf("%d", &mois); // Sans le &, on risque l'erreur de segmentation

        printf("Donner un année (0-2021) : "); // Avec un point-virgule
        scanf("%d", &annee);

        printf("La date saisie est : %02d/%02d/%04d", jour, mois, annee); // et non print

        return 0;
    }
    ```

## Exercice 4

Créer un programme exo4.c qui demande un entier à l'utilisateur puis lui affiche la conversion en hexadécimal et en octal.

```
> ./exo4.exe
Nombre à convertir : 42
Hexadécimal : 2A
Octal : 52
```

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int nombre;

        printf("Nombre à convertir : ");
        scanf("%d", &nombre);

        printf("Hexadecimal : %X\n", nombre);
        printf("Octal : %o", nombre);

        return 0;
    }
    ```

## Exercice 5

Créer un programme exo5.c qui convertit des composantes RGB de décimal en hexadécimal.

```
> ./exo5.exe
Couleur en décimal : 255 204 0
Couleur en hexa    : #FFCC00
```

??? danger "Aller plus loin"
    
    Programmer l'inverse.
    
    ```
    > ./exo5.exe
    Couleur en hexa    : #FFCC00
    Couleur en décimal : 255 204 0
    ```

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        unsigned char r, g, b;

        printf("Couleur en decimal : ");
        scanf("%hhd %hhd %hhd", &r, &g, &b);

        printf("Couleur en hexa    : #%02X%02X%02X", r, g, b);

        return 0;
    }
    ```

## Exercice 6

Créer un programme exo6.c qui demande deux entiers à l’utilisateur puis donne le résultat de leur division.

```
> ./exo6.exe
Entier 1 : 12
Entier 2 : 5
Resultat : 12 / 5 = 2.40000
```

??? success "Correction"

    Solution 1

    ```c
    #include <stdio.h>

    int main() {
        int n1, n2;
        
        printf("Entier 1 : ");
        scanf("%d", &n1);
        
        printf("Entier 2 : ");
        scanf("%d", &n2);

        // int / int -> int 
        // donc on doit "caster" n1 et n2 pour obtenir un float
        printf("Resultat : %d / %d = %f", n1, n2, (float)n1 / (float)n2);
    }
    ```

    Solution 2

    ```c
    #include <stdio.h>

    int main() {
        float n1, n2;
        
        // On n'est pas obligé de dire à l'utilisateur 
        // qu'on stocke son entier dans un float :)
        printf("Entier 1 : ");
        scanf("%f", &n1);
        
        printf("Entier 2 : ");
        scanf("%f", &n2);

        // On affiche le float sans nombre après la virgule
        printf("Resultat : %.0f / %.0f = %f", n1, n2, n1 / n2);
    }
    ```

## Exercice 7

Créer un programme exo7.c qui demande un entier strictement positif à l'utilisateur et ne s’arrête pas **tant qu**’il n’a pas une réponse qui convient.

```
> ./exo7.exe
Entrer un nombre strictement positif : -420
Ce nombre n'est pas strictement positif.
Entrer un nombre strictement positif : 0
Ce nombre n'est pas strictement positif.
Entrer un nombre strictement positif : 23
OK ! Merci...
```
??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int nombre;

        do {
            printf("Entrer un nombre strictement positif : ");
            scanf("%d", &nombre);
            if(nombre <= 0) {
                printf("Ce nombre n'est pas strictement positif.\n");
            }
        }
        while(nombre <= 0);
         
        printf("OK ! Merci...\n");
    }
    ```

??? danger "Aller plus loin"
    
    Compter le nombre de tentatives :
    
    ```
    > ./exo7.exe
    Entrer un nombre strictement positif : 23
    Chapeau ! Du premier coup !
    
    > ./exo7.exe
    Entrer un nombre strictement positif : -420
    Ce nombre n'est pas strictement positif.
    Entrer un nombre strictement positif : 0
    Ce nombre n'est pas strictement positif.
    Entrer un nombre strictement positif : 23
    Ah quand même... 3 fois pour y arriver :(
    ```

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            int nombre, nb_essais = 1;

            do {
                printf("Entrer un nombre strictement positif : ");
                scanf("%d", &nombre);
                if(nombre <= 0) {
                    nb_essais++;
                    printf("Ce nombre n'est pas strictement positif.\n");
                }
            }
            while(nombre <= 0);
            
            if (nb_essais == 1) {
                printf("Chapeau ! Du premier coup !");
            }
            else {
                printf("Ah quand même... %d fois pour y arriver :(", nb_essais);
            }
        }
        ```
