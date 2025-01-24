# Intégrales

[:material-file-download: Télécharger le support](../../pdf/cours/bts1/bts1_mathsxsti_integrales.pdf){ .md-button .md-button--primary }

??? success "Solution"

    *Solution avec les rectangles*

    Certains seront tentés d'avoir une approche "mathématiques" du problème :

    ```c
    float i = 0;
    float pas = 1.0f / 10;
    for (i = 0; i < 1; i += pas) {
        printf("%.10f\n", i);
    }
    ```

    Ce qui donne :
    
    ```
    0.0000000000
    0.1000000015
    0.2000000030
    0.3000000119
    0.4000000060
    0.5000000000
    0.6000000238
    0.7000000477
    0.8000000715
    0.9000000954
    ```

    😱

    Les problèmes de précision avec les nombres à virgule flottante en C (et dans beaucoup d'autres langages) viennent du fait que ces nombres sont représentés en binaire, et non en décimal. Le format de représentation des nombres à virgule flottante, basé sur le standard IEEE 754, utilise une quantité fixe de bits (généralement 32 bits pour un float ou 64 bits pour un double) pour stocker les nombres.

    Cela signifie que certains nombres décimaux, comme 0.1, ne peuvent pas être représentés de manière exacte en binaire. Par exemple, 0.1 en binaire est une fraction périodique, tout comme 1/3 est une fraction périodique en décimal. En conséquence, le résultat de certaines opérations comme 1.0 / 10 peut souffrir de petites erreurs d'arrondi.

    C'est pourquoi, lorsqu'on travaille avec des float ou double, il est fréquent de rencontrer de petites imprécisions. Ces erreurs peuvent être visibles lorsque des calculs impliquent des valeurs qui ne peuvent pas être représentées exactement dans le format binaire.

    Utilisons donc le nombre d'intervalles (int) et non le pas (float) pour réaliser notre boucle `for`.

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    float f(float);

    float aireMethode1(float, float, float);
    float aireMethode2(float, float, float);
    float aireMethode3(float, float, float);

    int main() {

        system("chcp 65001");
        system("cls");

        puts("Aire avec la méthode des rectangles au-dessous");
        printf("avec 10 intervalles : %f\n",  aireMethode1(0, 1, 10));
        printf("avec 50 intervalles : %f\n",  aireMethode1(0, 1, 50));
        printf("avec 100 intervalles : %f\n", aireMethode1(0, 1, 100));

        puts("Aire avec la méthode des rectangles au-dessus");
        printf("avec 10 intervalles : %f\n",  aireMethode2(0, 1, 10));
        printf("avec 50 intervalles : %f\n",  aireMethode2(0, 1, 50));
        printf("avec 100 intervalles : %f\n", aireMethode2(0, 1, 100));

        puts("Aire avec la méthode des rectangles au milieu");
        printf("avec 10 intervalles : %f\n",  aireMethode3(0, 1, 10));
        printf("avec 50 intervalles : %f\n",  aireMethode3(0, 1, 50));
        printf("avec 100 intervalles : %f\n", aireMethode3(0, 1, 100));

        return 0;
    }

    float f(float x) {
        return x * x;
    }

    float aireMethode1(float debut, float fin, float intervalles) {
        float somme = 0;
        float pas = (fin - debut) / intervalles;

        // Veiller à utiliser des valeurs précises pour s'assurer d'avoir le bon nombre d'itérations        
        for (int i = 0; i < intervalles; i++) { 
            somme += f(i * pas) * pas;
        }
        return somme;
    }

    float aireMethode2(float debut, float fin, float intervalles) {
        float somme = 0;
        float pas = (fin - debut) / intervalles;
        for (int i = 0; i < intervalles; i++) {
            somme += f(i * pas + pas) * pas;
        }
        return somme;
    }

    float aireMethode3(float debut, float fin, float intervalles) {
        float somme = 0;
        float pas = (fin - debut) / intervalles;
        for (int i = 0; i < intervalles; i++) {
            somme += f(i * pas + pas / 2) * pas;
        }
        return somme;
    }
    ```