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

+ [x] Lire un fichier CSV en C 📄

    + [x] Lire un fichier texte ligne par ligne

    + [x] Séparer les données de chaque ligne suivant un séparateur (token)

+ [x] Décoder une trame NMEA 🛰️

    + [x] Vérifier le checksum
    
    + [x] Récupérer l'heure

    + [x] Récupérer et convertir la latitude et la longitude en degrés décimaux

+ [x] Calculer la date 📆

+ [x] Calculer une distance à vol d'oiseau à partir de coordonnées GPS 🕊️

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

+ [x] Ecrire un fichier CSV en C ✏️

## Conception

Liste des fonctions à développer : 

```c
bool verifierChecksum(char * trame);
void extraireInfoNMEA(char * trame, char * heure, char * latitude, char * longitude);
int extraireHeure(char * heure);
float convertirEnDegres(char * coordonnees);
float calculerDistance(float latitude, float longitude);
void export(int jour, char * heure, float latitude, float longitude, float distance);
```

## Solution

??? success "Vérification du checksum"

    ```c
    /**
    * @brief Vérifie le checksum d'une trame NMEA
    * 
    * @param trame La trame NMEA à vérifier
    * @return true     Si le checksum est bon :)
    * @return false    Si le checksum n'est pas bon :(
    */
    bool verifierChecksum(char * trame) {
        int i, checksumCalcule = 0, checksumLu = 0;
        char * fin;
        
        // On fait un xor cumulé de chaque caractère entre $ et *
        for (i = 1; trame[i] != '*'; i++) {
            checksumCalcule ^= trame[i];
        }
        
        i++;
        checksumLu = strtol(trame + i, &fin, 16);
        
        return checksumCalcule == checksumLu;
    }
    ```

??? success "Extraction des valeurs de la trame NMEA"

    Deux versions possibles :

    +   En parcourant la trame caractère par caractère :

    ```c
    /**
    * @brief (Version 1) Extrait l'heure, la latitude et la longitude d'une trame NMEA
    *                    en parcourant la chaîne caractère par caractère.
    * @param trame      (entrée) La trame contenant les données à extraire
    * @param heure      (sortie) L'heure extraite
    * @param latitude   (sortie) La latitude extraite
    * @param longitude  (sortie) La longitude extraite
    */
    void extraireInfoNMEA1(char * trame, char * heure, char * latitude, char * longitude) {
        
        // On compte les points-virgules rencontrés et recopie les valeurs qui nous intéressent
        int virgule = 0;
        char * lat = latitude + 1, * lng = longitude + 1;
        for (int i = 0; trame[i] != '\0'; i++) {
            if (trame[i] == ',') {
                virgule++;
            }
            else if (virgule == 1) {
                *heure = trame[i];
                heure++;
            }
            else if (virgule == 2) {
                *lat = trame[i];
                lat++;
            }
            else if (virgule == 3) {
                *latitude = '+';
                if (trame[i] == 'S') {
                    *latitude = '-';
                }
            }
            else if (virgule == 4) {
                *lng = trame[i];
                lng++;
            }
            else if (virgule == 5) {
                *longitude = '+';
                if (trame[i] == 'W') {
                    *longitude = '-';
                }
            }
        }
    }
    ```

    +   En utilisant la fonction `strtok()` :

    ```c
    #include <string.h>

    /**
    * @brief (Version 2) Extrait l'heure, la latitude et la longitude d'une trame NMEA
    *                    en utilisant strtok().
    * @param trame      (entrée) La trame contenant les données à extraire
    * @param heure      (sortie) L'heure extraite
    * @param latitude   (sortie) La latitude extraite
    * @param longitude  (sortie) La longitude extraite
    */
    void extraireInfoNMEA2(char * trame, char * heure, char * latitude, char * longitude) {
        char * valeur = strtok(trame, ",");
        for (int i = 0; valeur != NULL; i++) {
            if (i == 1) {
                strcpy(heure, valeur);
            }
            else if (i == 2) {
                strcpy(latitude + 1, valeur);
            }
            else if (i == 3) {
                latitude[0] = '+';
                if (strcmp(valeur, "S") == 0) {
                    latitude[0] = '-';
                }
            }
            else if (i == 4) {
                strcpy(longitude + 1, valeur);
            }
            else if (i == 5) {
                longitude[0] = '+';
                if (strcmp(valeur, "W") == 0) {
                    longitude[0] = '-';
                }
            }
            valeur = strtok(NULL, ",");
        }
    }
    ```

??? success "Extraction de l'heure (pour vérifier si on change de jour)"

    ```c
    #include <stdlib.h>

    /**
    * @brief Extrait et convertit en entier l'heure d'une trame NMEA 
    * 
    * @param heure L'heure (format NMEA)
    * @return int  L'heure en entier
    */
    int extraireHeure(char * heure) {
        char heures[3] = "";
        strncpy(heures, heure, 2);
        return atoi(heures);
    }
    ```

??? success "Conversion des coordonnées en degrés décimaux"

    ```c
    #include <stdlib.h>

    /**
    * @brief Convertit en degrés décimaux une coordonnée en dix millièmes de degrés
    * 
    * @param coordonnee Une coordonnée en dix millièmes de degrés (latitude ou longitude)
    * @return double    La coordonnée en degrés décimaux
    */
    double convertirEnDegres(char * coordonnee) {
        double brut = 0, degres = 0, minutes = 0;
        brut = atof(coordonnee);
        degres = (int)(brut / 100);
        minutes = brut - degres * 100;
        return degres + minutes / 60;
    }
    ```

??? success "Calculer la distance entre deux points avec leurs coordonnées"

    ```c
    #define _USE_MATH_DEFINES 1
    #include <math.h>

    /**
    * @brief Calculer la distance (à vol d'oiseau) entre deux points A et B en utilisant leurs coordonnées GPS
    * 
    * @param latitudeA     Latitude du point A
    * @param longitudeA    Longitude du point A 
    * @param latitudeB     Latitude du point B 
    * @param longitudeB    Longitude du point B 
    * @return double       Distance en mètres entre les deux points
    */
    double calculerDistance(double latitudeA, double longitudeA, double latitudeB, double longitudeB) {
        
        // Conversion en radian
        latitudeA   = latitudeA     * M_PI /180;
        longitudeA  = longitudeA    * M_PI /180;
        latitudeB   = latitudeB     * M_PI /180;
        longitudeB  = longitudeB    * M_PI /180;
        
        // Calcul
        return sqrt(pow((longitudeB - longitudeA) * cos((latitudeB + latitudeA) / 2), 2) + pow(latitudeB - latitudeA, 2)) * 6371000;
    }
    ```

??? success "Exporter les données"

    ```c
    #include <stdio.h>

    /**
    * @brief Exporte les données au format csv
    * 
    * @param jour      le jour
    * @param heure     l'heure
    * @param latitude  la latitude
    * @param longitude la longitude
    * @param distance  la distance
    */
    void export(int jour, char * heure, double latitude, double longitude, double distance) {
        char h[3] = "", m[3] = "", s[3] = "";
        
        // Ouverture du fichier pour ajout
        FILE * fichier_sortie = fopen("eloignement.csv", "a");
        if (fichier_sortie == NULL) {
            puts("ERREUR : Ouverture du fichier impossible !");
            exit(-1);
        }
        
        // Découpage de l'heure
        strncpy(h, heure, 2);
        strncpy(m, heure + 2, 2);
        strncpy(s, heure + 4, 2);

        // Ecriture de la ligne
        fprintf(fichier_sortie, "%02d/11/2024;%s:%s:%s;%.9f;%.9f;%.0f\n", jour, h, m, s, latitude, longitude, distance);

        // Fermeture du fichier
        fclose(fichier_sortie);
    }
    ```

??? danger "Programme final"

    Utilisation : 

    ```
    > gcc .\fichier.c -o eloignement.exe
    > .\eloignement.exe gruber_20241126.log 48.06422560225566 -0.7801964890109019
    ```

    ```c
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #define _USE_MATH_DEFINES 1
    #include <math.h>

    bool    verifierChecksum(char * trame);
    void    extraireInfoNMEA1(char * trame, char * heure, char * latitude, char * longitude);
    void    extraireInfoNMEA2(char * trame, char * heure, char * latitude, char * longitude);
    int     extraireHeure(char * heure);
    double  convertirEnDegres(char * coordonnee);
    double  calculerDistance(double latitudeA, double longitudeA, double latitudeB, double longitudeB);
    void    export(int jour, char * heure, double latitude, double longitude, double distance);

    int main(int argc, char ** argv) {

        char fichierChemin[500], ligne[100] = "", heureTexte[11] = "", latitudeTexte[13] = "", longitudeTexte[14] = "";
        int heureCourante, heurePrecedente = 0, jour = 1;
        double latitude, longitude, distance, latitudeDomicile, longitudeDomicile;
        FILE * fichierEntree, * fichierSortie;

        // Vérification des arguments
        if (argc < 4) {
            puts("ERREUR : eloignement.exe fichier.log latitude longitude");
            return -1;
        }

        // Récupération des arguments
        strcpy(fichierChemin, argv[1]);
        latitudeDomicile = atof(argv[2]);
        longitudeDomicile = atof(argv[3]);
        
        // Ouverture du fichier contenant les géolocalisations
        fichierEntree = fopen(fichierChemin, "r");
        if (fichierEntree == NULL) {
            printf("ERREUR : Ouverture du fichier \"%s\" impossible !", fichierChemin);
            return -2;
        }

        // Première ouverture du fichier de sortie
        fichierSortie = fopen("eloignement.csv", "w");
        if (fichierSortie == NULL) {
            puts("ERREUR : Ouverture du fichier d'export impossible !");
            exit(-1);
        }
        fclose(fichierSortie);
        
        // Lecture et traitement ligne à ligne
        while (fgets(ligne, 100, fichierEntree) != NULL) {
            if (verifierChecksum(ligne)) {
                extraireInfoNMEA1(ligne, heureTexte, latitudeTexte, longitudeTexte);
                heureCourante = extraireHeure(heureTexte);
                if (heureCourante < heurePrecedente) {
                    jour++;
                }
                latitude = convertirEnDegres(latitudeTexte);
                longitude = convertirEnDegres(longitudeTexte);
                distance = calculerDistance(latitude, longitude, latitudeDomicile, longitudeDomicile);
                //if (distance < 500) {
                    export(jour, heureTexte, latitude, longitude, distance);
                //}
            }
            heurePrecedente = heureCourante;
        }
        
        // Fermeture du fichier
        fclose(fichierEntree);

        // Ouverture du fichier d'export
        system("notepad.exe eloignement.csv");

        return 0;
    }

    /**
    * @brief Vérifie le checksum d'une trame NMEA
    * 
    * @param trame La trame NMEA à vérifier
    * @return true     Si le checksum est bon :)
    * @return false    Si le checksum n'est pas bon :(
    */
    bool verifierChecksum(char * trame) {
        int i, checksumCalcule = 0, checksumLu = 0;
        char * fin;
        for (i = 1; trame[i] != '*'; i++) {
            checksumCalcule ^= trame[i];
        }
        i++;
        checksumLu = strtol(trame + i, &fin, 16);
        return checksumCalcule == checksumLu;
    }

    /**
    * @brief (Version 1) Extrait l'heure, la latitude et la longitude d'une trame NMEA
    *                    en parcourant la chaîne caractère par caractère.
    * @param trame      (entrée) La trame contenant les données à extraire
    * @param heure      (sortie) L'heure extraite
    * @param latitude   (sortie) La latitude extraite
    * @param longitude  (sortie) La longitude extraite
    */
    void extraireInfoNMEA1(char * trame, char * heure, char * latitude, char * longitude) {
        int virgule = 0;
        char * lat = latitude + 1, * lng = longitude + 1;
        for (int i = 0; trame[i] != '\0'; i++) {
            if (trame[i] == ',') {
                virgule++;
            }
            else if (virgule == 1) {
                *heure = trame[i];
                heure++;
            }
            else if (virgule == 2) {
                *lat = trame[i];
                lat++;
            }
            else if (virgule == 3) {
                *latitude = '+';
                if (trame[i] == 'S') {
                    *latitude = '-';
                }
            }
            else if (virgule == 4) {
                *lng = trame[i];
                lng++;
            }
            else if (virgule == 5) {
                *longitude = '+';
                if (trame[i] == 'W') {
                    *longitude = '-';
                }
            }
        }
    }

    /**
    * @brief (Version 2) Extrait l'heure, la latitude et la longitude d'une trame NMEA
    *                    en utilisant strtok().
    * @param trame      (entrée) La trame contenant les données à extraire
    * @param heure      (sortie) L'heure extraite
    * @param latitude   (sortie) La latitude extraite
    * @param longitude  (sortie) La longitude extraite
    */
    void extraireInfoNMEA2(char * trame, char * heure, char * latitude, char * longitude) {
        char * valeur = strtok(trame, ",");
        for (int i = 0; valeur != NULL; i++) {
            if (i == 1) {
                strcpy(heure, valeur);
            }
            else if (i == 2) {
                strcpy(latitude + 1, valeur);
            }
            else if (i == 3) {
                latitude[0] = '+';
                if (strcmp(valeur, "S") == 0) {
                    latitude[0] = '-';
                }
            }
            else if (i == 4) {
                strcpy(longitude + 1, valeur);
            }
            else if (i == 5) {
                longitude[0] = '+';
                if (strcmp(valeur, "W") == 0) {
                    longitude[0] = '-';
                }
            }
            valeur = strtok(NULL, ",");
        }
    }

    /**
    * @brief Extrait et convertit en entier l'heure d'une trame NMEA 
    * 
    * @param heure L'heure (format NMEA)
    * @return int  L'heure en entier
    */
    int extraireHeure(char * heure) {
        char heures[3] = "";
        strncpy(heures, heure, 2);
        return atoi(heures);
    }

    /**
    * @brief Convertit en degrés décimaux une coordonnée en dix millièmes de degrés
    * 
    * @param coordonnee Une coordonnée en dix millièmes de degrés (latitude ou longitude)
    * @return double    La coordonnée en degrés décimaux
    */
    double convertirEnDegres(char * coordonnee) {
        double brut = 0, degres = 0, minutes = 0;
        brut = atof(coordonnee);
        degres = (int)(brut / 100);
        minutes = brut - degres * 100;
        return degres + minutes / 60;
    }

    /**
    * @brief Calculer la distance (à vol d'oiseau) entre deux points A et B en utilisant leurs coordonnées GPS
    * 
    * @param latitudeA     Latitude du point A
    * @param longitudeA    Longitude du point A 
    * @param latitudeB     Latitude du point B 
    * @param longitudeB    Longitude du point B 
    * @return double       Distance en mètres entre les deux points
    */
    double calculerDistance(double latitudeA, double longitudeA, double latitudeB, double longitudeB) {
        latitudeA   = latitudeA     * M_PI /180;
        longitudeA  = longitudeA    * M_PI /180;
        latitudeB   = latitudeB     * M_PI /180;
        longitudeB  = longitudeB    * M_PI /180;
        return sqrt(pow((longitudeB - longitudeA) * cos((latitudeB + latitudeA) / 2), 2) + pow(latitudeB - latitudeA, 2)) * 6371000;
    }

    /**
    * @brief Exporte les données au format csv
    * 
    * @param jour      le jour
    * @param heure     l'heure
    * @param latitude  la latitude
    * @param longitude la longitude
    * @param distance  la distance
    */
    void export(int jour, char * heure, double latitude, double longitude, double distance) {
        char h[3] = "", m[3] = "", s[3] = "";
        
        FILE * fichier_sortie = fopen("eloignement.csv", "a");
        
        if (fichier_sortie == NULL) {
            puts("ERREUR : Ouverture du fichier impossible !");
            exit(-1);
        }
        
        strncpy(h, heure, 2);
        strncpy(m, heure + 2, 2);
        strncpy(s, heure + 4, 2);
        
        fprintf(fichier_sortie, "%02d/11/2024;%s:%s:%s;%.9f;%.9f;%.0f\n", jour, h, m, s, latitude, longitude, distance);

        fclose(fichier_sortie);
    }
    ```