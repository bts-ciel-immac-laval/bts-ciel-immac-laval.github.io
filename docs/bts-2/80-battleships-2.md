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

## Découverte de l'API

Documentation officielle en français : 
[https://github.com/kitao/pyxel/blob/main/docs/README.fr.md](https://github.com/kitao/pyxel/blob/main/docs/README.fr.md)

Explication des concepts de base en POO : [Tuto NDC](https://nuitducode.forge.apps.education.fr/docs/PYTHON/TUTORIELS/2-premiers-pas-avec-pyxel-terminale/)

Quelques défis (de saison) pour s'entraîner :

+   Afficher "Vive le vent..." caractère par caractère

+   Afficher "Vive le vent..." mot par mot en changeant de couleur à chaque mot

+   Faire neiger sur l'écran

+   Cacher une immage sous un fond noir et afficher un halo révélateur au survol de la souris