# Les structures

![structures](../images/illustration/structures.jpg)

## Besoin initial

Pour répondre au besoin d'un futur projet, votre programme doit récupérer la date et l'heure du système et la formater dans une chaîne de caractères au format `aaaammjjhhiiss`, où :

- `aaaa` : est l'année sur 4 chiffres
- `mm` : le mois sur deux chiffres
- `jj` : le jour dans le mois sur deux chiffres
- `hh` : l'heure sur deux chiffres (24h)
- `ii` : les minutes sur deux chiffres
- `ss` : les secondes sur deux chiffres

Par exemple, si à l'exécution du programme, nous sommes le 23/04/2023 et qu'il est 12 h 56 et 47 secondes, la chaîne résultante doit être : `20230423125647`.

## Observer et déduire

![horloge](../images/illustration/horloge.jpg)

Les fonctions permettant de manipuler le temps en C sont définies dans la bibliothèque time.h. En C, les dates sont calculées en secondes écoulées depuis le 1er janvier 1970 00:00:00 UTC [Epoch](https://fr.wikipedia.org/wiki/Epoch).

time.h définit également une "structure" nommée **tm** qui permet de récupérer de manière simple et rapide les différentes composantes de la date.

Etudions cette "structure".

*Répondre aux questions suivantes en réalisant des recherches sur Internet. Pour les éléments de code, tester vos propositions avec votre IDE. Vos recherches feront office de support de cours, noter un maximum d'exemples et soignez votre rédaction.*

## Afficher l'heure

**Q1** | A l'aide de la page [How to get the date and time values in a C program?](https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program), trouver, adapter et tester un programme utilisant la **structure tm** permettant d'afficher la date et l'heure au moment de l'exécution du programme sous les formes suivantes :

- `jj/mm/aaaa hh h ii' ss"`
- `aaaammjjhhiiss`

Exemple :

```
> ./heure.exe
23/04/2023 10 h 33' 42"
20230423103342
```

## Etudier le programme

### Déclaration

**Q2** | Trouver et noter la déclaration de la structure tm.

**Q3** | Quel terme utilise-t-on pour nommer les **éléments** d’une structure ?

**Q4** | Proposer une écriture générique pour **déclarer une structure**.

## Utilisation

**Q5** | Dans le programme, quel **mot-clé** est utilisé lors de la déclaration de la variable utilisant la structure tm ?

**Q6** | A l'aide de quel symbole accède-t-on aux valeurs stockées (aux attributs) dans la variable utilisant la structure tm ?

**Q7** | Il existe deux symboles pour accéder aux valeurs stockées dans une variable utilisant une structure. Les trouver et noter quand est-ce qu'on les utilise.
