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

Nommer les fonctions "echange".

??? danger "Aller plus loin"

    Trouver une méthode de swap sans utiliser de 3<sup>ème</sup> variable.

??? success "Correction"

    ```c
    #include <iostream>

    using namespace std;

    // Passage par adresse
    void echange(int * x, int * y) {
        int z = *x;
        *x = *y;
        *y = z;
    }

    // Passage par référence
    void echange(int & x, int & y) {
        int z = x;
        x = y;
        y = z;
    }

    // Aller plus loin
    void echangeSansVariableSupplementaire(int & a, int & b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    int main() {
        int a = 42, b = -1;

        cout << a << ", " << b << endl;
        echange(a, b);
        cout << a << ", " << b << endl;
        echange(&a, &b);
        cout << a << ", " << b << endl;
        echangeSansVariableSupplementaire(a, b);
        cout << a << ", " << b << endl;
        
        return 0;
    }
    ```

## Exercice 3

Ecrire une fonction qui permet de retourner le nombre de secondes en additionnant les heures, minutes et secondes qu'on lui passe en paramètres. 

Seul le paramètre des heures est obligatoire. 

Ecrire un programme de test.

??? tip "Indice"
    
    Arguments optionnels

??? success "Correction"

    ```cpp
    #include <iostream>

    using namespace std;

    // Prototype avec les valeurs par défaut
    int nombreDeSecondes(int heures, int minutes = 0, int secondes = 0);

    int main() {
        cout << nombreDeSecondes(1, 10, 25) << endl;
        cout << nombreDeSecondes(1, 10) << endl;
        cout << nombreDeSecondes(1) << endl;
        return 0;
    }
    // Définition de la fonction, SANS les valeurs par défaut
    int nombreDeSecondes(int heures, int minutes, int secondes) {
        return heures * 3600 + minutes * 60 + secondes;
    }
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
    */
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
    fct (n);    // Correct, appel de la fonction A
    fct (x);    // Correct, appel de la fonction B
    fct (n,x);  // Correct, appel de la fonction C
    fct (x,n);  // Correct, appel de la fonction D
    fct (c);    // Correct, appel de la fonction A, conversion implicite de char en int
    fct (n,p);  // Incorrect, conflit entre C et D
    fct (n,c);  // Incorrect, conflit entre C et D 
    fct (n,z);  // Correct, appel de la fonction C, conversion implicite de double en float
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
    #include <iostream>

    using namespace std;

    const int COUNT_INT = 5;
    const int COUNT_CHAR = 5;

    void remplir (int *, int); 
    // surdefinition de la fonction remplir
    void remplir (char *, int);

    int main() { 
        int intArray[COUNT_INT];
        remplir(intArray, COUNT_INT);

        cout << endl;

        char charArray[COUNT_CHAR];
        remplir(charArray, COUNT_CHAR);

        return 0;
    }

    void remplir (int * array, int count) {
        // Remplissage
        for (int i = 0; i < count; i++) {
            cout << "Saisissez l'entier N° " << i + 1 << " : ";
            cin >> array[i];
        }
        // Affichage
        cout << "Saisie :";
        for (int i = 0; i < count; i++) {
            cout << " " << array[i];
        }
    }


    void remplir (char * array, int count) {
        // Remplissage
        for (int i = 0; i < count; i++) {
            cout << "Saisissez le caractère N° " << i + 1 << " : ";
            cin >> array[i];
        }
        // Affichage
        cout << "Saisie :";
        for (int i = 0; i < count; i++) {
            cout << " " << array[i];
        }
    }
    ```
    
??? danger "Aller plus loin"
    
    Rendre le nombre d’éléments et le type de tableau paramétrable via la ligne de commande.

## Exercice 6

1.  Migrer le programme en C suivant en C++ en utilisant les nouvelles possibilités du langage.

2.  Compléter la fonction principale pour afficher les "personnes" saisies.

3.  Déplacer le code de remplissage de la personne dans une fonction `saisiePersonne`.

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
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    struct Personne
    {
        string nom;
        int age;
    };

    Personne saisiePersonne(int i) {
        Personne indigene;
        cout << "Saisissez le nom de la personne N°" << i + 1 << " : ";
        cin >> indigene.nom;
        
        cout << "Saisissez l'age de la personne N°" << i + 1 << " : ";
        cin >> indigene.age;

        return indigene;
    }

    int main () {
        vector<Personne> p;

        // Saisie des 3 personnes
        for (int i = 0; i < 3; i++)
        {
            p.push_back(saisiePersonne(i));
        }

        cout << endl << p.size() << " personnes ont ete saisies" << endl;

        for (int i = 0; i < p.size(); i++) {
            cout << p[i].nom << " (" << p[i].age << ")" << endl;
        }

        return 0;
    }
    ```
