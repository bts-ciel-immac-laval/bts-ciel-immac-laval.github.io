# 02 - Premiers programmes

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

    ![Please... wait...](../images/meme/waiting-bean.gif)

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

    ![You've been rickrolled !](../images/meme/rickroll-roll.gif)

## Exercice 4

Créer un programme exo4.c qui demande un entier à l'utilisateur puis lui affiche la conversion en hexadécimal et en octal.

```
> ./exo4.exe
Nombre à convertir : 42
Hexadécimal : 2A
Octal : 52
```

??? success "Correction"

    ![Please... wait...](../images/meme/waiting-kid.gif)

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

    ![Please... wait...](../images/meme/waiting-zootopia.gif)

## Exercice 6

Créer un programme exo6.c qui demande deux entiers à l’utilisateur puis donne le résultat de leur division.

```
> ./exo6.exe
Entier 1 : 12
Entier 2 : 5
Resultat : 12 / 5 = 2.40000
```

??? success "Correction"

    ![Please... wait...](../images/meme/waiting-kid.gif)

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

    ![Please... wait...](../images/meme/waiting-bean.gif)