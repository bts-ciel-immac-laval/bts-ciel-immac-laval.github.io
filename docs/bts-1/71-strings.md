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

    + [X] Séparer les données de chaque ligne suivant un séparateur (token)

+ [X] Décoder une trame NMEA 🛰️

    + [X] Vérifier le checksum
    
    + [X] Récupérer l'heure

    + [X] Récupérer et convertir la latitude et la longitude en degrés décimaux

+ [X] Calculer la date 📆

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

    Solution avec un tableau de tableau qui récupère toutes les valeurs (quand on veut tout récupérer) :

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

    Solution avec des variables différenciées (quand on ne veut récupérer que certaines valeurs)

    ```c
    #include <stdio.h>
    #include <string.h>

    int main() {

        char ligne[] = "$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E";
        char heure[11], latitude[12], longitude[13], ns[2], we[2];
        int i = 0;
        char * valeur = NULL;
        
        valeur = strtok(ligne, ",");
        for (int i = 1; valeur != NULL; i++) {
            switch(i) {
                case 2 : strcpy(heure, valeur);     break;
                case 3 : strcpy(latitude, valeur);  break;
                case 4 : strcpy(ns, valeur);        break;
                case 5 : strcpy(longitude, valeur); break;
                case 6 : strcpy(we, valeur);        break;
            }
            valeur = strtok(NULL, ",");
        }

        puts(heure);
        puts(latitude);
        puts(ns);
        puts(longitude);
        puts(we);
        
        return 0;
    }
    ```

:octicons-arrow-right-16: Transformer ce programme en fonction, la stocker dans une bibliothèque `experts.h` et tester avec d'autres trames.

??? success "Code en C"

    :octicons-file-16: `experts.h`

    ```c
    // [...]
    #include <string.h>

    // [...]
    void extraireValeurs(char *, char *, char *, char *, char *, char*);

    // [...]
    void extraireValeurs(char * ligne, char * heure, char * latitude, char * ns, char * longitude, char* we) {
        char * valeur = NULL;
        
        valeur = strtok(ligne, ",");
        for (int i = 1; valeur != NULL; i++) {
            switch(i) {
                case 2 : strcpy(heure, valeur);     break;
                case 3 : strcpy(latitude, valeur);  break;
                case 4 : strcpy(ns, valeur);        break;
                case 5 : strcpy(longitude, valeur); break;
                case 6 : strcpy(we, valeur);        break;
            }
            valeur = strtok(NULL, ",");
        }
    }
    ```

    :octicons-file-16: `experts.c`

    ```c
    #include "experts.h"

    int main() {

        char trame[] = "$GPGGA,080104.555,4804.656727,N,00047.507355,W,1,04,3.8,88.27,M,,,,,0000*3E";
        char heureTxt[11], latitudeTxt[12], longitudeTxt[13], ns[2], we[2];
        
        extraireValeurs(trame, heureTxt, latitudeTxt, ns, longitudeTxt, we);

        puts(heureTxt);
        puts(latitudeTxt);
        puts(ns);
        puts(longitudeTxt);
        puts(we);
        
        return 0;
    }
    ```


### Convertir les données lues

Créer une fonction pour chacune des conversions suivantes :

+   Passer d'une heure au format `hhmmss.sss` au format `hh:mm:ss`

    ??? success "Code en C"

        ```c
        void convertirHeure(char * nmea, char * resultat) {
            sprintf(resultat, "%c%c:%c%c:%c%c", nmea[0], nmea[1], nmea[2], nmea[3], nmea[4], nmea[5]);
        }
        ```

+   Passer d'une coordonnée au format DDDMM.MMMMMM + N/S ou E/W au format (-)DDD.DDDDDD

    ??? success "Code en C"

        ```c
        float convertirCoordonnees(char * coordonnee, char * direction) {
            char * point = NULL, degres[4] = "";
            float resultat;
            
            // Recupération des degrés
            point = strchr(coordonnee, '.');
            strncpy(degres, coordonnee, point - coordonnee - 2);
            resultat = atof(degres);
            
            // Extraction des minutes et conversion en degrés
            resultat += atof(point - 2) / 60;

            // Gestion de la direction
            if (*direction == 'S' || *direction == 'W') {
                resultat *= -1;
            }
            
            return resultat;
        }
        ```

### Calculer une distance à vol d'oiseau

Créer une fonction qui calcule la distance à vol d'oiseau entre deux points à partir de leurs coordonnées GPS (en degrés décimaux).

??? info "Indice"

    ![look up](../images/meme/looking-up.gif)

    J'ai l'impression qu'on se répète...

??? success "Code en C"

    ```c
    // Bibliothèque pour obtenir PI, cos, pow et sqrt
    #define _USE_MATH_DEFINES
    #include <math.h>

    float convertirDegresEnRadians(float);
    float calculerDistance(float, float, float, float);

    int main() {

        printf("%f\n", calculerDistance(48.07429936102162, -0.7680080793209888, 48.07352056412836, -0.7723579441783978)); 
        
        // 334,87m d'après Google Maps
        
        return 0;
    }

    float convertirDegresEnRadians(float angle) {
        return angle * M_PI / 180;
    }

    float calculerDistance(float latA, float lngA, float latB, float lngB) {
        float distance = 0;

        // Conversion en radian
        latA = convertirDegresEnRadians(latA);
        lngA = convertirDegresEnRadians(lngA);
        latB = convertirDegresEnRadians(latB);
        lngB = convertirDegresEnRadians(lngB);

        // Calcul de la distance
        return sqrt(pow((lngB - lngA) * cos((latA + latB) / 2), 2) + pow(latB - latA, 2)) * 6371 * 1000;
    }
    ```

## Première intégration

A partir de la bibliothèque `experts.h` suivante, créer un programme qui lit le fichier `gruber_20241126.log` et affiche pour les trames valides dont la distance avec le domicile de Mme H.GENNERO est inférieure à 500 m :

+   Date (`jj/mm/aaaa`),
+   Heure (`hh:mm:ss`),
+   Les coordonnées GPS en degrés décimaux (`DD.DDDDDD`),
+   La distance à vol d'oiseau calculée en mètres (`m`).

[:material-file-download: Télécharger la bibliothèque experts.h](../files/bts1/experts.h){ .md-button .md-button--primary }

??? success "Première version"

    :octicons-file-16: `experts.h`

    On choisit de traiter le fichier ligne à ligne, tout le traitement va donc être réalisé dans la fonction `lireFichier`.

    ```c
    void lireFichier(char * cheminFichier) {
        char ligne[100], nmeaHeure[10], nmeaLatitude[12], nmeaNS[2], nmeaLongitude[13], nmeaWS[2], heure[9], date[] = "01/11/2024";
        float latitude, longitude, distance;
        int heureCourante, heurePrecedente = 0;

        FILE * fichier = NULL;
        
        fichier = fopen(cheminFichier, "r");
        if (fichier == NULL) {
            puts("Erreur lors de l'ouverture en lecture du fichier de log");
            exit(-1);
        }
        
        // Pour chaque ligne...
        while (fgets(ligne, 100, fichier) != NULL) {
            
            // ...on vérifie le checksum...
            if (verifierChecksumNMEA(ligne)) {
                
                // ...on extrait les valeurs...
                extraireValeurs(ligne, nmeaHeure, nmeaLatitude, nmeaNS, nmeaLongitude, nmeaWS);
                
                // ...convertit l'heure en texte...
                convertirHeure(nmeaHeure, heure);

                // ...puis en entier pour voir si on a changé de journée et gérer la date...
                heureCourante = extraireHeure(heure);
                if (heureCourante < heurePrecedente) {
                    incrementerDate(date);
                }
                heurePrecedente = heureCourante;

                // ...puis on convertit les coordonnées...
                latitude = convertirCoordonnees(nmeaLatitude, nmeaNS);
                longitude = convertirCoordonnees(nmeaLongitude, nmeaWS);

                // ...pour calculer la distance...
                distance = calculerDistance(48.06410268512942, -0.7801647985752476, latitude, longitude);

                // ...pour enfin vérifier si elle est inférieure à 500 m...
                if (distance < 500) {

                    // finalement on affiche les informations demandées
                    printf("%s %s (%f, %f) %f m\n", date, heure, latitude, longitude, distance);
                }
            }
        }
        
        fclose(fichier);
    }
    ```

    :octicons-file-16: `experts.c`

    La fonction principale se résume à un appel à la fonction `lireFichier`.

    ```c
    #include "experts.h"

    int main() {

        lireFichier("gruber_20241126.log");
        
        return 0;
    }
    ```

## Suite et fin

### Générer un fichier texte

Réaliser les exercices suivants :

+   Créer une fonction qui crée un fichier `exo1.txt` et le remplit en **une seule fois** avec une phrase passée en paramètre. 

    La tester avec la phrase :
    
        Le courage n'est pas l'absence de peur, mais la capacité de vaincre ce qui fait peur.

    ??? success "Solution"

        ```c
        #include <stdio.h>
        #include <stdlib.h>

        void exo1(char * chaine) {
            FILE * fichier = NULL;

            fichier = fopen("exo1.txt", "w");

            if (fichier == NULL) {
                puts("Exo 1 - Erreur lors de l'ouverture.");
                exit(-1);
            }

            fputs(chaine, fichier);

            fclose(fichier);
        }

        int main() {
            exo1("Le courage n'est pas l'absence de peur, mais la capacité de vaincre ce qui fait peur.");

            return 0;
        }
        ```

+   Créer une fonction qui crée un fichier `exo2.txt` et le remplit **5 caractères par 5 caractères** avec une phrase passée en paramètre.

    La tester avec la phrase :
    
        Quand on veut on peut, quand on peut on doit.

    ??? success "Solution"

        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        void exo2(char * chaine) {
            FILE * fichier = NULL;
            int i = 0;

            fichier = fopen("exo2.txt", "w");

            if (fichier == NULL) {
                puts("Exo 2 - Erreur lors de l'ouverture.");
                exit(-1);
            }

            // Par soucis de généricité, pour ne pas dépasser la longueur 
            // de la chaîne pour les chaines dont la taille n'est pas un 
            // multiple de 5, on s'arrête 5 caractères avant la fin.
            for (i = 0; i < strlen(chaine) - 5; i += 5) {
                fwrite(chaine + i, sizeof(char), 5, fichier);
            }

            // On écrit finalement le reliquat (de 1 à 5 caractères)
            fwrite(chaine + i, sizeof(char), strlen(chaine) - i, fichier);

            fclose(fichier);
        }

        int main() {
            exo2("Quand on veut o123n peut, quand on peut on doit.");

            return 0;
        }
        ```

+   Créer une fonction qui crée un fichier `exo3.txt` et le remplit **caractère par caractère** avec une phrase passée en paramètre.

    La tester avec le texte :

        Entre :
        Ce que je pense,
        Ce que je veux dire, 
        Ce que je crois dire, 
        Ce que je dis, 
        Ce que vous avez envie d'entendre, 
        Ce que vous entendez, 
        Ce que vous comprenez... 
        Il y a dix possibilités qu'on ait des difficultés à communiquer. 
        Mais essayons quand même...

    ??? success "Solution"

        ```c
        #include <stdio.h>
        #include <stdlib.h>

        void exo3(char * chaine) {
            FILE * fichier = NULL;
            int i = 0;

            fichier = fopen("exo2.txt", "w");

            if (fichier == NULL) {
                puts("Exo 3 - Erreur lors de l'ouverture.");
                exit(-1);
            }

            // On parcourt la chaine caractère par caractère
            for (int i = 0; chaine[i] != '\0'; i++) {
                fputc(chaine[i], fichier);
            }

            fclose(fichier);
        }

        int main() {
            exo3("Entre :\nCe que je pense,\nCe que je veux dire,\nCe que je crois dire,\nCe que je dis,\nCe que vous avez envie d'entendre,\nCe que vous entendez,\nCe que vous comprenez..\nIl y a dix possibilités qu'on ait des difficultés à communiquer.\nMais essayons quand même...");

            return 0;
        }
        ```

+   Créer une fonction qui crée un fichier `exo4.csv` (séparateur : tabulation) et le remplit avec les valeurs de 3 tableaux passées en paramètres.

    La tester avec les tableaux suivants :

        [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]

        [ 1.2, 3.4, 5.6, 6.7, 8.9, 0.1, 2.3, 4.5, 6.7, 8.9 ]

        [ Archibald, Tryphon, Piotr, Bianca, Tchang, Abdallah, Roberto, Séraphin, Allan, Oliveira ]

    ??? success "Solution"

        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        // Les tableaux multidimensionnels dont la mémoire a été réservée dans la pile doivent être passés avec l'écriture tableau
        void exo4(int * a1, float * a2, char a3[10][10], int n) {
            FILE * fichier = NULL;

            fichier = fopen("exo4.csv", "w");

            if (fichier == NULL) {
                puts("Exo 4 - Erreur lors de l'ouverture.");
                exit(-1);
            }

            for (int i = 0; i < n; i++) {
                fprintf(fichier, "%d\t%f\t%s\n", a1[i], a2[i], a3[i]);
            }

            fclose(fichier);
        }

        int main() {

            int   tab1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            float tab2[10] = { 1.2, 3.4, 5.6, 6.7, 8.9, 0.1, 2.3, 4.5, 6.7, 8.9 };
            char  tab3[10][10] = { "Archibald", "Tryphon", "Piotr", "Bianca", "Tchang", "Abdallah", "Roberto", "Séraphin", "Allan", "Oliveira" };
            
            exo4(tab1, tab2, tab3, 10);

            return 0;
        }
        ```

### Rendre le programme générique

<object class="fullScreenAble" data="../../pdf/cours/bts1/bts1_10_argc-argv.pdf" type="application/pdf"></object>

Créer un programme qui prend 4 paramètres d'entrées : 

+   le chemin d'un fichier

+   une date au format jj/mm/aaaa

+   la latitude et la longitude en degrés décimaux d'une coordonnée GPS

Le programme vérifie la présence des paramètres, convertit les coordonnées et affiche les paramètres à l'écran.

Exemple :

```
> param.exe ../eyjafjallajokull.txt 20/03/2010 63.63528391052931 -19.606861438578065
../eyjafjallajokull.txt
20/03/2010 
63.63528391052931 
-19.606861438578065
```

??? warning "Déboguer avec des arguments en ligne de commande avec VS Code"

    Utiliser le fichier .vscode/launch.json suivant (à la racine du projet dans VS Code) en modifiant les valeurs surlignés pour correspondre à votre environnement :

    ```json hl_lines="10 16"
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "gcc.exe - Build and debug active file",
                "type": "cppdbg",
                "request": "launch",
                "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
                "args": [
                    "Mathieu"
                ],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "MIMode": "gdb",
                "miDebuggerPath": "C:\\projects\\mingw64\\bin\\gdb.exe",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    },
                    {
                        "description": "Set Disassembly Flavor to Intel",
                        "text": "-gdb-set disassembly-flavor intel",
                        "ignoreFailures": true
                    }
                ],
                "preLaunchTask": "C/C++: gcc.exe build active file"
            }
        ]
    }
    ```

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char ** argv) {

        float lat, lng;

        if (argc < 5) {
            puts("Nombre de paramètres insuffisant :\n>param.exe chemin_fichier date latitude longitude");
            return -1;
        }

        lat = atof(argv[3]);
        lng = atof(argv[4]);

        printf("%s\n%s\n%.14f\n%.14f\n", argv[1], argv[2], lat, lng);

        return 0;
    }
    ```

## Intégration finale

A partir des derniers travaux, reprendre la première intégration et terminer le programme avec les fonctionnalités suivantes :

+   exportation des résultats dans un fichier csv

    
    ??? success "Solution intermédiaire"

        On modifie *légérement* la fonction `lireFichier` pour intégrer l'écriture dans le fichier :

        ```c  hl_lines="13 23 24 25 26 27 59 68"
        /**
        * @brief Ouvre en lecture, analyse et exporte les données des lignes du fichier log qui contreviennent à la mesure d'éloignement.
        *        
        *        ⚠️ En cas d'erreur lors de l'ouverture des fichiers, interrompt le programme.
        * 
        * @param cheminFichier Le chemin (relatif ou absolu) du fichier log à lire.
        */
        void lireFichier(char * cheminFichier) {
            char ligne[100], nmeaHeure[10], nmeaLatitude[12], nmeaNS[2], nmeaLongitude[13], nmeaWS[2], heure[9], date[] = "01/11/2024";
            float latitude, longitude, distance;
            int heureCourante, heurePrecedente = 0;

            FILE * fichierLog = NULL, * fichierCsv = NULL;
            
            // Ouverture du fichier log en lecture
            fichierLog = fopen(cheminFichier, "r");
            if (fichierLog == NULL) {
                puts("Erreur lors de l'ouverture en lecture du fichier de log");
                exit(-1);
            }

            // Ouverture du fichier CSV en écriture
            fichierCsv = fopen("experts.csv", "w");
            if (fichierCsv == NULL) {
                puts("Erreur lors de l'ouverture en écriture du fichier csv");
                exit(-1);
            }
            
            // Pour chaque ligne...
            while (fgets(ligne, 100, fichierLog) != NULL) {
                
                // ...on vérifie le checksum...
                if (verifierChecksumNMEA(ligne)) {
                    
                    // ...on extrait les valeurs...
                    extraireValeurs(ligne, nmeaHeure, nmeaLatitude, nmeaNS, nmeaLongitude, nmeaWS);
                    
                    // ...convertit l'heure en texte...
                    convertirHeure(nmeaHeure, heure);

                    // ...puis en entier pour voir si on a changé de journée et gérer la date...
                    heureCourante = extraireHeure(heure);
                    if (heureCourante < heurePrecedente) {
                        incrementerDate(date);
                    }
                    heurePrecedente = heureCourante;

                    // ...puis on convertit les coordonnées...
                    latitude = convertirCoordonnees(nmeaLatitude, nmeaNS);
                    longitude = convertirCoordonnees(nmeaLongitude, nmeaWS);

                    // ...pour calculer la distance...
                    distance = calculerDistance(48.06410268512942, -0.7801647985752476, latitude, longitude);

                    // ...pour enfin vérifier si elle est inférieure à 500 m...
                    if (distance < 500) {

                    // finalement on écrit les informations demandées dans le fichier csv
                        fprintf(fichierCsv, "%s;%s;%.14f;%.14f;%f\n", date, heure, latitude, longitude, distance);
                    }
                }
            }
            
            // Fermeture du fichier de log
            fclose(fichierLog);

            // Fermeture et sauvegarde du fichier csv
            fclose(fichierCsv);
        }
        ```

+   programme générique pouvant prendre n'importe quel fichier de log, date de démarrage et coordonnées de domicile en entrée.

Tester.

```
> experts.exe ../gruber_20241126.log 01/11/2024 48.064132391638964, -0.7801643032709202
```

## Programme final

??? success "Solution"

    :octicons-file-16: `experts.h`
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define _USE_MATH_DEFINES
    #include <math.h>

    void lireFichier(char *, char *, float, float);
    int verifierChecksumNMEA(char *);
    void extraireValeurs(char *, char *, char *, char *, char *, char*);
    void convertirHeure(char *, char *);
    float convertirCoordonnees(char *, char *);
    float convertirDegresEnRadians(float);
    float calculerDistance(float, float, float, float);
    int extraireHeure(char *);
    void incrementerDate(char *);

    /**
    * @brief Ouvre en lecture, analyse et exporte les données des lignes du fichier log qui contreviennent à la mesure d'éloignement.
    *        
    *        ⚠️ En cas d'erreur lors de l'ouverture des fichiers, interrompt le programme.
    * 
    * @param cheminFichier Le chemin (relatif ou absolu) du fichier log à lire.
    */
    void lireFichier(char * cheminFichier, char * date, float domicileLatitude, float domicileLongitude) {
        char ligne[100], nmeaHeure[10], nmeaLatitude[12], nmeaNS[2], nmeaLongitude[13], nmeaWS[2], heure[9];
        float latitude, longitude, distance;
        int heureCourante, heurePrecedente = 0;

        FILE * fichierLog = NULL, * fichierCsv = NULL;
        
        // Ouverture du fichier log en lecture
        fichierLog = fopen(cheminFichier, "r");
        if (fichierLog == NULL) {
            puts("Erreur lors de l'ouverture en lecture du fichier de log");
            exit(-1);
        }

        // Ouverture du fichier CSV en écriture
        fichierCsv = fopen("experts.csv", "w");
        if (fichierCsv == NULL) {
            puts("Erreur lors de l'ouverture en écriture du fichier csv");
            exit(-1);
        }
        
        // Pour chaque ligne...
        while (fgets(ligne, 100, fichierLog) != NULL) {
            
            // ...on vérifie le checksum...
            if (verifierChecksumNMEA(ligne)) {
                
                // ...on extrait les valeurs...
                extraireValeurs(ligne, nmeaHeure, nmeaLatitude, nmeaNS, nmeaLongitude, nmeaWS);
                
                // ...convertit l'heure en texte...
                convertirHeure(nmeaHeure, heure);

                // ...puis en entier pour voir si on a changé de journée et gérer la date...
                heureCourante = extraireHeure(heure);
                if (heureCourante < heurePrecedente) {
                    incrementerDate(date);
                }
                heurePrecedente = heureCourante;

                // ...puis on convertit les coordonnées...
                latitude = convertirCoordonnees(nmeaLatitude, nmeaNS);
                longitude = convertirCoordonnees(nmeaLongitude, nmeaWS);

                // ...pour calculer la distance...
                distance = calculerDistance(domicileLatitude, domicileLongitude, latitude, longitude);

                // ...pour enfin vérifier si elle est inférieure à 500 m...
                if (distance < 500) {

                    // finalement on écrit les informations demandées dans le fichier csv
                    fprintf(fichierCsv, "%s;%s;%.14f;%.14f;%.0f\n", date, heure, latitude, longitude, distance);
                }
            }
        }
        
        // Fermeture du fichier de log
        fclose(fichierLog);

        // Fermeture et sauvegarde du fichier csv
        fclose(fichierCsv);
    }

    /**
    * @brief Vérifie le checksum de la trame NMEA passée en paramètre.
    * 
    * @param trame La trame à vérifier.
    * @return int 1 si le checksum est vérifié, 0 sinon.
    */
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

    /**
    * @brief Extrait d'une trame NMEA de type GPGGA et passe par adresse l'heure, la latitude, la direction de la latitude, la longitude et la direction de la longitude.
    * 
    * @param trame ⬇️ La trame NMEA source
    * @param heure ⬆️ Un pointeur vers une chaine de caractères pour recevoir l'heure en sortie.
    * @param latitude ⬆️ Un pointeur vers une chaine de caractères pour recevoir la latitude en sortie.
    * @param ns ⬆️ Un pointeur vers une chaine de caractères pour recevoir la direction de la latitude en sortie.
    * @param longitude ⬆️ Un pointeur vers une chaine de caractères pour recevoir la longitude en sortie.
    * @param we ⬆️ Un pointeur vers une chaine de caractères pour recevoir la direction de la longitude en sortie.
    */
    void extraireValeurs(char * trame, char * heure, char * latitude, char * ns, char * longitude, char* we) {
        char * valeur = NULL;
        
        valeur = strtok(trame, ",");
        for (int i = 1; valeur != NULL; i++) {
            switch(i) {
                case 2 : strcpy(heure, valeur);     break;
                case 3 : strcpy(latitude, valeur);  break;
                case 4 : strcpy(ns, valeur);        break;
                case 5 : strcpy(longitude, valeur); break;
                case 6 : strcpy(we, valeur);        break;
            }
            valeur = strtok(NULL, ",");
        }
    }

    /**
    * @brief Transforme une heure au format hhmmss.ssss au format hh:mm:ss.
    * 
    * @param nmea ⬇️ Un pointeur vers une chaine de caractères contenant une heure au format hhmmss.ssss.
    * @param resultat ⬆️ Un pointeur vers une chaine de caractères pour recevoir l'heure au format hh:mm:ss en sortie.
    */
    void convertirHeure(char * nmea, char * resultat) {
        sprintf(resultat, "%c%c:%c%c:%c%c", nmea[0], nmea[1], nmea[2], nmea[3], nmea[4], nmea[5]);
    }

    /**
    * @brief Convertit une coordonnée (latitude ou longitude) en degrés horaires (D)DDMM.MMMMMM NESW en degrés décimaux +/-(D)DD.DDDDDD 
    * 
    * @param coordonnee Un pointeur vers une chaine de caractères contenant la coordonnée en degrés horaires.
    * @param direction Un pointeur vers une chaine de caractères contenant la direction de la coordonnée (N,E,S ou W).
    * @return float La coordonnée en degrés décimaux.
    */
    float convertirCoordonnees(char * coordonnee, char * direction) {
        char * point = NULL, degres[4] = "";
        float resultat;
        
        // Recupération des degrés
        point = strchr(coordonnee, '.');
        strncpy(degres, coordonnee, point - coordonnee - 2);
        resultat = atof(degres);
        
        // Extraction des minutes et conversion en degrés
        resultat += atof(point - 2) / 60;

        // Gestion de la direction
        if (*direction == 'S' || *direction == 'W') {
            resultat *= -1;
        }
        
        return resultat;
    }

    /**
    * @brief Convertit un angle en degrés décimaux en radians
    * 
    * @param angle l'angle en degrés décimaux
    * @return float l'angle en radian
    */
    float convertirDegresEnRadians(float angle) {
        return angle * M_PI / 180;
    }

    /**
    * @brief Calcule la distance à vol d'oiseau en mètres entre un point A et un point B à partir de leurs coordonnées en degrés décimaux.
    * 
    * @param latA La latitude du point A
    * @param lngA La longitude du point A
    * @param latB La latitude du point B
    * @param lngB La longitude du point B
    * @return float La distance entre le point A et le point B en mètres
    */
    float calculerDistance(float latA, float lngA, float latB, float lngB) {
        float distance = 0;

        // Conversion en radian
        latA = convertirDegresEnRadians(latA);
        lngA = convertirDegresEnRadians(lngA);
        latB = convertirDegresEnRadians(latB);
        lngB = convertirDegresEnRadians(lngB);

        // Calcul de la distance
        return sqrt(pow((lngB - lngA) * cos((latA + latB) / 2), 2) + pow(latB - latA, 2)) * 6371 * 1000;
    }

    /**
    * @brief renvoie l'heure au format numérique extrait d'une chaine au format hh:mm:ss
    * 
    * @param texte Un pointeur vers une chaine de caractères contenant l'heure au format hh:mm:ss
    * @return int l'heure au format numérique
    */
    int extraireHeure(char * texte) {
        int resultat = 0;
        sscanf(texte, "%d:", &resultat);
        return resultat;
    }

    /**
    * @brief incrémente une date au format jj/mm/aaaa d'un jour.
    * 
    * @param date Un pointeur vers une chaine de caractères contenant la date au format jj/mm/aaaa
    */
    void incrementerDate(char * date) {
        int nbJoursParMois[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int jour, mois, annee;
        sscanf(date, "%d/%d/%d", &jour, &mois, &annee);
        nbJoursParMois[1] = (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0 ? 29 : 28;
        jour ++;
        if (jour > nbJoursParMois[mois - 1]) {
            jour = 1;
            mois++;
            if (mois > 12) {
                mois = 1;
                annee++;
            }
        }
        sprintf(date, "%02d/%02d/%04d", jour, mois, annee);
    }
    ```

    :octicons-file-16: `experts.c`

    ```c
    #include "experts.h"

    int main(int argc, char ** argv) {

        system("chcp 65001");
        system("cls");

        if (argc != 5) {
            puts("Nombre de paramètres insuffisant :\n> experts.exe chemin_fichier date latitude longitude");
            return -1;
        }

        lireFichier(argv[1], argv[2], atof(argv[3]), atof(argv[4]));
        
        return 0;
    }
    ```

    Exécution :
    
    ```
    > ./experts.exe .\gruber_20241126.log 01/01/2024 48.06410268512942, -0.7801647985752476
    ```

    Résultat :
    
    :octicons-file-16: `experts.csv` :

    ```csv
    08/01/2024;18:07:57;48.06417846679688;-0.77990198135376;21
    15/01/2024;18:44:16;48.06389999389648;-0.78000402450562;25
    18/01/2024;16:08:36;48.06420898437500;-0.78340399265289;241
    ```

    ![Yippee-ki-yay](../images/meme/looking-john.gif)