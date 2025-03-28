# Algorithme de Dijkstra

[:material-file-download: Télécharger le support](../../pdf/cours/bts1/bts1_14_math-x-sti_dijkstra.pdf){ .md-button .md-button--primary }

## Solution de l'exercice 1

<video width="640"  controls>
    <source src="/files/bts1/bts1_14_math-x-sti_dijkstra.mp4" type="video/mp4">
</video>

## Implémentation en C

Compléter les fonctions suivantes pour terminer le programme :

- `recuperer_poids_arete`
- `recuperer_chemin_minimum`

```c
#include <stdio.h>

#define NB_NOEUDS   8
#define NB_ARETES   13
#define INFINI      9999

struct arete {
    int parent;
    int enfant;
    int poids;
};

//       2--29--5--22--7          C--29--F--22--H    
//     / |      |    / |        / |      |    / |    
//   26  22    25  29  11     26  22    25  29  11   
//  /    |      | /    |     /    |      | /    |    
// 0-43--3--33--4--16--6    A-43--D--33--E--16--G    
//  \    |    /              \    |    /             
//   31 24  21                31 24  21              
//     \ | /                    \ | /                
//       1                        B                  

struct noeud {
    char nom;
    int via;
    int cout;
    int etudie;
};

/**
 * @brief Affiche le contenu du tableau parcours (le tableau de travail)
 * 
 * @param parcours Le tableau parcours 
 */
void afficher_parcours(struct noeud * parcours) {
    printf("Noeud | Via   | Cout\n");
    for (int i = 0; i < NB_NOEUDS; i++) {
        printf( "%5c | %5c | %4d\n",
                parcours[i].nom, 
                parcours[i].via == -1 ? ' ' : parcours[parcours[i].via].nom, 
                parcours[i].cout
        );
    }
}

/**
 * @brief Retourne le poids d'une arête (parent -> enfant) dans le graphe
 * 
 * @param graphe Le tableau du graphe
 * @param parent Le noeud parent (origine)
 * @param enfant Le noeud enfant (destination)
 * @return int Le poids de l'arête si elle existe, sinon INFINI
 */
int recuperer_poids_arete(struct arete * graphe, int parent, int enfant) {
		
}

/**
 * @brief Renvoie parmi les noeuds non étudiés celui dont le poids pour y arriver est le plus petit.
 * 
 * @param parcours Le tableau contenant les noeuds (le tableau de travail)
 * @return int Le plus petit poids s'il reste des noeuds à étudier sinon -1
 */
int recuperer_chemin_minimum(struct noeud * parcours) {
		
}

/**
 * @brief Affiche le chemin le plus court en remontant dans le tableau parcours (tableau de travail)
 * 
 * @param parcours le tableau parcours (tableau de travail)
 * @param noeud_cible le noeud de destination
 */
void print_recursif(struct noeud * parcours, int noeud_cible) {
    if (noeud_cible == 0) {
        printf("%c", parcours[0].nom);
    }
    else {
        print_recursif(parcours, parcours[noeud_cible].via);
        printf(" -> %c", parcours[noeud_cible].nom);
    }
}

int main() {
    
    struct arete graphe[] = {
        { 0, 1, 31 },
        { 0, 2, 26 },
        { 0, 3, 43 },
        { 1, 3, 24 },
        { 1, 4, 21 },
        { 2, 3, 22 },
        { 2, 5, 29 },
        { 3, 4, 33 },
        { 4, 5, 25 },
        { 4, 6, 16 },
        { 4, 7, 29 },
        { 5, 4, 25 }, // Arete EF dans les 2 sens...
        { 5, 7, 22 },
        { 6, 7, 11 },
    };

    struct noeud parcours[] = {
        { 'A',  0, 0,      1 },
        { 'B', -1, INFINI, 0 },
        { 'C', -1, INFINI, 0 },
        { 'D', -1, INFINI, 0 },
        { 'E', -1, INFINI, 0 },
        { 'F', -1, INFINI, 0 },
        { 'G', -1, INFINI, 0 },
        { 'H', -1, INFINI, 0 },
    };

    // On commence avec le premier noeud.
    int noeud_choisi = 0;

    // Démarrage
    printf("\nDemarrage :\n");
    afficher_parcours(parcours);
    printf("Noeud choisi : %c\n", parcours[noeud_choisi].nom);
    
    // Etude des noeuds
    // Tant qu'il reste des noeuds à étudier
    for (int i = 1; noeud_choisi != -1; i++) {
        // Pour chacun des noeuds...
        for (int j = 0; j < NB_NOEUDS; j++) {
            // ... s'il n'a pas été étudié...
            if (parcours[j].etudie == 0) {
                // ... on récupère le poids de l'arête qui le relie directement au noeud choisi.
                int cout = recuperer_poids_arete(graphe, noeud_choisi, j);
                // Si cette arête existe...
                if (cout != INFINI) {
                    // ... on cumule le poids récupéré avec celui cumulé pour arrivé au noeud choisi.
                    cout = parcours[noeud_choisi].cout + cout;
                    // Si ce poids est meilleur que le poids précédemment calculé...
                    if (cout < parcours[j].cout) {
                        // ... on met à jour le noeud !
                        parcours[j].cout = cout;
                        parcours[j].via = noeud_choisi;
                    }
                }
            }
        }

        // On repart du noeud non étudié au plus faible poids.
        noeud_choisi = recuperer_chemin_minimum(parcours);
        if (noeud_choisi != -1) {
            parcours[noeud_choisi].etudie = 1;
        }

        // Affichage
        printf("\nEtape %d :\n", i);
        afficher_parcours(parcours);
        if (noeud_choisi != -1) {
            printf("Noeud choisi : %c\n", parcours[noeud_choisi].nom);
        }
        else {
            printf("Fin\n");
        }
    }

    // Coût minimum et chemin le moins coûteux
    printf("\nLe chemin le moins couteux est :\n");
    print_recursif(parcours, NB_NOEUDS - 1);
    printf("\n\nLe cout minimum pour y arriver est : %d.\n\n", parcours[NB_NOEUDS - 1].cout);

    return 0;
}
```

- Résultat attendu
    
    ```
    > ./dijkstra.exe
    
    Demarrage :
    Noeud | Via   | Cout
        A |     A |    0
        B |       | 9999
        C |       | 9999
        D |       | 9999
        E |       | 9999
        F |       | 9999
        G |       | 9999
        H |       | 9999
    Noeud choisi : A
    
    Etape 1 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |       | 9999
        F |       | 9999
        G |       | 9999
        H |       | 9999
    Noeud choisi : C
    
    Etape 2 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |       | 9999
        F |     C |   55
        G |       | 9999
        H |       | 9999
    Noeud choisi : B
    
    Etape 3 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |     B |   52
        F |     C |   55
        G |       | 9999
        H |       | 9999
    Noeud choisi : D
    
    Etape 4 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |     B |   52
        F |     C |   55
        G |       | 9999
        H |       | 9999
    Noeud choisi : E
    
    Etape 5 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |     B |   52
        F |     C |   55
        G |     E |   68
        H |     E |   81
    Noeud choisi : F
    
    Etape 6 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |     B |   52
        F |     C |   55
        G |     E |   68
        H |     F |   77
    Noeud choisi : G
    
    Etape 7 :
    Noeud | Via   | Cout
        A |     A |    0
        B |     A |   31
        C |     A |   26
        D |     A |   43
        E |     B |   52
        F |     C |   55
        G |     E |   68
        H |     F |   77
    Fin
    
    Le chemin le moins couteux est :
    A -> C -> F -> H
    
    Le cout minimum pour y arriver est : 77.
    ```

??? success "Solution"

    ```c
    /**
    * @brief Retourne le poids d'une arête (parent -> enfant) dans le graphe
    * 
    * @param graphe Le tableau du graphe
    * @param parent Le noeud parent (origine)
    * @param enfant Le noeud enfant (destination)
    * @return int Le poids de l'arête si elle existe, sinon INFINI
    */
    int recuperer_poids_arete(struct arete * graphe, int parent, int enfant) {
        for (int i = 0; i < NB_ARETES; i++) {
            if (graphe[i].parent == parent && graphe[i].enfant == enfant) {
                return graphe[i].poids;
            }
        }
        return INFINI;
    }

    /**
    * @brief Renvoie parmi les noeuds non étudiés celui dont le poids 
    *        pour y arriver est le plus petit.
    * 
    * @param parcours Le tableau contenant les noeuds (le tableau de travail)
    * @return int Le plus petit poids s'il reste des noeuds à étudier sinon -1
    */
    int recuperer_chemin_minimum(struct noeud * parcours) {
        // Initialiser le minimum
        int min = INFINI;
        // Initialiser l'indice
        int iMin = -1;
        // On parcourt tous les noeuds :
        for (int i = 0; i < NB_NOEUDS; i++) {
            // Si le noeud n'est pas étudié
            if (parcours[i].etudie == 0) {
                // Si le cout du noeud est inférieur au minimum
                if (parcours[i].cout < min) {
                    // Sauvegarder le nouveau minimum
                    min = parcours[i].cout;
                    // Sauvegarder l'indice
                    iMin = i;
                }
            }
        }
        // Renvoyer l'indice
        return iMin;
    }
    ``` 

## Aller plus loin

Adapter le programme pour résoudre le second exercice.

## Aller beaucoup plus loin

Adapter le programme pour pouvoir le paramétrer à l’aide d’un fichier !

<aside>
💡 Seul le tableau `graphe` nécessite d’être paramétré, toutes les autres variables et constantes peuvent être calculées à partir de ce tableau.
</aside>

