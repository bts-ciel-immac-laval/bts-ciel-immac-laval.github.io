# Premiers pas en C

## Les entiers

<object data="../../pdf/cours/bts1/bts1_03_premiers-pas-en-c.pdf" type="application/pdf">
    <embed src="../../pdf/cours/bts1/bts1_03_premiers-pas-en-c.pdf" type="application/pdf" />
</object>

### Déclarer une variable
    
+ Déclarer un entier nommé `a`.
    
+ Déclarer un entier nommé `jeSuisUnEntier`.
    
+ Déclarer trois entiers `x`, `y` et `z`.
    

### Différents types d’entiers
  
+ Déclarer un entier `int4Bytes` sur 4 octets.
    
+ Déclarer un entier `int2Bytes` sur 2 octets.

+ Déclarer un entier `int1Byte` sur 1 octet.
    
+ Commenter chaque déclaration en notant la taille allouée.
    

### Affecter une valeur à une variable
    
+ Déclarer les entiers suivants en utilisant le type adéquat :
    
    + `base10` et lui affecter la valeur `234`.

    + `base16` et lui affecter la valeur `2F`

    + `negatif` et lui affecter la valeur `-1234567`

### Afficher le contenu d’une variable
  
+ Afficher les valeurs des variables `base10`, `base16` et `negatif` prédemment créées des manières suivantes :
    
    + avec 3 `printf` :
    
    ```output
    234
    2F
    -1234567
    ```
    
    + avec un seul `printf` :
    
    ```output
    234 2F -1234567
    
    2F
    -1234567
    234
    
    2F = 47
    ```

### Obtenir la taille d’une variable

+ Afficher la taille des variables `int4Bytes`, `int2Bytes` et `int1Byte` déclarées précédemment.
    
### Initialiser une variable

1. Déclarer une variable `moi_pas_initialisee`, initialiser une variable `moi_initialisee` avec la valeur `123` et afficher les valeurs des deux variables.
    
2. Lancer le programme à plusieurs reprises. *Qu’est-ce qu’il y a dans une variable si on l’initialise pas ?*

### Calculs

+ Déclarer deux entiers pour stocker les longueurs des côtés `AB` (3 cm) et `BC` (4 cm) d’un triangle rectangle en B.

+ Calculer son hypothénuse et stocker le résultat dans une variable `AC` et l’afficher.

### Opérateurs arithmétiques et relationnels
    
+ **Sur papier** : quel est le résultat des calculs (~~débiles~~) suivants ?

    ```
    (12 + 3 * 5 - 2) / 5

    -12 >= 3 + 5

    3 * 6 == 2 * 9 != 18
    ```

### Limites des différents types d’entier

+ Initialiser un entier sur 1 octet avec la valeur `127` et afficher sa valeur et sa valeur + 1 
    
### Récupérer l’adresse d’une variable

+ Afficher l’adresse des variables `int4Bytes`, `int2Bytes` et `int1Byte` déclarées précédemment.
    
### Lire une saisie utilisateur

+ Reprendre l’exercice du calcul de l’hypothénuse en rendant la saisie des longueurs des deux côtés paramétrable par l’utilisateur :
    
    ```output
    > ./hypothenuse.exe
    Mesure du premier côté : 12
    Mesure du second côté : 7
    L'hypothénuse mesure : 13.892443
    ```

## Exercices

### Exercice 1

Créer un programme `exo1.c` qui demande à l'utilisateur son année de naissance et lui donne son âge.

```output
> exo1.exe
Année de naissance : 1984
Vous avez 38 ans !
```

> On sera plus précis dans l'exercice 2

### Exercice 2

Créer un programme `exo2.c` qui demande à l'utilisateur son année, puis son mois, puis son jour de naissance et lui souhaite un joyeux anniversaire **si** c'est aujourd'hui.

> Réfléchir sur le papier

> La date du jour doit être définie dans des constantes.

```output
// Si nous sommes le 13/09 😄

> exo2.exe
Année de naissance : 1984
Mois de naissance : 9
Jour de naissance : 13
Joyeux anniversaire !

> exo2.exe
Année de naissance : 1984
Mois de naissance : 9
Jour de naissance : 7
Joyeux non-anniversaire !
```