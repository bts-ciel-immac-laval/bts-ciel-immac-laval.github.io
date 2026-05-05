# Premiers pas en POO

## Exercice 1

![string](../images/illustration/string.jpg)

> Utiliser une classe

Créer un programme en C++ qui utilise la classe des chaînes de caractères [`std::string`](https://cplusplus.com/reference/string/string/){target="_blank"} :

+   Créer une variable `hw` et lui affecter la valeur `"hello"`

    +   Afficher la taille de la chaine ;

    +   Lui concaténer la chaîne `", world!"` (2 manières : méthode ou opérateur) ;

    +   Afficher la sous-chaîne du 2ème au 5ème caractères (2 manières : méthode ou algorithmique) ;

    +   Remplacer `"hello"` par `"bonjour"` en utilisant une méthode.

+   Créer une variable `input` et stocker-y la saisie de l'utilisateur :

    +   Si `input` est égale à `"hello"`, afficher `"bonjour"` ;

    +   Si `input` contient au moins 3 lettres à suivre `'l'`, afficher `"boooooooooooooonjour"`.

    +   Créer une fonction `app::cleanNum` qui efface les caractères numériques de la chaîne qui lui est passée en paramètre. La tester avec la saisie de l'utilisateur.


## Exercice 2

![grids](../images/illustration/grids.jpg)

> Utiliser une classe

Créer un programme en C++ qui utilise la classe des listes/tableaux [`std::vector`](https://cplusplus.com/reference/vector/vector/){target="_blank"} :

+   Créer un tableau vide d'entiers nommé `tab1`

    +   Y ajouter les nombres suivants : 8, 15, 23, 42

    +   Afficher la taille du tableau

    +   Afficher le contenu du tableau

    +   Créer une fonction `app::print` qui affiche le contenu d'un tableau d'entiers (ex : `[ 8, 15, 23, 42 ]`). La tester avec `tab1`.

    +   Insérer la valeur 16 entre 15 et 23

    +   Insérer la valeur 4 au début du tableau

+   Créer un tableau d'entiers nommé `tab2` qui contient 10 entiers de valeurs 3 (constructeur)

    +   Echanger le contenu de `tab1` et `tab2`

    +   Vider `tab2`

## Exercice 3

![range](../images/illustration/range.jpg)

> Concevoir, créer une classe et l'utiliser

### Besoin

On souhaite créer des variables pouvant contenir un entier dont la valeur est bornée entre une valeur minimale et maximale.

Une fois créée, la variable ne peut être qu'incrémenter ou décrémenter de 1.

Si une borne est atteinte, on ne peut pas la dépasser :

+   Incrémenter une variable qui a atteint la borne maximale n'a pas d'effet,

+   Décrémenter une variable qui a atteint la borne minimale n'a pas d'effet.

A tout moment, on pourra récupérer la valeur et la réinitialiser à sa valeur de départ.

On pourra également récupérer les valeurs maximales et minimales atteintes jusque-là.

### Travail

Concevoir, réaliser le diagramme de classe et développer en C++ la classe `IntRange` répondant au besoin décrit ci-dessus.

Réaliser un programme de test en C++ démontrant l'adéquation de la classe au besoin.