# Variables statiques

## Cours

![Gestions des variables](../pdf/cours/bts1/bts1_2425_05_fonctions_gestion_variables.pdf)

## Exercice 1

Ecrire une fonction qui compte combien de fois elle a été exécutée et renvoie ce nombre. 

Créer un programme de test qui la lance 4096 fois.

??? success "Solution"
    
    ```c
    #include <stdio.h>

    int iCountMyself();

    int main() {
        int count = 0;

        do {
            count = iCountMyself();
            
            // printf("%d\n", count); // <- Pour visualiser les appels 🤓
        }
        while (count != 4096);

        printf("Et voila : %d fois !\n", count);

        return 0;
    }

    int iCountMyself() {
        // Déclaration de la variable statique initialisée à 0 lors du premier appel...
        static int count = 0; 
        
        // ... mais qui va garder sa valeur entre 2 appels de la fonction !
        // Seule l'instruction suivante sera exécutée à chaque appel suivant.
        return ++count;
    }
    ```
    
## Exercice 2

Ecrire une fonction qui calcule le temps écoulé depuis sa dernière exécution (dans le même programme 😅).

Créer un programme de test qui l’appelle plusieurs fois de suite en faisant des "pauses" entre 2 appels.

??? success "Solution"
    
    ```c
    #include <stdio.h>
    #include <time.h>
    #include <windows.h>

    int mesureEntre2Appels();

    int main() {
        printf("%d\n", mesureEntre2Appels());
        Sleep(3000);                            // On patiente 3 secondes
        printf("%d\n", mesureEntre2Appels());
        Sleep(5000);                            // On patiente 5 secondes
        printf("%d\n", mesureEntre2Appels());

        return 0;
    }

    int mesureEntre2Appels() {
        // Une variable statique pour conserver l'heure du dernier appel de la fonction
        // Initialisée à 0 pour le 1er appel
        static time_t dernierAppel = 0;
        
        // On récupère l'heure du système (en secondes depuis EPOCH)
        time_t maintenant = time(NULL);
        int tempsEcoule = 0;
        
        // Si ce n'est pas le premier appel, on calcule le temps écoulé depuis le dernier appel
        if (dernierAppel != 0) {
            tempsEcoule = maintenant - dernierAppel;
        }

        // ⚠️ On n'oublie pas de sauvegarder l'heure du dernier appel !
        dernierAppel = time(NULL);
        
        // On renvoie (ou affiche) le temps écoulé.
        return tempsEcoule;
    }
    ```

## Exercice 3

Calculer la somme des saisies successives d’un utilisateur à l’aide d’une fonction utilisant une variable statique.

```
> ./exo3.exe
1
= 1
2
= 3
3
= 6
588
= 594
```

??? danger "Aller plus loin"
    
    Remettre le compteur à 0 si on saisit 0.
    
    Modifier la fonction et le programme de test pour répondre à ce besoin.
    
    ```
    > ./exo3.exe
    1
    = 1
    2
    = 3
    3
    = 6
    0
    = 0
    32
    = 32
    ```

??? success "Solution"
    
    ```c
    #include <stdio.h>
    #include <time.h>
    #include <windows.h>

    int addition(int);

    int main() {
        
        int saisie;
        
        printf("Saisir les valeur a additionner :\n");
        
        while(1) {
            scanf("%d", &saisie);
            printf("= %d\n", addition(saisie));
        }

        return 0;
    }

    int addition(int x) {
        static int somme = 0;
        somme += x;
        return somme;
    }
    ```

    Solution **Aller plus loin**

    ```c
    #include <stdio.h>
    #include <time.h>
    #include <windows.h>

    int addition(int);

    int main() {
        
        int saisie;
        
        printf("Saisir les valeur a additionner (0 pour reinitialiser) :\n");
        
        while(1) {
            scanf("%d", &saisie);
            printf("= %d\n", addition(saisie));
        }

        return 0;
    }

    int addition(int x) {
        static int somme = 0;
        if (x == 0) {
            somme = 0;
        }
        somme += x;
        return somme;
    }
    ```