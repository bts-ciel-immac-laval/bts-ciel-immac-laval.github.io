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
