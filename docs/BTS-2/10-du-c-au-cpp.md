# 01 - Du C au C++

## 05/09/2024

### Exercice 0

Ecrire un programme en C++ qui affiche ```"hello, world!"```

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

### Exercice 1

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

    ```sqrt()``` est dans la bibliothèque cmath.