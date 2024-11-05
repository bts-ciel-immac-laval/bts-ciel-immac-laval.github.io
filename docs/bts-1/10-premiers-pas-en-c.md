# 01 - Premiers pas en C

## Les entiers

<object class="fullScreenAble" data="../../pdf/cours/bts1/bts1_03_premiers-pas-en-c.pdf" type="application/pdf"></object>

### Déclarer une variable
    
+ Déclarer un entier nommé `a`.

??? success "Correction"

    ```c
    int a;
    ```
    
+ Déclarer un entier nommé `jeSuisUnEntier`.

??? success "Correction"

    ```c
    int jeSuisUnEntier;
    ```
    
+ Déclarer trois entiers `x`, `y` et `z`.

??? success "Correction"

    ```c
    int x, y, z;
    ```
    

### Différents types d’entiers
  
+ Déclarer un entier `int4Bytes` sur 4 octets.

??? success "Correction"

    ```c
    int int4Bytes;
    ```
    
+ Déclarer un entier `int2Bytes` sur 2 octets.

??? success "Correction"

    ```c
    short int2Bytes;
    ```

+ Déclarer un entier `int1Byte` sur 1 octet.

??? success "Correction"

    ```c
    char int1Byte;
    ```
    
+ Commenter chaque déclaration en notant la taille allouée.

??? success "Correction"

    ```c
    // Un entier sur 4 octets
    int int4Bytes;
    
    /* Un entier sur 2 octets */
    short int2Bytes;
    
    /*
    Un 
        entier 
            sur 
                1 
                    octet
    */
    char int1Byte;
    ```
    

### Affecter une valeur à une variable
    
+ Déclarer les entiers suivants en utilisant le type adéquat :
    
    + `base10` et lui affecter la valeur `234`.

    ??? success "Correction"

        ```c
        int base10;
        base10 = 234;
        ```

    + `base16` et lui affecter la valeur `2F`

    ??? success "Correction"

        ```c
        int base16;
        base16 = 0x2F; // 0x permet de spécifier une valeur en héxadécimal 
        ```

    + `negatif` et lui affecter la valeur `-1234567`

    ??? success "Correction"

        ```c
        int negatif;
        negatif = -1234567;
        ```

### Afficher le contenu d’une variable
  
+ Afficher les valeurs des variables `base10`, `base16` et `negatif` prédemment créées des manières suivantes :
    
    + avec 3 `printf` :
    
    ```
    234
    2F
    -1234567
    ```

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            int base10, base16, negatif;
            base10 = 234;
            base16 = 0x2F;
            negatif = -1234567;

            printf("%d\n", base10); // %d pour afficher la valeur décimale (base 10) d'un entier
                                    // \n pour passer à la ligne
            printf("%X\n", base16); // %x pour afficher la valeur héxadécimale (base16) d'un entier
                                    // %X pour l'afficher en majuscules
            printf("%d\n", negatif);

            return 0;
        }
        ```
    
    + avec un seul `printf` :
    
    ```
    234 2F -1234567
    
    2F
    -1234567
    234
    
    2F = 47
    ```

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            int base10, base16, negatif;
            base10 = 234;
            base16 = 0x2F;
            negatif = -1234567;

            printf("%d %X %d\n\n", base10, base16, negatif);

            printf("%X\n%d\n%d\n\n", base16, negatif, base10);
            
            printf("%X = %d", base16, base16);

            return 0;
        }
        ```

### Obtenir la taille d’une variable

+ Afficher la taille des variables `int4Bytes`, `int2Bytes` et `int1Byte` déclarées précédemment.

??? success "Correction"

    ```c
    #include <stdio.h>

    int main() {
        int int4Bytes;
        short int2Bytes;
        char int1Byte;

        // Il faut considérer le format comme un texte à trous, les % seront remplacés par les paramètres fournis ensuite.
        
        // sizeof est un opérateur qui permet de récupérer la taille d'une variable.

        printf("int4Bytes : %d octets,\nint2Bytes : %d octets,\nint1Byte  : %d octet.", 
               sizeof(int4Bytes),
               sizeof(int2Bytes),
               sizeof(int1Byte)
        );

        return 0;
    }
    ```

    Résultat : 

    ```
    int4Bytes : 4 octets,
    int2Bytes : 2 octets,
    int1Byte  : 1 octet.
    ```
    
### Initialiser une variable

1. Déclarer une variable `moi_pas_initialisee`, initialiser une variable `moi_initialisee` avec la valeur `123` et afficher les valeurs des deux variables.

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            int moi_pas_initialisee, moi_initialisee = 123;

            printf("moi_initialisee : %d\nmoi_pas_initialisee : %d", 
                moi_pas_initialisee,
                moi_initialisee
            );

            return 0;
        }
        ```
    
2. Lancer le programme à plusieurs reprises. *Qu’est-ce qu’il y a dans une variable si on l’initialise pas ?*
   
    ??? success "Correction"

        ```
        moi_initialisee : 426    !!? 🚨 Les variables ne sont pas automatiquement initialisée à 0 et récupèrent ce qu'il y avait dans l'espace mémoire alloué.
        moi_pas_initialisee : 123
        ```

### Calculs

+ Déclarer deux entiers pour stocker les longueurs des côtés `AB` (3 cm) et `BC` (4 cm) d’un triangle rectangle en B.

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            int AB = 3, BC = 4;

            return 0;
        }
        ```

+ Calculer son hypothénuse et stocker le résultat dans une variable `AC` et l’afficher.

    ??? success "Correction"

        ```c
        /**
         * D'après le théorème de Pythagore : 
         * AC² = AB² + BC²
         * AC  = √(AB² + BC²)
         *
         * Il existe une fonction sqrt() qui permet de calculer la racine carré d'une valeur.
         * Cette fonction est disponible dans la bibliothèque math.h, qu'on doit inclure dans 
         * le programme.
         * NB : Sous Linux, il faut dire au compilateur de lier math.h au programme en ajoutant 
         *      l'option -lm à la commande : gcc fichier.c -lm -o fichier.exe
         */
        #include <stdio.h>
        #include <math.h>

        int main() {
            int AB = 3, BC = 4, AC;

            AC = sqrt(AB * AB + BC * BC);

            printf("%d", AC);

            return 0;
        }
        ```

        Résultat : 

        ```
        5
        ```

### Opérateurs arithmétiques et relationnels
    
+ **Sur papier** : quel est le résultat des calculs (~~débiles~~) suivants ?

    ```
    (12 + 3 * 5 - 2) / 5

    -12 >= 3 + 5

    3 * 6 == 2 * 9 != 18
    ```
    
    ??? success "Correction"

        ```
        (12 + 3 * 5 - 2) / 5
        (12 +   15  - 2) / 5     🡒 La multiplication est prioritaire
               25        / 5
                         5

        -12 >= 3 + 5             🡒 Les opérateurx arithmétiques sont prioritaires
        -12 >= 8
             0                   🡒 Les opérateurs relationnels renvoient 0 ou 1.

        3 * 6 == 2 * 9 != 18
          18  ==  18   != 18     🡒 A priorité égale, on résoud de gauche à droite.
               1       != 18
                        1
        ```

### Limites des différents types d’entier

+ Initialiser un entier sur 1 octet avec la valeur `127` et afficher sa valeur et sa valeur + 1 

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            char limite = 127;
            
            //        🡓 on veut afficher un entier stocké sur 1 octet : %hhd
            printf("%hhd + 1 = %hhd", limite, limite + 1);

            return 0;
        }
        ```

        Résultat : 

        ```
        127 + 1 = -128
        ```
    
### Récupérer l’adresse d’une variable

+ Afficher l’adresse des variables `int4Bytes`, `int2Bytes` et `int1Byte` déclarées précédemment.

    ??? success "Correction"

        ```c
        #include <stdio.h>

        int main() {
            int int4Bytes;
            short int2Bytes;
            char int1Byte;

            // L'opérateur & permet d'afficher l'adresse en mémoire d'une variable
            // Par convention, on affiche les adresses en héxadécimal.
            
            printf("int4Bytes : %X,\nint2Bytes : %X,\nint1Byte  : %X.", 
                &int4Bytes,
                &int2Bytes,
                &int1Byte
            );

            return 0;
        }
        ```

        Résultat : 

        ```
        int4Bytes : 933FF64C,
        int2Bytes : 933FF64A,
        int1Byte  : 933FF649.
        ```
    
### Lire une saisie utilisateur

+ Reprendre l’exercice du calcul de l’hypothénuse en rendant la saisie des longueurs des deux côtés paramétrable par l’utilisateur :
    
    ```
    > ./hypothenuse.exe
    Mesure du premier côté : 12
    Mesure du second côté : 7
    L'hypothénuse mesure : 13.892443
    ```

    ??? success "Correction"

        ```c
        #include <stdio.h>
        #include <math.h>

        int main() {
            int AB, BC; // Pas d'initialisation, cette fois, c'est l'utilisateur qui va donner les valeurs.

            // Tout à l'heure le résultat était un entier, tout allait bien...
            // Mais cette fois, on rique d'obtenir des nombres réels.
            // sqrt() renvoie des réels de type double.
            double AC;

            printf("Mesure du premier cote : "); // On donne une indication à l'utilisateur.
            
            // scanf() permet de lire une saisie au clavier.
            
            //     🡓 on veut lire un entier : %d
            scanf("%d" , &AB);
            //            🡑 on veut le stocker à l'adresse de AB

            printf("Mesure du second cote : ");  // Second côté.
            scanf("%d", &BC);
             
            AC = sqrt(AB * AB + BC * BC);

            //                             🡓 on afficher un réel : %f
            printf("L'hypothenuse mesure : %f", AC);

            return 0;
        }
        ```

        Résultat : 

        ```
        Mesure du premier cote : 8
        Mesure du second cote : 13
        L'hypothenuse mesure : 15.264338
        ```
