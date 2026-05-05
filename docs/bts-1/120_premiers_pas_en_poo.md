# Premiers pas en POO

## Exercice 1

![string](../images/illustration/string.jpg)

> Utiliser une classe

Créer un programme en C++ qui utilise la classe des chaînes de caractères [`std::string`](https://cplusplus.com/reference/string/string/){target="_blank"} :

+   Créer une variable `hw` et lui affecter la valeur `"hello"`

    +   Afficher la taille de la chaine ;

    +   Lui concaténer la chaîne `", world!"` (2 manières : méthode ou opérateur) ;

    +   Afficher la sous-chaîne du 2ème au 5ème caractère (2 manières : méthode ou algorithmique) ;

    +   Remplacer `"hello"` par `"bonjour"` en utilisant une méthode.

+   Créer une variable `input` et stocker-y la saisie de l'utilisateur :

    +   Si `input` est égale à `"hello"`, afficher `"bonjour"` ;

    +   Si `input` contient au moins 3 lettres à suivre `'l'`, afficher `"boooooooooooooonjour"`.

    +   Créer une fonction `app::cleanNum` qui efface les caractères numériques de la chaîne qui lui est passée en paramètre. La tester avec la saisie de l'utilisateur.

??? success "Solution"

    ```cpp
    #include <iostream>
    #include <string>

    // Nouveau namespace
    namespace app {
        // Fonction avec passage par référence pour modifier l'objet envoyé et que
        // la modification soit effective dans la fonction appelante.
        void cleanNum(std::string & s) {
            // Parcours en partant de la fin pour éviter de sauter des caractères lors
            // des suppressions.
            for (int i = s.size(); i >= 0 ; i--) {
                if (s[i] >= '0' && s[i] <= '9') {
                    s.erase(i, 1);
                }
            }
        }
    }

    int main() {

        std::string hw;
        hw = "hello";                               // Affectation

        std::cout << hw << "\n";
        std::cout << hw.size() << "\n";             // Taille

                                                    // Concaténation
        hw.append(", world!");                      // Manière 1 avec une méthode
        // hw += ", world!";                        // Manière 2 avec un opérateur

        std::cout << hw << "\n";

                                                    // Sous-chaine
        std::cout << hw.substr(1, 4) << "\n";       // 1 avec une méthode
        
        for (int i = 1; i < 5; i++) {               // 2 algorithmiquement
            std::cout << hw[i]; // ou hw.at(i)
        }
        std::cout << "\n";

        hw.replace(hw.find("hello"), 5, "bonjour"); // Recherche et remplacement
        std::cout << hw << "\n";

        std::string input;

        do {
            std::cout << "> ";
            std::cin >> input;
                                                    // Comparaison
            if (input == "hello") {                 // en utilisant l'opérateur ==
            // if (input.compare("hello") == 0) {   // en utilisant une méthode
                std::cout << "bonjour\n";
            }

            // Recherche d'une sous-chaine
            else if (input.find("lll") != std::string::npos) {
                                        // ↑ valeur renvoyée si la sous-chaîne n'est pas trouvée
                std::cout << "boooooooooooooonjour\n";
            }

            // Appel de cleanNum()
            app::cleanNum(input);
            std::cout << input << "\n";

        } while (input != "quit");
        
        return 0;
    }
    ```


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

??? success "Solution"

    ![Waiiit !](../images/meme/loading-03.gif)

