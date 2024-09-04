# Accueil

For full documentation visit [mkdocs.org](https://www.mkdocs.org).

## Commands

* `mkdocs new [dir-name]` - Create a new project.
* `mkdocs serve` - Start the live-reloading docs server.
* `mkdocs build` - Build the documentation site.
* `mkdocs -h` - Print help message and exit.

## Project layout

    mkdocs.yml    # The configuration file.
    docs/
        index.md  # The documentation homepage.
        ...       # Other markdown pages, images and other files.

!!! note "Phasellus posuere in sem ut cursus"

    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla et euismod
    nulla. Curabitur feugiat, tortor non consequat finibus, justo purus auctor
    massa, nec semper lorem quam in massa.

## Exercice 8

Créer un programme exo8.c qui demande un entier strictement positif à l'utilisateur et ne s’arrête pas **tant qu**’il n’a pas une réponse qui convient.

``` text title="example" 
> ./exo8.exe
Entrer un nombre strictement positif : -420
Ce nombre n'est pas strictement positif.

Entrer un nombre strictement positif : 0
Ce nombre n'est pas strictement positif.

Entrer un nombre strictement positif : 23
OK ! Merci...

```

??? tip "Aller plus loin"
    
    Compter le nombre de tentatives :
    
    ``` output
    > ./exo7.exe
    Entrer un nombre strictement positif : 23
    Chapeau ! Du premier coup !
    
    > ./exo7.exe
    Entrer un nombre strictement positif : -420
    Ce nombre n'est pas strictement positif.

    Entrer un nombre strictement positif : 0
    Ce nombre n'est pas strictement positif.

    Entrer un nombre strictement positif : 23
    Ah quand même... 3 fois pour y arriver :(
    ```
    
??? example "Solution"
    
    ``` cpp linenums="1" hl_lines="8 14"
    #include <stdio.h>
    
    int main() {
        
        int input = 0;
    
    	
        while (input <= 0) { /* (1)! */
            printf("Entrer un nombre strictement positif : ");
            scanf("%d", &input);
            if (input <= 0) {
                printf("Ce nombre n'est pas strictement positif.\n");
            }
        }
        printf("OK ! Merci...");
    
        return 0;
    }
    ```

    1. Exemple avec un type de boucle