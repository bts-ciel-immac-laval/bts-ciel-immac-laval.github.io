# BattleShips

## Initiation à Pyxel

### Installation de l'environnement de développement

#### Eléments à installer :

- Python
- Pyxel
- Git
- VS Code

#### Installation de Python

1. Se rendre sur cette page : https://www.python.org/downloads/windows/
2. Télécharger le **Windows Installer (64-Bit)** de la dernière version stable
3. Lancer l'installeur
4. Décocher "Use admin privileges when installing py.exe"
5. Cocher "Add python.exe to PATH" *(c'est ce qui permet de juste saisir `python ...` en ligne de commande)*
6. Cliquer sur "Install Now"

:warning: Bien fermer **toutes** les fenêtres de terminal avant de tester.

7. Tester en ouvrant une fenêtre de terminal et en saisissant `python --version`, la version installée doit s'afficher.

#### Installation de Pyxel

Pyxel est un module Python, il s'installe avec pip (l'utilitaire d'installation des modules, bibliothèque Python).

1. Ouvrir un terminal
2. Saisir `pip install pyxel`

Si cela ne fonctionne pas, essayer : `python -m pip install pyxel`

#### Installation de Git

1. Se rendre sur la page : https://git-scm.com/install/windows
2. Télécharger le standalone installer : **Git for Windows/x64 Setup**.
3. Lancer l'installeur et dérouler toute l'installation sans changer les options.

#### Installation de VS Code

1. Se rendre sur la page : https://code.visualstudio.com/download
2. Télécharger le **User Installer x64** pour Windows.
3. Lancer l'installeur et dérouler toute l'installation sans changer les options.
4. Lancer VS Code.
5. Installer l'extension **Python**.

## Python

![Aide-mémoire Python](../pdf/cours/bts2/memo_python.pdf)

![Cheatsheet Python](../pdf/cours/bts2/beginners_python_cheat_sheet_pcc_all.pdf)

## Découverte de l'API

Documentation officielle en français : 
[https://github.com/kitao/pyxel/blob/main/docs/README.fr.md](https://github.com/kitao/pyxel/blob/main/docs/README.fr.md)

Explication des concepts de base en POO : [Tuto NDC](https://nuitducode.forge.apps.education.fr/docs/PYTHON/TUTORIELS/2-premiers-pas-avec-pyxel-terminale/)

Quelques défis (de saison) pour s'entraîner :

+   Afficher "Vive le vent..." caractère par caractère

    ![defi1](../images/gif/day01.gif)

    ??? success "Solution"

        ```python
        import pyxel

        pyxel.init(128, 128)

        song = [
            "Vive le vent,",
            "Vive le vent,",
            "Vive le vent d'hiver",
            "Qui s'en va sifflant, soufflant,",
            "Dans les grands sapins verts...",
            "Hey !",
            " ",
            "Vive le temps,",
            "Vive le temps,",
            "Vive le temps d'hiver",
            "Boule de neige et jour de l'an,",
            "Et bonne annee grand-mere !"
        ]

        steps = 0

        def update() :
            global steps

            # On compte les itérations
            steps += 1 

        def draw() :
            global steps, song

            # On efface l'écran
            pyxel.cls(1)

            line = 0

            # Pour ralentir l'affichage, on n'affiche 
            # un caractère supplémentaire qu'une itération sur deux
            remainingChars = steps // 2
            
            while remainingChars > 0 and line < len(song) :
                # Si la ligne actuelle ne contient pas assez de caractère
                # on n'en affiche qu'une partie
                if remainingChars < len(song[line]) :
                    pyxel.text(1, 20 + 7 * line, song[line][:remainingChars], 7)
                    remainingChars = 0
                
                # sinon on affiche tout et on passe à la ligne suivante
                else :
                    pyxel.text(1, 20 + 7 * line, song[line], 7)
                    remainingChars -= len(song[line])
                    line += 1

        pyxel.run(update, draw)
        ```

+   Afficher "Vive le vent..." mot par mot en changeant de couleur à chaque mot

    ![defi2](../images/gif/day02.gif)

    ??? success "Solution"

        ```python
        import pyxel

        pyxel.init(128, 128)

        song = [
            "Vive le vent,",
            "Vive le vent,",
            "Vive le vent d'hiver",
            "Qui s'en va sifflant, soufflant,",
            "Dans les grands sapins verts...",
            "Hey !",
            " ",
            "Vive le temps,",
            "Vive le temps,",
            "Vive le temps d'hiver",
            "Boule de neige et jour de l'an,",
            "Et bonne annee grand-mere !"
        ]
        # On éclate chaque ligne en un tableau de mots
        songWords = list()
        for i in range(len(song)) :
            songWords.append(song[i].split(" "))

        steps = 0

        def update() :
            global steps

            # On compte les itérations
            steps += 1 

        def draw() :
            global steps, songWords

            # On efface l'écran
            pyxel.cls(2)

            # Pour ralentir l'affichage, on n'affiche 
            # un mot supplémentaire qu'une itération sur 10 !
            remainingWords = steps // 10

            line = 0
            color = 0
            
            while remainingWords > 0 and line < len(songWords) :
                prevWordLength = 0

                # On affiche chaque ligne mot à mot (tant qu'il reste des mots)
                for i in range(len(songWords[line]) if len(songWords[line]) < remainingWords else remainingWords) :
                    # Chaque caractère occupe 4 pixels de large
                    pyxel.text(1 + prevWordLength * 4, 20 + 6 * line, songWords[line][i], color)
                    
                    remainingWords -= 1
                    prevWordLength += len(songWords[line][i]) + 1       # + 1 espace
                    
                    # On change la couleur
                    color += 1
                    if color == 16 :
                        color = 0
                    if color == 2 :
                        color += 1

                line += 1

        pyxel.run(update, draw)
        ```

+   Faire neiger sur l'écran

    ![defi3](../images/gif/day03.gif)

    ??? success "Solution"

        ```python
        import pyxel
        from random import randint

        pyxel.init(128, 128)

        snow = []

        def update() :
            global snow

            # On descend tous les flocons
            for i in range(len(snow)) :
                if pyxel.pget(snow[i][0], snow[i][1] + 1) != 7 and snow[i][1] < 127 :
                    snow[i][1] += 1
            
            # On limite le nombre de flocons à la moitié de l'écran
            if len(snow) < 128 * 64 :
                # Ajouter des 3 à 10 flocons
                for i in range(randint(3, 10)) :
                    snow.append([randint(0, 127), 0])

        def draw() :
            global steps
            pyxel.cls(3)

            # On affiche tous les flocons
            for i in range(len(snow)) :
                pyxel.pset(snow[i][0], snow[i][1], 7)
            

        pyxel.run(update, draw)
        ```

+   Cacher une image sous un fond noir et afficher un halo révélateur au survol de la souris

    ![defi4](../images/gif/day08.gif)

    ??? success "Solution"

        fichier .pyxres : [advent.pyxres](../files/bts2/advent.pyxres)

        ```python
        import pyxel
        from random import randint
        from math import sqrt

        pyxel.init(128, 128)

        # Chargement du pyxres
        pyxel.load('../advent.pyxres')

        # Placement de Santa et du coucou
        santaX = randint(10, 90)
        santaY = randint(20, 90)
        coucouX = (santaX + 12) if santaX < 48 else (santaX - 10)
        coucouY = santaY - 8

        def update() :
            pass

        def draw() :
            global santaX, santaY, coucouX, coucouY
            
            # On dessine d'abord le fond
            pyxel.cls(9)
            
            # On dessine ensuite Santa
            pyxel.blt(santaX, santaY, 0, 0, 0, 32, 32, 10)

            # On dessine ensuite le coucou...
            pyxel.text(coucouX, coucouY, "coucou", 7)
            # ...avec une petite ligne dans le bon sens
            if coucouX < santaX :
                pyxel.line(coucouX + 12, coucouY + 6, coucouX + 13, coucouY + 7, 7)
            else :
                pyxel.line(coucouX + 11, coucouY + 6, coucouX + 10, coucouY + 7, 7)

            # Finalement on colorie toute l'image en noir sauf la zone à une distance de 16 pixels ou moins de la souris
            for i in range(128) :
                for j in range(128) :
                    if sqrt((i - pyxel.mouse_x)**2 + (j - pyxel.mouse_y)**2) >= 16 :
                        pyxel.pset(i, j, 0)

        pyxel.run(update, draw)
        ```

## Premiers développements

+   Créer une classe `Case` et l'utiliser dans un programme qui affiche une cache cochable au clic :

    ``` mermaid
    classDiagram
        class Case {
            - x : int
            - y : int
            - w : int
            - h : int
            - checked : boolean
            + _ _init_ _(x : int, y : int, w : int, h :int)
            + update()
            + draw()
        }
    ```

    ??? success "Solution"

        ```python
        import pyxel

        class Case :
            def __init__(self, x : int, y : int, w : int, checked : bool) -> None:
                self.__x = x
                self.__y = y
                self.__w = w
                self.__h = w
                self.__checked = checked

            def update(self) -> None :
                if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and self.__x <= pyxel.mouse_x <= self.__x + self.__w and self.__y <= pyxel.mouse_y <= self.__y + self.__h :
                    self.__checked = not self.__checked

            def draw(self) -> None :
                pyxel.rectb(self.__x, self.__y, self.__w, self.__h, 7)
                if self.__checked :
                    pyxel.line(self.__x + 2, self.__y + 2, self.__x + self.__w - 3, self.__y + self.__h - 3, 7)
                    pyxel.line(self.__x + self.__w - 3, self.__y + 2, self.__x + 2, self.__y + self.__h - 3, 7)

        class App:
            def __init__(self):
                pyxel.init(128, 128)
                pyxel.mouse(True)
                self.cases = [Case(10, 10, 9, False), Case(10, 21, 9, True), Case(10, 32, 9, False)]
                pyxel.run(self.update, self.draw)

            def update(self):
                for i in range(len(self.cases)) :
                    self.cases[i].update()

            def draw(self):
                pyxel.cls(0)
                for i in range(len(self.cases)) :
                    self.cases[i].draw()

        App()
        ```

+   Réutiliser la classe `Case` pour créer une grille

    ``` mermaid
    classDiagram
        class Case {
            - x : int
            - y : int
            - w : int
            - h : int
            - checked : boolean
            + _ _init_ _(x : int, y : int, w : int, h :int)
            + update()
            + draw()
        }
        class Grille {
            - x : int
            - y : int
            - l : int
            - c : int
            - cases : Case[]
            + _ _init_ _(x : int, y : int, l : int, c :int)
            + update()
            + draw()
        }
        Grille -- Case
    ```

    ??? success "Solution"

        ```py
        import pyxel

        class Case :
            def __init__(self, x : int, y : int, w : int, color : int = 7, checked : bool = False) -> None:
                self.__x = x
                self.__y = y
                self.__w = w
                self.__h = w
                self.__color = color
                self.__checked = checked

            def update(self) -> None :
                # Gestion du clic
                if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and self.__x < pyxel.mouse_x < self.__x + self.__w - 1 and self.__y < pyxel.mouse_y < self.__y + self.__h - 1 :
                    self.__checked = not self.__checked

            def draw(self) -> None :
                # Contour
                pyxel.rectb(self.__x, self.__y, self.__w, self.__h, self.__color)
                
                # Croix
                if self.__checked :
                    pyxel.line(self.__x + 2, self.__y + 2, self.__x + self.__w - 3, self.__y + self.__h - 3, self.__color)
                    pyxel.line(self.__x + self.__w - 3, self.__y + 2, self.__x + 2, self.__y + self.__h - 3, self.__color)

        class Grille : 
            def __init__(self, x : int, y : int, l : int, c : int, cw : int) -> None:
                self.__x = x
                self.__y = y
                self.__l = l
                self.__c = c
                self.__cw = cw
                self.cases = [[Case(self.__x + i * (self.__cw - 1), self.__y + j * (self.__cw - 1), self.__cw, 5) for i in range(c)] for j in range(l)]

            def update(self) -> None :
                # Mise à jour des cases
                for i in range(self.__l) :
                    for j in range(self.__c) :
                        self.cases[i][j].update()

            def draw(self) -> None :
                # Affichage des cases
                for i in range(self.__l) :
                    for j in range(self.__c) :
                        self.cases[i][j].draw()


        class App:
            def __init__(self):
                pyxel.init(128, 128)
                pyxel.mouse(True)
                self.grid = Grille(10, 10, 10, 10, 9)
                pyxel.run(self.update, self.draw)

            def update(self):
                self.grid.update()

            def draw(self):
                pyxel.cls(6)
                self.grid.draw()

        App()
        ```

+   Réutiliser la classe `Case` pour créer une case à cocher accompagnée d'un texte qui quand on clique dessus coche la case.

    ``` mermaid
    classDiagram
        class Case {
            - x : int
            - y : int
            - w : int
            - h : int
            - checked : boolean
            + _ _init_ _(x : int, y : int, w : int, h :int)
            + update()
            + draw()
        }
        class Checkbox {
            - text : string
            + _ _init_ _(x : int, y : int, w : int, h :int, text : string)
            + update()
            + draw()
        }
        Case <|-- Checkbox
    ```
    
    ??? success "Solution"

        ```py
        import pyxel

        class Case :

            def __init__(self, x : int, y : int, w : int, color : int = 7, checked : bool = False) -> None:
                self._x = x
                self._y = y
                self.__w = w
                self.__h = w
                self.__color = color
                self._checked = checked

            def update(self) -> None :
                # Gestion du clic
                if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and self._x < pyxel.mouse_x < self._x + self.__w - 1 and self._y < pyxel.mouse_y < self._y + self.__h - 1 :
                    self._checked = not self._checked

            def draw(self) -> None :
                # Contour
                pyxel.rectb(self._x, self._y, self.__w, self.__h, self.__color)
                
                # Croix
                if self._checked :
                    pyxel.line(self._x + 2, self._y + 2, self._x + self.__w - 3, self._y + self.__h - 3, self.__color)
                    pyxel.line(self._x + self.__w - 3, self._y + 2, self._x + 2, self._y + self.__h - 3, self.__color)

                     # ↓↓↓↓ Nom de la classe héritée
        class Checkbox(Case) : 
            
            def __init__(self, x : int, y : int, text : str) -> None:
                
                # Appel explicite de la méthode de la classe héritée :
                super().__init__(x, y, 7, 1)
                
                self.__text = text
                self._xt = x + 10
                self.__wt = len(text) * 4

            def update(self) -> None :
                
                # Mise à jour de la case
                super().update()

                # Gestion du clic au niveau du texte
                if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and self._xt <= pyxel.mouse_x <= self._xt + self.__wt - 1 and self._y + 1 <= pyxel.mouse_y <= self._y + 6 :
                    self._checked = not self._checked

            def draw(self) -> None :
                
                # Affichage de la case
                super().draw()
                
                # Affichage du texte
                pyxel.text(self._xt, self._y + 1, self.__text, 1)


        class App:
            def __init__(self):
                pyxel.init(128, 128)
                pyxel.mouse(True)
                self.checkbox1 = Checkbox(10, 10, "Option 1")
                self.checkbox2 = Checkbox(10, 20, "Option 2")
                pyxel.run(self.update, self.draw)

            def update(self):
                self.checkbox1.update()
                self.checkbox2.update()

            def draw(self):
                pyxel.cls(6)
                self.checkbox1.draw()
                self.checkbox2.draw()

        App()
        ```

+   Créer un programme qui affiche un nombre au hasard récupéré depuis une URL

    ??? success "Solution"

        Après avoir installé WAMP, créer un dossier `battleships` dans le répertoire `www` de WAMP.

        Y créer un fichier `lucky.php` :
        
        ```php
        <?php
        echo rand(0, 9);
        ?> 
        ```
        
        Côté Python/Pyxel :

        ```py
        import pyxel
        import requests

        class App:
            def __init__(self):
                pyxel.init(128, 128)
                pyxel.mouse(True)
                
                # Valeur par défaut de lucky
                self.lucky = "?"
                
                pyxel.run(self.update, self.draw)

            def update(self):
                # Au clic sur le carré :
                if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) and 60 <= pyxel.mouse_x <= 67 and 60 <= pyxel.mouse_y <= 67 :
                    
                    # Emission d'une requête GET
                    r = requests.get("http://localhost/battleships/lucky.php")
                    
                    # Récupération de la valeur renvoyée par le serveur
                    self.lucky = r.text

            def draw(self):
                pyxel.cls(0)
                pyxel.rectb(59, 59, 9, 9, 9)

                # Affichage du nombre récupéré depuis le serveur (ou pas...)
                pyxel.text(62, 61, self.lucky, 9)

        App()
        ```

+   Créer un programme qui affiche des éléments extraits d'un message au format json récupéré depuis une URL

    Exemple de message :

    ```json
    {
        "ma_phrase" : "hello, world!",
        "lucky" : 9,
        "tableau": [1, 2, 3],
        "object" : {
            "attribut1" : 12,
            "attribut2" : "42"
        }
    }
    ```

    ??? success "Solution"

        Côté :simple-php: :

        ```php
        <?php
        $message = '{
            "ma_phrase" : "hello, world!",
            "lucky" : 9,
            "tableau": [1, 2, 3],
            "object" : {
                "attribut1" : 12.3,
                "attribut2" : "42"
            }
        }';
        echo $message;
        ?>
        ```

        ou avec un "object/dictionnaire" encodé en json :

        ```php
        <?php
        $message = [
            'ma_phrase' => 'hello, world!',
            'lucky' => rand(0, 9),
            'tableau' => [1, 2, 3],
            'object' => [
                'attribut1' => 12.3,
                'attribut2' => '42'
            ]
        ];
        echo json_encode($message);
        ?>
        ```

        Côté :material-language-python:

        ```py
        import pyxel
        import requests
        import json

        class App:
            def __init__(self):
                pyxel.init(128, 128)
                pyxel.mouse(True)
                self.message = None
                pyxel.run(self.update, self.draw)

            def update(self):
                if pyxel.btnp(pyxel.MOUSE_BUTTON_LEFT) :
                    r = requests.get("http://localhost/battleships/message.php")
                    self.message = json.loads(r.text)

            def draw(self):
                pyxel.cls(0)
                
                if self.message != None :
                    pyxel.text(10, 10, self.message["ma_phrase"], 9)
                    pyxel.text(10, 20, str(self.message["lucky"]), 9)
                    for i in range(len(self.message["tableau"])) :
                        pyxel.text(10 + i * 8, 30, str(self.message["tableau"][i]), 9)
                    pyxel.text(10, 40, str(self.message["object"]["attribut1"]), 9)
                    pyxel.text(10, 50, self.message["object"]["attribut2"], 9)

        App()
        ```

+   Créer un programme qui affiche une phrase récupérée depuis une URL et complétée avec une donnée envoyée au format json

    ??? success "Solution"

        Côté :simple-php: :
        ```php
        <?php
        // On vérifie s'il y a des données postées
        if (isset($_POST) && isset($_POST['prenom'])) {
            // On récupère le prénom envoyé avec $_POST['prenom']
            echo json_encode(["message" => "Bonjour " . $_POST['prenom'] . " !"]);
        }
        else {
            echo json_encode(["message" => "Erreur !"]);
        }
        ?>
        ```

        Côté :material-language-python:

        ```py
        import pyxel
        import requests
        import json

        class App:
            def __init__(self):
                pyxel.init(128, 128)
                self.prenom = ""
                self.reponse = None
                pyxel.run(self.update, self.draw)

            def update(self):
                # Saisie du prénom au clavier
                if len(self.prenom) < 10 :
                    for i in range(26) :
                        if (pyxel.btnp(pyxel.KEY_A + i)) :
                            self.prenom += chr(pyxel.KEY_A + i - 32)

                # Correction
                if pyxel.btnp(pyxel.KEY_BACKSPACE) and len(self.prenom) > 0 :
                    self.prenom = self.prenom[:-1]

                # Emission de la requête
                if pyxel.btnp(pyxel.KEY_RETURN) :
                    r = requests.post("http://localhost/battleships/hello.php", { "prenom" : self.prenom })
                    self.reponse = json.loads(r.text)

            def draw(self):
                pyxel.cls(0)
                
                pyxel.text(10, 10, "Prenom:", 7)
                
                # Boîte de texte
                pyxel.rectb(42, 8, 44, 9, 7)
                pyxel.text(44, 10, self.prenom, 7)
                if (pyxel.frame_count % 40 > 20) :
                    x = 44 + len(self.prenom) * 4
                    pyxel.line(x, 10, x, 14, 7) 
                
                # Bouton
                pyxel.rect(89, 8, 9, 9, 7)
                pyxel.line(94, 10, 94, 13, 0)
                pyxel.line(94, 13, 91, 13, 0)
                pyxel.pset(92, 12, 0)
                pyxel.pset(92, 14, 0)
                pyxel.pset(91, 14, 13)

                # Message (s'il y en a un...)
                if self.reponse != None :
                    pyxel.text(44, 20, self.reponse["message"], 7)

        App()
        ```

+   Créer un programme qui affiche le résultat récupéré depuis une URL d'une requête SQL filtrée par une donnée envoyée au format json

    En utilisant [PhpMyAdmin](http://localhost/phpmyadmin/), créer une base de données :

    ```sql
    --
    -- Base de données : `test`
    --
    CREATE DATABASE IF NOT EXISTS `test` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
    USE `test`;

    --
    -- Structure de la table `utilisateur`
    --

    CREATE TABLE IF NOT EXISTS `utilisateur` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `login` varchar(33) NOT NULL,
    `password` varchar(33) NOT NULL,
    PRIMARY KEY (`id`)
    ) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

    --
    -- Déchargement des données de la table `utilisateur`
    --

    INSERT INTO `utilisateur` (`id`, `login`, `password`) VALUES
    (1, 'michel', 'd780182f77b121450849c2b088a444f0'),
    (2, 'karine', 'fd90a6b28219a4febb1ab06d03513d77');
    ```

    Envoyer ensuite login et mot de passe (michel/michel ou karine/karine) via une requête post et valider la connexion au regard de la base de données. 

+   Créer un code qui gère les différents aléas induits par l'utilisation d'une requête HTTP : délai de réponse, erreurs (404, 500)...