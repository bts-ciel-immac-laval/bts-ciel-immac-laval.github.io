---
icon: material/music
---

# S'entraîner

![piano](../images/illustration/piano.jpg)

Voici quelques exercices pour t'entraîner aux basiques de la programmation en Python.

:alarm_clock:&nbsp;&nbsp;Tente de les résoudre dans le temps imparti !

## Et si je galère ?

Des difficultés 😣 ? 

Besoin de reprendre *from scratch* 💪 ?

Une bonne ressource en ligne : [https://www.france-ioi.org/algo/chapters.php](https://www.france-ioi.org/algo/chapters.php)

N'hésite pas à te créer un compte pour suivre tes progrès.

## Les exercices

:alarm_clock:&nbsp;&nbsp;Ouvrir un exercice lance le chrono !

💡 Tente de **résoudre le problème par toi-même**, et **avant** de révéler la solution, vérifie si tu as pensé à tout en déroulant le "Y as-tu pensé ?".

⛔ Dans un but pédagogique, il est bien sûr **interdit** d'utiliser les [fonctions natives](https://docs.python.org/fr/3.13/library/functions.html){target="_blank"} de Python qui réaliserait le travail demandé.

??? exo-chrono "Exercice 1<span class="chrono">05:00</span>"

    Coder la fonction `volume_boule` permettant de calculer le volume d'une boule.

    Pour rappel :

    $$
    V = \frac{4}{3}\times\pi\times r^{³}
    $$

    ??? info "Y as-tu pensé ?"

        + Quels sont les paramètres de la fonction ?

        + Si le rayon est nul ?

        + Si le rayon est négatif ? (on n'est jamais à l'abri d'une erreur de saisie 🤪)

    ??? success "Solution"

        ```py
        from math import pi

        def volume_boule(rayon : int) :
            '''
            Calcule le volume d'une boule de rayon "rayon"
            '''

            assert rayon >= 0 , "Le rayon doit être positif !"

            return 4 / 3 * pi * rayon ** 3

        # Tests
        print(volume_boule(1))          # 4.18879020
        print(volume_boule(10.607845))  # 5000.00116
        print(volume_boule(0))          # 0.0
        print(volume_boule(-5))         # Erreur d'assertion
        ```

??? exo-chrono "Exercice 2.1<span class="chrono">10:00</span>"

    Coder une fonction `multiplyArrayBy` permettant de multiplier toutes les valeurs d'une liste par un entier et qui renvoie les résultats dans une nouvelle liste.

    ??? info "Y as-tu pensé ?"

        + Si le tableau est vide ?

        + Si les valeurs de la liste ne sont pas numériques ?

    ??? success "Solution"

        ```py
        def multiplyArrayBy(liste : list, entier : int) :
            '''
            Multiplie toutes les valeurs de liste par entier et renvoie les résultats dans une nouvelle liste.
            '''
            resultats = []

            # On parcourt le tableau - première version
            for valeur in liste :

                assert type(valeur) is int or type(valeur) is float, "La liste doit contenir des valeurs numériques !"

                resultats.append(valeur * entier)

            # On parcourt le tableau - seconde version
            # for i in range(len(liste)) :
            #     assert type(liste[i]) is int or type(liste[i]) is float, "La liste doit contenir des valeurs numériques !"
            #     resultats.append(liste[i] * entier)

            return resultats

        # Tests
        print(multiplyArrayBy([1, 2, 3], 2))                # [2, 4, 6]
        print(multiplyArrayBy([-3, 7.3, 10, 1, 0], 5))      # [-15, 36.5, 50, 5, 0]
        print(multiplyArrayBy([], 42))                      # []
        print(multiplyArrayBy(['a'], 42))                   # Erreur d'assertion
        ```

??? exo-chrono "Exercice 2.2<span class="chrono">10:00</span>"

    Coder une fonction `multiplyArrayInPlaceBy` permettant de multiplier toutes les valeurs d'une liste par un entier et qui remplace les valeurs originales dans la liste par les résultats.

    ??? info "Y as-tu pensé ?"

        + Si le tableau est vide ?

        + Si les valeurs de la liste ne sont pas numériques ?

    ??? success "Solution"

        ```py
        def multiplyArrayInPlaceBy(liste : list, entier : int) :
            '''
            Multiplie toutes les valeurs de liste par entier
            '''

            # On parcourt le tableau
            # Pas le choix ici, l'accès par indice est la solution la plus "propre"
            for i in range(len(liste)) :

                assert type(liste[i]) is int or type(liste[i]) is float, "La liste doit contenir des valeurs numériques !"

                liste[i] *= entier
                # liste[i] = liste[i] * entier

            # On ne renvoie rien ici, les listes sont passées par référence en Python,
            # les modifier dans la fonction les modifie dans la fonction appelante !

        # Tests
        l = [1, 2, 3]
        multiplyArrayInPlaceBy(l, 2)
        print(l)                                        # [2, 4, 6]

        l = [-3, 7.3, 10, 1, 0]
        multiplyArrayInPlaceBy(l, 5)
        print(l)                                        # [-15, 36.5, 50, 5, 0]

        l = []
        multiplyArrayInPlaceBy(l, 42)
        print(l)                                        # []

        l = ['a', 'b', 'c']
        multiplyArrayInPlaceBy(l, 42)
        print(l)                                        # Erreur d'assertion
        ```

??? exo-chrono "Exercice 3<span class="chrono">15:00</span>"

    Coder la fonction `somme_prod` permettant de multiplier une à une les valeurs de deux listes et d'en renvoyer la somme.

    ??? info "Y as-tu pensé ?"

        + Si les tableaux sont vides ? 

        + Si les tableaux n'ont pas le même nombre d'éléments ?

        + Si les valeurs de la liste ne sont pas numériques ?

    ??? success "Solution"

        ```py
        def somme_prod(l1 : list, l2 : list) :
            '''
            Multiplie une à une les valeurs des listes l1 et l2 et en renvoie la somme
            '''

            # On initialise à 0 une variable pour stocker la somme des produits au fur et à mesure
            somme = 0

            assert len(l1) == len (l2), "Les deux listes doivent avoir le même nombre d'éléments !"

            for i in range(len(l1)) :

                assert type(l1[i]) is int or type(l1[i]) is float, "La liste 1 doit contenir des valeurs numériques !"
                assert type(l2[i]) is int or type(l2[i]) is float, "La liste 2 doit contenir des valeurs numériques !"

                somme += l1[i] * l2[i]

            return somme

        # Tests
        print(somme_prod([1, 2, 3], [1, 2, 3]))         # 14
        print(somme_prod([0.1, 2.3], [4.56, 78.9]))     # 181.926
        print(somme_prod([], []))                       # 0
        print(somme_prod([1, 2], []))                   # Erreur d'assertion
        print(somme_prod([1, 2], [1, 'a']))             # Erreur d'assertion - Commenter la ligne précédente pour la voir
        ```

??? exo-chrono "Exercice 4<span class="chrono">20:00</span>"

    Coder une fonction `saisirListe` qui demande à l'utilisateur de saisir *en une fois* une liste d'entiers séparés par des espaces, puis la renvoie sous la forme d'un tableau d'entiers.

    ??? info "Y as-tu pensé ?"

        + Si l'utilisateur ne saisit rien ?

        + As-tu convertit les entiers dans le bon type ?

    ??? success "Solution"

        ```py
        def saisirListe() :
            '''
            Demande à l'utilisateur de saisir une liste d'entiers séparés par des espaces, puis la renvoie sous la forme d'un tableau d'entiers.
            '''
            # On récupère la saisie de l'utilisateur
            saisie = input("Saisir une liste d'entiers séparés par des espaces : ")

            # Une liste pour stocker le résultat
            liste = []

            # Une chaine temporaire pour stocker les caractères lus
            temporaire = ""

            # On parcours la saisie caractere par caractere
            for caractere in saisie :

                # Si ce n'est pas un espace...
                if caractere != ' ' :
                    # ...on concatène le caractère dans une chaine temporaire
                    temporaire += caractere

                # Si c'est un espace...
                else :
                    # ...on convertit la chaine temporaire en entier et on le stocke dans la liste...
                    liste.append(int(temporaire))
                    # ...et on n'oublie pas de réinitialiser la chaine temporaire
                    temporaire = ""

            # ET on n'oublie pas le dernier (qui n'est pas suivi d'un espace...) !
            if len(temporaire) > 0 :
                liste.append(int(temporaire))

            return liste

        # Test
        print(saisirListe())

        # Saisir 1 2 3 4 5 donne : [1, 2, 3, 4, 5]
        # Saisir 12 345 donne : [12, 345]
        # Ne rien saisir donne : []
        # Saisir a b c renvoie une erreur de conversion : invalid literal for int() with base 10: 'a'
        ```

??? exo-chrono "Exercice 5.1<span class="chrono">15:00</span>"

    Coder une fonction `calculer_distance_vol_oiseau` qui calcule la distance $d$ à vol d'oiseau entre deux points $A$ et $B$ du globe à partir de leurs coordonnées GPS en utilisant la [formule de haversine](https://fr.wikipedia.org/wiki/Formule_de_haversine){target="_blank"}.

    Voici la formule :

    \begin{split}
    &d=2r\arcsin{(\sqrt{\sin^2{(\frac{\varphi_B - \varphi_A}{2})}+\cos{(\varphi_A)}\cos{(\varphi_B)}\sin^2{(\frac{\lambda_B - \lambda_A}{2})}})}
    \end{split}

    où :

    + $r$ est le rayon de la terre : 6371 km,

    + $\varphi_A$ et $\varphi_B$ sont les latitudes des points A et B,

    + $\lambda_A$ et $\lambda_B$ sont les longitudes des points A et B,

    + les latitudes et longitudes sont exprimées en **radians** ($1 ° × π/180 = 0,01745 rad$),

    + les fonctions trigonométriques sont disponibles dans la bibliothèque `math`.
    
    Résultats attendus :

    | A | B | Distance |
    | --- | --- | --- |
    | **Petit bois à l'Immac**<br>Latitude : `48.07465140238585`<br>Longitude : `-0.7685811118128099` | **Kiosque du Square de Boston**<br>Latitude : `48.07352246874617`<br>Longitude : `-0.7723670509520487` | 308 m |
    | **Tour Eiffel**<br>Latitude : `48.8584830111056`<br>Longitude : `2.2944598391027196` | **Golden Gate**<br>Latitude : `37.82000588671323`<br>Longitude : `-122.47860249700975` | 8949 km |

    ??? success "Solution"

        ```py
        from math import cos, pi, sqrt, sin, asin

        def calculer_distance_vol_oiseau(latA : float, lngA : float, latB : float, lngB : float) :
            '''
            Calcule la distance à vol d'oiseau entre deux points A(latA, lngA) et B(latB, lngB) du globe à partir de leurs coordonnées GPS.
            '''

            distance = 0

            # Conversion en radians
            latA = latA * pi / 180
            lngA = lngA * pi / 180
            latB = latB * pi / 180
            lngB = lngB * pi / 180

            # Calcul de la distance
            distance =  2 * 6371 * asin(sqrt(sin((latB - latA) / 2) ** 2 + cos(latA) * cos(latB) * sin((lngB - lngA) / 2) ** 2))

            return distance

        # Tests

        print(calculer_distance_vol_oiseau(48.07465140238585, -0.7685811118128099, 48.07352246874617, -0.7723670509520487)) #  308 m

        print(calculer_distance_vol_oiseau(48.8584830111056, 2.2944598391027196, 37.82000588671323, -122.47860249700975))   # 8949 km
        ```

??? exo-chrono "Exercice 5.2<span class="chrono">15:00</span>"

    Reprendre la fonction créée à l'exercice 5.1 en l'adaptant pour qu'elle prenne en entrée un dictionnaire au format suivant :

    ```py
    trajet1 = {
        "A" : {
            "nom" : "Petit bois à l'Immac",
            "lat" : 48.07465140238585,
            "lng" : -0.7685811118128099
        },
        "B" : {
            "nom" : "Kiosque du Square de Boston",
            "lat" : 48.07352246874617,
            "lng" : -0.7723670509520487
        },
        "distance" : 0
    }
    ```

    ??? success "Solution"

        ```py
        from math import cos, pi, sqrt, sin, asin

        def calculer_distance_vol_oiseau(trajet : dict) :
            '''
            Calcule la distance à vol d'oiseau entre deux points A(latA, lngA) et B(latB, lngB) du globe à partir de leurs coordonnées GPS.
            '''

            distance = 0

            # Conversion en radians (on garde des variables locales pour ne pas modifier le dictionnaire)
            latA = trajet["A"]["lat"] * pi / 180
            lngA = trajet["A"]["lng"] * pi / 180
            latB = trajet["B"]["lat"] * pi / 180
            lngB = trajet["B"]["lng"] * pi / 180

            # Calcul de la distance
            trajet["distance"] =  2 * 6371 * asin(sqrt(sin((latB - latA) / 2) ** 2 + cos(latA) * cos(latB) * sin((lngB - lngA) / 2) ** 2))

            # Rien à renvoyer : les dictionnaires comme les listes sont passés par références
            # (modifier le dictionnaire dans la fonction le modifie dans la fonction appelante)

        # Tests

        trajet1 = {
            "A" : {
                "nom" : "Petit bois à l'Immac",
                "lat" : 48.07465140238585,
                "lng" : -0.7685811118128099
            },
            "B" : {
                "nom" : "Kiosque du Square de Boston",
                "lat" : 48.07352246874617,
                "lng" : -0.7723670509520487
            },
            "distance" : 0
        }
        calculer_distance_vol_oiseau(trajet1)
        print(trajet1["distance"])              #  308 m

        #print(calculer_distance_vol_oiseau(48.8584830111056, 2.2944598391027196, 37.82000588671323, -122.47860249700975))
        trajet2 = {
            "A" : {
                "nom" : "Tour Eiffel",
                "lat" : 48.8584830111056,
                "lng" : 2.2944598391027196
            },
            "B" : {
                "nom" : "Golden Gate",
                "lat" : 37.82000588671323,
                "lng" : -122.47860249700975
            },
            "distance" : 0
        }
        calculer_distance_vol_oiseau(trajet2)
        print(trajet2["distance"]) # 8949 km
        ```