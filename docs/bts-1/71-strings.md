# Les experts - Laval

![CSI Laval](../images/cours/bts-1/71/csi-laval.jpg)

## Contexte

Mme H.GENNERO, résidant au 18 rue du Gué d'Orger à Laval, s'est présentée ce matin au poste de police où vous officez en tant que technicien de police scientifique. 

Elle aurait aperçu son ex-compagnon, M. H.GRUBER, à plusieurs reprises à proximité de son domicile entre le 1er et le 25 novembre 2024. Sous le coup d'une injonction d'éloignement de 500 m, celui-ci est équipé d'un bracelet anti-rapprochement. Toutefois vos collègues du pôle national de télésurveillance et assistance n'ont pas relevé d'alerte sur cette période. 

L'inspecteur J.MCLANE convoque M. H.GRUBER. Durant son interrogatoire, vous êtes mandaté pour analyser le **fichier de journalisation des géolocalisations** du bracelet de M. H.GRUBER. Ce fichier contient les traces NMEA régulièrement générées par le capteur GPS du bracelet entre le 1er et 25 novembre 2024.

[:material-file-download: Télécharger le fichier de journalisation](../files/bts1/gruber_20241126.log){ .md-button .md-button--primary }

## Votre mission

Créer un programme permettant d'analyser le fichier de journalisation fourni et de générer un fichier CSV (séparateur point-virgule (;)) contenant la liste des géolocalisations contrevenant à l'injonction d'éloignement de M. H. GRUBER.

Pour chaque géolocalisation, les informations suivantes devront être mentionnées :

+   Date (`jj/mm/aaaa`),
+   Heure (`hh:mm:ss`),
+   Les coordonnées GPS en degrés décimaux (`DD.DDDDDD`),
+   La distance à vol d'oiseau calculée en mètres (`m`).

## Analyse 🔍

Voici la liste des points à éclaircir avant de coder :

+ [X] Lire un fichier CSV en C 📄

    + [X] Lire un fichier texte ligne par ligne

    + [ ] Séparer les données de chaque ligne suivant un séparateur (token)

+ [ ] Décoder une trame NMEA 🛰️

    + [ ] Vérifier le checksum
    
    + [ ] Récupérer l'heure

    + [ ] Récupérer et convertir la latitude et la longitude en degrés décimaux

+ [ ] Calculer la date 📆

+ [X] Calculer une distance à vol d'oiseau à partir de coordonnées GPS 🕊️

    ??? question "Calculer la distance entre deux points du globe 🌍 à partir de leurs coordonnées GPS 🛰️"

        La distance d entre deux points A et B sera calculée en utilisant la formule suivante :

        \begin{split}
        &x=(longitudeB-longitudeA)\times\cos(\frac{latitudeA+latitudeB}{2}) \\
        &y=latitudeB-latitudeA \\
        &d=\sqrt{x^2+y^2}\times6371
        \end{split}

        Notes : 
        
        +   Dans cette formule, les latitudes et longitudes sont exprimées en **radians**. 
        
        +   6371 correspond au rayon de la terre en km.

+ [ ] Ecrire un fichier CSV en C ✏️

## Développement incrémental

### Lire un fichier ligne par ligne

Coder le programme suivant :

![Algorigramme](../images/cours/bts-1/71/flowchart_01.png)

??? success "Code en C"

    ```c
    #include <stdio.h>

    int main() {
        
        char cheminFichierLog[] = "gruber_20241126.log",
            ligne[100];

        FILE * fichierLog = NULL;
        
        // Ouverture du fichier
        fichierLog = fopen(cheminFichierLog, "r");

        // Vérification
        if (fichierLog == NULL) {
            puts("Erreur lors de l'ouverture en lecture du fichier de log");
            return -1;
        }
        
        // Lecture ligne à ligne
        while (fgets(ligne, 100, fichierLog) != NULL) {
            printf(ligne);
        }

        // Fermeture du fichier
        fclose(fichierLog);

        return 0;
    }
    ```

:octicons-arrow-right-16: Transformer ce programme en fonction et la stocker dans une bibliothèque `experts.h`

??? success "Code en C"

    :octicons-file-16: `experts.h`

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    void lireFichier(char *);

    void lireFichier(char * cheminFichier) {
        char ligne[100];

        FILE * fichier = NULL;
        
        fichier = fopen(cheminFichier, "r");
        if (fichier == NULL) {
            puts("Erreur lors de l'ouverture en lecture du fichier de log");
            exit(-1);
        }
        
        while (fgets(ligne, 100, fichier) != NULL) {
            printf(ligne);
        }
        
        fclose(fichier);
    }
    ```

    :octicons-file-16: `experts.c`

    ```c
    #include "experts.h"

    int main() {
        
        lireFichier("gruber_20241126.log");

        return 0;
    }
    ```

### Vérifier le checksum d'une trame NMEA

Créer un programme qui isole, calcule et vérifie le checksum de la trame NMEA suivante :

```
$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E
```

??? info "Indice 1"

    S'inspirer des exemples fournis sur cette [page](https://rietman.wordpress.com/2008/09/25/how-to-calculate-the-nmea-checksum/).

??? success "Code en C"

    ```c
    #include <stdio.h>

    int main() {

        char trame[] = "$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E";
        char checksumCalcule = 0, checksumLu;
        int i;
        
        // Calcul du checksum
        for (i = 1; trame[i] != '*'; i++) {
            checksumCalcule ^= trame[i];    
        }

        // Lecture du checksum
        sscanf(trame + i + 1, "%x", &checksumLu);

        // Comparaison
        if (checksumCalcule == checksumLu) {
            puts("OK !");
        }
        else {
            puts("KO...");
        }
        
        return 0;
    }
    ```

:octicons-arrow-right-16: Transformer ce programme en fonction, la stocker dans une bibliothèque `experts.h` et tester avec d'autres trames.

??? success "Code en C"

    :octicons-file-16: `experts.h`

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    // [...]
    int verifierChecksumNMEA(char *);

    // [...]
    int verifierChecksumNMEA(char * trame) {
        char checksumCalcule = 0, checksumLu;
        int i;

        // Calcul du checksum
        for (i = 1; trame[i] != '*'; i++) {
            checksumCalcule ^= trame[i];
        }

        // Lecture du checksum
        sscanf(trame + i + 1, "%x", &checksumLu);

        // Comparaison
        return checksumCalcule == checksumLu;
    }
    ```

    :octicons-file-16: `experts.c`

    ```c
    #include "experts.h"

    int main() {

        if (verifierChecksumNMEA("$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E")) {
            puts("OK !");
        }
        else {
            puts("KO...");
        }
        
        return 0;
    }
    ```

### Séparer les données de chaque ligne suivant un séparateur (token)

Créer un programme qui lit la ligne suivante, extrait chacune des valeurs dans une chaine de caractères et les affiche.

```
$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E
```

??? info "Indice 1"

    Utiliser un tableau de chaînes de caractères

??? info "Indice 2"

    Utiliser la fonction [strtok()](https://koor.fr/C/cstring/strtok.wp)

??? success "Code en C"

    Solution avec un tableau de tableau qui récupère toutes les valeurs :

    ```c
    #include <stdio.h>
    #include <string.h>

    int main() {

        char ligne[] = "$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E";
        char valeurs[12][13] = { "" };
        int i = 0;

        char * valeur = strtok (ligne, ",");
        while (valeur != NULL) {
            strcpy(valeurs[i++], valeur);
            valeur = strtok (NULL, ",");
        }

        for (int i = 0; i < 12; i++) {
            puts(valeurs[i]);
        }
        
        return 0;
    }
    ```

:octicons-arrow-right-16: Transformer ce programme en fonction, la stocker dans une bibliothèque `experts.h` et tester avec d'autres trames.

## Programme final

??? success "Solution"

    ![Yippee-ki-yay](../images/meme/looking-john.gif)