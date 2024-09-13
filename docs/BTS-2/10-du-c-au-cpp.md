# 01 - Du C au C++

## Cours

<object data="../../pdf/cours/bts2/bts2_01_du-c-au-cpp.pdf" type="application/pdf">
    <embed src="../../pdf/cours/bts2/bts2_01_du-c-au-cpp.pdf" type="application/pdf" />
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

    ```c
    #include <iostream>
    #include <cmath>

    using namespace std;

    int main() {
        int input;
        
        cout << endl << "-= Calcul de racine carrée =-" << endl << endl;

        cout << "Entrer 0 pour quitter." << endl << endl;
        
        do {
        
            cout << "Entrer une valeur positive : ";
            cin >> input;
            if (input < 0) {
                cout << "J'ai dit P-O-S-I-T-I-V-E !!!" << endl;
                continue;
            }
            if (input > 0) {
                cout << "Racine carrée : " << sqrt(input) << endl;
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
    #include <iostream>

    using namespace std;

    void swapByAddr(int *, int *);
    void swapByRef(int &, int &);
    // Aller plus loin
    void swapWithoutTemp(int &, int &);

    int main() {
        int x = 12, y = -4;

        cout << "1/ x : " << x << ", y : " << y << endl;
        swapByAddr(&x, &y);
        cout << "2/ x : " << x << ", y : " << y << endl;
        swapByRef(x, y);
        cout << "3/ x : " << x << ", y : " << y << endl;
        swapWithoutTemp(x, y);
        cout << "4/ x : " << x << ", y : " << y << endl;
        
        return 0;
    }

    void swapByAddr(int * a, int * b) {
        int buffer = *a;
        *a = *b;
        *b = buffer;
    }

    void swapByRef(int & a, int & b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Aller plus loin
    void swapWithoutTemp(int & a, int & b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    ```

## Exercice 3

Ecrire une fonction qui permet de retourner le nombre de secondes en additionnant les heures, minutes et secondes qu'on lui passe en paramètres. 

Seul le paramètre des heures est obligatoire. 

Ecrire un programme de test.

??? tip "Indice"
    
    Arguments optionnels

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

??? danger "Aller plus loin"
    
    Déplacer le code de remplissage de la personne dans une fonction `saisiePersonne`.

## Exercices ++

### Exercice 7

Dessiner un sapin de Noël formé d'étoiles :

```output
Nombre d'étages : 5

    *
   ***
  *****
 *******
*********
    *
```

Le nombre d'étages est donné par l'utilisateur.

## Exercice 8

Afficher les tables de multiplications de 1 à 10 sous la forme suivante :

```output
     |   1   2   3   4   5   6   7   8   9  10
----------------------------------------------
  1  |   1   2   3   4   5   6   7   8   9  10
  2  |   2   4   6   8  10  12  14  16  18  20
  3  |   3   6   9  12  15  18  21  24  27  30
  4  |   4   8  12  16  20  24  28  32  36  40
  5  |   5  10  15  20  25  30  35  40  45  50
  6  |   6  12  18  24  30  36  42  48  54  60
  7  |   7  14  21  28  35  42  49  56  63  70
  8  |   8  16  24  32  40  48  56  64  72  80
  9  |   9  18  27  36  45  54  63  72  81  90
 10  |  10  20  30  40  50  60  70  80  90 100
```

??? danger "Aller plus loin"
    
    Rendre les tables affichées paramétrables via la ligne de commande.