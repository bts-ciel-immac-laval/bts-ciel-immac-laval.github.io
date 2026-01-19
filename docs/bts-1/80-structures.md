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

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q3** | Quel terme utilise-t-on pour nommer les **éléments** d’une structure ?

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q4** | Proposer une écriture générique pour **déclarer une structure**.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

## Utilisation

**Q5** | Dans le programme, quel **mot-clé** est utilisé lors de la déclaration de la variable utilisant la structure tm ?

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q6** | A l'aide de quel symbole accède-t-on aux valeurs stockées (aux attributs) dans la variable utilisant la structure tm ?

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q7** | Il existe deux symboles pour accéder aux valeurs stockées dans une variable utilisant une structure. Les trouver et noter quand est-ce qu'on les utilise.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

## Aller plus loin

![aller plus loin](../images/illustration/aller_plus_loin.jpg)

### Déclarer sa propre structure

**Q8** | Proposer la déclaration d'une structure nommée `point` pour stocker les coordonnées entières x et y d’un point sur un graphique.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q9** | Proposer la déclaration d'une structure nommée `student` pour stocker le nom d'un étudiant, son prénom et 10 notes.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)
    
**Q10** | Proposer la déclaration d'une structure nommée `releve_temperature` pour stocker un relevé de température en conservant la date et l'heure du relevé.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

La définition d'une structure doit toujours être placée avant sa première utilisation. L'endroit où elle est définie détermine sa portée.

**Q11** | Expliquer pourquoi le programme suivant ne compile pas.

```c
void f(struct ma_structure * p) {
    p->b = 13.4;
}

int main() {
    struct ma_structure {
        int a;
        float b;
    };

    struct ma_structure s;
    s.a = 42;
    f(&s);
}
```

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

### Utiliser une structure

**Q12** | En utilisant la structure `point` définie plus tôt, **déclarer** deux variables `A` et `B`.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q13** | En utilisant la structure `point` définie plus tôt, **initialiser** les points `C(1, 2)` et `D(3, -2)`.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q14** | En utilisant la structure `student` définie plus tôt, **initialiser** une variable `mf` pour stocker les informations de l'étudiante Micheline FROUBILLON avec les notes suivantes : 18, 13, 17.5 et 19.5.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q15** | En utilisant la structure `student` définie plus tôt, **initialiser** une variable `md` pour stocker les informations de  l'étudiant Michel DURAND, qui n'a pas encore de note.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q16** | En utilisant la structure `student` définie plus tôt, **initialiser** une variable `xx` pour stocker les informations d'un étudiant anonyme avec un relevé de notes initialisé à -1.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)
    
### Accéder aux valeurs des attributs

**Q17** | Afficher les valeurs des champs de la variable `mf` :

```
./programme.exe
Prénom : Micheline
Nom : FROUBILLON
Notes : 18.00, 13.00, 17.50, 19.50
```

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q18** | Remplacer le code de la question précédente par une fonction nommée display() et l'utiliser pour afficher les valeurs des champs des variables `mf`, `md` et `xx`.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q19** | Créer une fonction nommée `getAverageGrade()` qui renvoie la moyenne d'un `student` passé en paramètre.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

### Copier une variable de type structuré

Contrairement aux tableaux (et par extension aux chaînes de caractères), il est possible de copier une variable de type structuré dans une autre par *simple* affectation.

**Q20** | Créer la variable `md1` pour Maurice, le frère de Michel DURAND, en l'initialisant avec `md`, puis en changeant son prénom.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

**Q21** | Pour simplifier le processus de création de `student`, en compilant vos travaux ci-dessus, créer une fonction `createStudent()` qui renvoie une variable `student` avec toutes ses notes initialisées à 0 et les noms et prénoms passés en paramètres.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)

### Modifier les valeurs des champs

**Q22** | Créer dans le `main()`, une variable `student` nommée `js` pour Jacqueline SUPINOT en utilisant la fonction `createStudent()` puis modifier ses 3 premières notes : elle a eu 17, 9.5 et 13.75 aux premiers contrôles.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)
  
**Q23** | Créer une fonction `ucFirstFirstname()` qui permet de mettre la première lettre du prénom d'une variable `student` passée en argument en majuscule.

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)
    
## Exercice

Le programme temp_100.c ci-dessous lit le fichier ci-après et affiche les relevé de températures qu'il contient.

[temp-100-jours.csv](../files/bts1/temp-100-jours.csv){ .md-button .md-button--primary }

1. En utilisant la structure `releve_temperature` créée plus tôt, modifier la fonction `readFile()` pour charger les données lues dans un tableau de `releve_temperature` et le renvoyer à la fonction appelante.

2. Créer une fonction `getMin()` qui parcourt le tableau de `releve_temperature` et qui renvoie le relevé dont la température est la plus basse. Afficher cette température et la date correspondante sous la forme :

```
> ./temp_100.exe
Il faisait 4.7 degres le 07/11/2016.
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readFile() {
    FILE * ftemp = fopen("temp-100-jours.csv", "r");
    time_t timestamp = 0;
    float tmin = 0.0f, tmax = 0.0f, tmoy = 0.0f;

    if (ftemp == NULL) {
        puts("Problème lors de la lecture du fichier");
        exit(-1);
    }

    for (int i = 0; i < 100; i++) {

        fscanf(ftemp, "%d;%f;%f;%f\r\n", &timestamp, &tmin, &tmax, &tmoy);

        struct tm * tm = localtime(&timestamp);

        printf(
            "%02d/%02d/%4d : min : %6.2f °C, max : %6.2f °C, moy : %6.2f °C\n",
            tm->tm_mday,
            tm->tm_mon + 1,
            tm->tm_year + 1900,
            tmin,
            tmax,
            tmoy
        );
    }

    fclose(ftemp);
}

int main() {
    // Encodage et nettoyage de la console
    system("chcp 65001");
    system("cls");

    // Lecture du fichier
    readFile();

    return 0;
}
```

??? note "Rappel sur les échanges de tableaux avec les fonctions"

    ![Fonctions et tableaux](../pdf/cours/bts1/bts1_05_fonctions_tableaux.pdf)

??? success "Solution"

    ![waiting](../images/meme/loading-02.gif)


## Exercice bonus

Créer un programme qui reproduit le fonctionnement du site : https://estcequecestbientotleweekend.fr/
