# 01 - Du C au C++

## Cours

<object data="../../pdf/cours/bts2_01_du-c-au-cpp.pdf" type="application/pdf">
    <embed src="../../pdf/cours/bts2_01_du-c-au-cpp.pdf" type="application/pdf" />
</object>

## Exercice 0

Ecrire un programme en C++ qui affiche `hello, world!`

??? tip "Indice"
    
    Trame de base d'un programme en C++
    
    ``` cpp
    #include <iostream>

    using namespace std;

    int main() {

    }
    ```

??? tip "Indice"
    
    Compilation
    
    ``` output
    > g++ exo0.cpp -o exo.exe
    ```

## Exercice 1

Ecrire un programme en C++ qui calcule la racine carrée de nombres fournis par l'utilisateur. 

Il refusera les valeurs négatives et s'arrêtera si on lui fournit 0.

??? tip "Indice"

    Procéder par étapes

??? tip "Indice"

    1. Ecrire un programme en C++ qui lit et affiche une saisie numérique de l’utilisateur

    2. Compléter en ajoutant le test pour les valeurs négatives

    3. Compléter en affichant la racine carrée

    4. Compléter en ajoutant la boucle qui s’arrête si on saisit 0

??? tip "Indice"

    `sqrt()` est dans la bibliothèque cmath.

## Exercice 2

Ecrire deux fonctions de swap utilisant :

1. le passage par adresse
2. le passage par référence

et le programme principal de test les utilisant en C++.

??? danger "Aller plus loin"

    Trouver une méthode de swap sans utiliser de 3<sup>ème</sup> variable.