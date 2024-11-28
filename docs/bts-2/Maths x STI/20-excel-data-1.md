# 02 - Valorisation de la donnée

## Open data

L’open data désigne un mouvement, né en Grande-Bretagne et aux États-Unis, d’ouverture et de mise à disposition des données produites et collectées par les services publics (administrations, collectivités locales...). *(CNIL)*

Quelques exemples en France :

+   [Données ouvertes de l'Etat](https://www.data.gouv.fr/fr/){target="_blank"}

+   [Données ouvertes du département de la Mayenne](https://data.lamayenne.fr/){target="_blank"}

+   [Données ouvertes de la SNCF](https://ressources.data.sncf.com/){target="_blank"}

## Calculs d'indicateurs avec Excel

Nous allons utiliser une source de données Open Data pour calculer des indicateurs à l'aide de Microsoft Excel (1).
{ .annotate }

1.  Transposables dans d'autres tableurs, bien sûr...

Les premiers exercices utiliseront le fichier suivant : [Défibrillateurs en Mayenne](https://data.lamayenne.fr/explore/dataset/225300011_geodae_defibrillateurs_mayenne/information/){target="_blank"}.

1.  Dans l'onglet Export, télécharger le jeu de données Excel (1).
    { .annotate }

    1.  Pour un développement ou si le client lourd d'Excel est disponible, privilégier les sources en CSV (meilleure fiabilité par rapport à l'encodage, au format des données...).  

2.  Ouvrir le fichier à l'aide d'[Excel 365](https://www.microsoft365.com/launch/excel).

3.  Nommer l'onglet courant "data".

4.  Sélectionner l'ensemble des données.

5.  Dans le ruban, sur l'onglet **Accueil**, cliquer sur le bouton **Trier et filtrer** et sélectionner **Filtrer**

6.  Les entêtes des colonnes proposent maintenant des options de filtres et de tris bien pratiques 👍 

### 🧮 En utilisant des formules

!!! note "Faîtes valider chaque indicateur calculé par un professeur."

!!! warning "Les icones :material-plus-circle: en bout de ligne donnent des indices, chercher un peu par vous même avant de les consulter 🙈"

1.  Créer un nouvel onglet "Indicateurs".

2.  Calculer les indicateurs suivants :

    +   Nombre de Défibrillateurs externes automatisés (DAE) en tout dans le fichier(1)
        { .annotate }
        1.  Utiliser la formule `NB()`.

    +   Nombre de DAE en extérieur(1)
        { .annotate }
        1.  Utiliser la formule `NB.SI()`.
    
    +   Nombre de DAE à Laval
    
    +   Nombre de DAE à Chateau-Gontier(1)
        { .annotate }
        1.  ⚠️ Chateau-Gontier est écrit de plusieurs façons. 
            
            Utiliser la formule `NB.SI.ENS()`.
    
    +   Nombre de DAE en extérieur à Laval

3.  Les indicateurs suivants vous demanderont d'*enrichir* les données de nouvelles colonnes. 

    ⚠️ Veillez à ne pas détériorer votre jeu de données.

    +   Nombre de DAE disponibles le mardi(1)
        { .annotate }
        1.  Utiliser les formules `FRACTIONNER.TEXTE()`.

    +   Est-ce qu'il y a un DAE rue Crossardière ?(1)
        { .annotate }
        1.  Utiliser les formules `RECHERCHEV()`, `ESTNA()` et `SI()`.

    +   Est-ce qu'il y a un DAE rue de la Libération à Grez-en-Bouère ?

    +   Est-ce qu'il y a un DAE rue de Nantes à Cossé-le-Vivien ?

4.  Créer un nouvel onglet "Localisation".

    Quel est le DAE le plus proche des coordonnées ci-après (Souvenir de BTS 1 ⏰) ?

    +   48.07430141009146, -0.7680929238111576

        +   le 21/11/2024 à 11:00

        +   le 24/11/2024 à 13:00

    ??? question "Comment calculer la distance entre points du globe à partir de leurs coordonnées 🌍 GPS 🛰️  ?"

        La distance d entre deux points A et B sera calculée en utilisant la formule suivante :

        \begin{split}
        &x=(longitudeB-longitudeA)\times\cos(\frac{latitudeA+latitudeB}{2}) \\
        &y=latitudeB-latitudeA \\
        &d=\sqrt{x^2+y^2}\times6371
        \end{split}

        Notes : 
        
        +   Dans cette formule, les latitudes et longitudes sont exprimées en **radians**. 
        
        +   6371 correspond au rayon de la terre en km.