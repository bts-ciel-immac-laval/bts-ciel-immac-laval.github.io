# 01 - Premiers programmes

## Récapitulatif

``` mermaid
%%{init: {'theme':'base'}}%%
mindmap
  root((Langage C))
    Compilateur
        langage compilé != langage interprété (Python, PHP)
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
                int 4 octets
            Réels
                float
        Identificateur
    Fonctions
        Principale main
            Point d'entrée du programme
        Bibliothèques 
            #include
            stdio.h
                ["printf()"]
                ["scanf()"]
    Opérateurs
        Arithmétiques
        Relationnels
        Logiques
        Adresse
    Logique
        if...else if...else
    Boucles
        Nombre de répétitions connu ?
            for
        En attendant un événement ?
            while
            Au moins une répétion nécessaire ?
                do...while
```

## Exercice 1

Créer un programme `exo1.c` qui demande à l'utilisateur son année de naissance et lui donne son âge.

```
> ./exo1.exe
Annee de naissance : 1984
Vous avez 38 ans !
```

> On sera plus précis dans l'exercice 3

??? success "Correction"

    ```c
    #include <stdio.h>
    #define ANNEE 2025

    int main() {
        int annee_utilisateur;

        printf("Annee de naissance : ");
        scanf("%d", &annee_utilisateur);
        printf("Vous avez %d ans !", ANNEE - annee_utilisateur);

        return 0;
    }
    ```

## Exercice 2

Créer un programme `exo2.c` qui demande à l'utilisateur sa date de naissance et lui souhaite un joyeux anniversaire **si** c'est aujourd'hui.

> Réfléchir sur le papier

> La date du jour doit être définie dans des **constantes**.

```
// Si nous sommes le 22/09 😄

> ./exo2.exe
Date de naissance : 22/09/1984
Joyeux anniversaire !

> ./exo2.exe
Date de naissance : 07/09/1984
Joyeux non-anniversaire !
```

??? success "Correction"

    ```c
    #include <stdio.h>

    #define MOIS    9
    #define JOUR    22

    int main() {
        int annee_utilisateur, mois_utilisateur, jour_utilisateur;

        printf("Date de naissance : ");
        scanf("%d/%d/%d", &jour_utilisateur, &mois_utilisateur, &annee_utilisateur);
        
        if (mois_utilisateur == MOIS && jour_utilisateur == JOUR) {
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
// Si nous sommes le 22/09 😄

> ./exo3.exe
Date de naissance : 25/09/1984
Vous avez 40 ans !

> ./exo3.exe
Date de naissance : 20/09/1984
Vous avez 41 ans !
```

??? success "Correction"

    ```c
    #include <stdio.h>

    #define MOIS    9
    #define JOUR    22
    #define ANNEE    2025

    int main() {
        int annee_utilisateur, mois_utilisateur, jour_utilisateur, age;

        printf("Date de naissance : ");
        scanf("%d/%d/%d", &jour_utilisateur, &mois_utilisateur, &annee_utilisateur);
        
        age = ANNEE - annee_utilisateur - 1;

        if (mois_utilisateur < MOIS || (mois_utilisateur == MOIS && jour_utilisateur <= JOUR)) {
            age++;
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

??? info "Un indice ?"

    Format pour `printf` :

    +   Octal : `%o`

    +   Hexadécimal : `%X`

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
