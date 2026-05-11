# Premiers pas en POO

## Exercice 1

![string](../images/illustration/string.jpg)

> Utiliser une classe

Créer un programme en C++ qui utilise la classe des chaînes de caractères [`std::string`](https://cplusplus.com/reference/string/string/){target="_blank"} :

+   Créer une variable `hw` et lui affecter la valeur `"hello"`

    +   Afficher la taille de la chaine ;

    +   Lui concaténer la chaîne `", world!"` (2 manières : méthode et opérateur) ;

    +   Afficher la sous-chaîne du 2ème au 5ème caractère (2 manières : méthode et algorithmique) ;

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

    +   Afficher le contenu du tableau (2 manières : for classqie et "foreach")

    +   Créer une fonction `app::print` qui affiche le contenu d'un tableau d'entiers (ex : `[8, 15, 23, 42]`). La tester avec `tab1`.

    +   Insérer la valeur 16 entre 15 et 23

    +   Insérer la valeur 4 au début du tableau

+   Créer un tableau d'entiers nommé `tab2` qui contient 10 entiers de valeurs 3 (constructeur)

    +   Echanger le contenu de `tab1` et `tab2`

    +   Vider `tab2`

??? success "Solution"

    ```cpp
    #include <iostream>
    #include <vector>

    namespace app {
        // Déclaration de app::print
        void print(std::vector<int> t) {
            std::cout << "[";
            for (int i = 0; i < t.size(); i++) {
                if (i != 0) {
                    std::cout << ", ";
                }
                std::cout << t[i];

            }
            std::cout << "]\n";
        }
    }

    int main() {
        std::vector<int> tab1;

        // Ajouter des éléments
        tab1.push_back(8);
        tab1.push_back(15);
        tab1.push_back(23);
        tab1.push_back(42);

        // Taille du tableau
        std::cout << tab1.size() << "\n";

        // Affichage du contenu - for classique
        for (int i = 0; i < tab1.size(); i++) {
            std::cout << i << " : " << tab1[i] << "\n";
        }

        // Affichage du contenu - "foreach"
        for (int valeur : tab1) {
            std::cout << valeur << "\n";
        }

        // Utilisation de la fonction app::print
        app::print(tab1);

        // Insertion d'un élément au milieu du tableau
        tab1.insert(tab1.begin() + 2, 16);
                        // ↑ renvoie un itérateur, un objet qui permet de se "balader" dans le tableau

        app::print(tab1);

        // Insertion d'un élément au début du tableau
        tab1.insert(tab1.begin(), 4);

        app::print(tab1);

        // Utilisation d'un constructeur pour initialiser le tableau
        std::vector<int> tab2(10, 3);
                            // ↑ valeur par défaut
                            // ↑ nombre d'éléments

        app::print(tab2);

        // Echanger le contenu de deux tableaux
        tab1.swap(tab2);

        app::print(tab1);
        app::print(tab2);

        // Vider un tableau
        tab2.clear();
        
        // Vérifier si le tableau est vide :
        if (tab2.empty()) {
            app::print(tab2);
        }

        return 0;
    }
    ```

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

Concevoir (1) la classe `IntRange` répondant au besoin décrit ci-dessus, réaliser son diagramme de classe et la développer en C++. 
{ .annotate }

1.  Identifier les entités, ce qui les caractérise, leurs relations, leurs échanges et comment on s'en sert.
    
    Un bon point de départ est d'imaginer un programme utilisant la classe.

Réaliser un programme de test en C++ démontrant l'adéquation de la classe au besoin.

??? success "Solution"

    ![Waiiit !](../images/meme/loading-04.gif)