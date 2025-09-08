# 01 - Du C au C++

## Cours

![Du C au C++](../pdf/cours/bts2/bts2_01_du-c-au-cpp.pdf)

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

??? success "Correction"

    ```c
    #include <iostream>

    using namespace std;

    int main() {
        cout << "hello, world!";
        return 0;
    }
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

??? success "Correction"

    ```cpp
    #include <iostream>
    #include <cmath>

    using namespace std;

    int main() {
        int input;

        system("chcp 65001");
        system("cls");
        
        cout << endl << "-= Calcul de racine carrée =-" << endl << endl;

        cout << "Entrer 0 pour quitter." << endl << endl;
        
        do {
        
            cout << "Entrer une valeur positive : ";
            cin >> input;
            if (input < 0) {
                cout << "J'ai dit P-O-S-I-T-I-V-E !!!" << endl << endl;
                continue;
            }
            if (input > 0) {
                cout << "Racine carrée : " << sqrt(input) << endl << endl;
            }
        }
        while(input != 0);
        
        return 0;
    }
    ```

## Exercice 2

Ecrire deux fonctions de swap utilisant :

1. le passage par adresse
2. le passage par référence

et le programme principal de test les utilisant en C++.

??? danger "Aller plus loin"

    Trouver une méthode de swap sans utiliser de 3<sup>ème</sup> variable.

??? success "Correction"

    ```c
    ```

## Exercice 3

Ecrire une fonction qui permet de retourner le nombre de secondes en additionnant les heures, minutes et secondes qu'on lui passe en paramètres. 

Seul le paramètre des heures est obligatoire. 

Ecrire un programme de test.

??? tip "Indice"
    
    Arguments optionnels

??? success "Correction"

    ```cpp
    ```

## Exercice 4

```cpp
void fct (int);         // fonction A 
void fct (float); 		// fonction B
void fct (int, float); 	// fonction C
void fct (float, int); 	// fonction D

int main () {
    int n, p;
    float x, y;
    char c;
    double z;
    /*
    Les appels suivants des fonctions sont ils corrects ? 
    Si oui, quelle est la fonction appelée et quelles sont
    éventuellement les conversions mises en place ?
    *
    fct(n);
    fct(x);
    fct(n, x);
    fct(x, n);
    fct(c);
    fct(n, p);
    fct(n, c);
    fct(n, z);
}
```

??? success "Correction"

    ```output
    ```

## Exercice 5

1. Ecrire une fonction qui permet d'effectuer la saisie d’un tableau d'entiers qui lui est passé (vide) en paramètre **puis** l'affiche.

2. Surdéfinir cette fonction pour qu’elle puisse effectuer la saisie de caractères.

3. Ecrire un programme de test.

Exemple :
    
```output
> ./exo5.exe
Saisir 3 entiers :
1: 23
2: 675
3: -33
Valeurs saisie : 23, 675, -33
```
    
??? tip "Indice"
    
    La fonction a 2 arguments.
    
??? tip "Indice"
    
    ```cpp
    // Prototype de la fonction
    void remplir(int *, int);
    ```

??? success "Correction"

    ```cpp
    ```
    
??? danger "Aller plus loin"
    
    Rendre le nombre d’éléments et le type de tableau paramétrable via la ligne de commande.

## Exercice 6

Migrer le programme en C suivant en C++ en utilisant les nouvelles possibilités du langage

```cpp
#include <stdio.h>

struct Personne
{
    char nom [30];
    int age;
};

int main () {
    struct Personne p[3];
    int nbpers, i;
    nbpers = 0;
    //saisie des 3 personnes
    for (i = 0; i < 3; i++)
    {
        printf("Saisissez le nom de la personne N° %d : ", i+1);
        gets(p[i].nom);
        printf("Saisissez l'age de la personne N° %d : ", i+1);
        scanf("%d", &p[i].age);
        nbpers++;
    }
    printf("\\n%d personnes ont ete saisies\\n", nbpers);

    return 0;
}
```

??? success "Correction"

    ```cpp
    ```

??? danger "Aller plus loin"
    
    Déplacer le code de remplissage de la personne dans une fonction `saisiePersonne`.
