#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

void lireFichier(char *);
int verifierChecksumNMEA(char *);
void extraireValeurs(char *, char *, char *, char *, char *, char*);
void convertirHeure(char *, char *);
float convertirCoordonnees(char *, char *);
float convertirDegresEnRadians(float);
float calculerDistance(float, float, float, float);
int extraireHeure(char *);
void incrementerDate(char *);

/**
 * @brief Ouvre en lecture et affiche le contenu du fichier dont le chemin est passé en paramètre.
 *        
 *        ⚠️ En cas d'erreur lors de l'ouverture, interrompt le programme.
 * 
 * @param cheminFichier Le chemin (relatif ou absolu) du fichier à lire.
 */
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