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

??? success "Solution"

    ```c
    #include <stdio.h>
    #include <time.h>

    int main() {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        
        // jj/mm/aaaa hh h ii' ss"
        printf("%02d/%02d/%04d %02d h %02d' %02d\"\n", 
            tm.tm_mday, 
            tm.tm_mon + 1, 
            tm.tm_year + 1900, 
            tm.tm_hour, 
            tm.tm_min, 
            tm.tm_sec
        );

        // aaaammjjhhiiss
        printf("%04d%02d%02d%02d%02d%02d\n", 
            tm.tm_year + 1900, 
            tm.tm_mon + 1, 
            tm.tm_mday, 
            tm.tm_hour, 
            tm.tm_min, 
            tm.tm_sec
        );
    }
    ```

## Etudier le programme

### Déclaration

**Q2** | Trouver et noter la déclaration de la structure tm.

??? success "Solution"

    ```c
    struct tm
    {
        int tm_sec;   // seconds after the minute - [0, 60] including leap second
        int tm_min;   // minutes after the hour - [0, 59]
        int tm_hour;  // hours since midnight - [0, 23]
        int tm_mday;  // day of the month - [1, 31]
        int tm_mon;   // months since January - [0, 11]
        int tm_year;  // years since 1900
        int tm_wday;  // days since Sunday - [0, 6]
        int tm_yday;  // days since January 1 - [0, 365]
        int tm_isdst; // daylight savings time flag
    };
    ```

**Q3** | Quel terme utilise-t-on pour nommer les **éléments** d’une structure ?

??? success "Solution"

    **attributs**, propriétés, champs, membres (+ générique)

**Q4** | Proposer une écriture générique pour **déclarer une structure**.

??? success "Solution"

    ```c
    struct nom_de_la_strcuture {
        type_1 attribut_1;
        type_2 attribut_2;
        ...
        type_n attribut_n;
    };
    ```

## Utilisation

**Q5** | Dans le programme, quel **mot-clé** est utilisé lors de la déclaration de la variable utilisant la structure tm ?

??? success "Solution"

    `struct`

**Q6** | A l'aide de quel symbole accède-t-on aux valeurs stockées (aux attributs) dans la variable utilisant la structure tm ?

??? success "Solution"

    On utilise le point `.` :

    ```c
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    tm.tm_mday
    ```


**Q7** | Il existe deux symboles pour accéder aux valeurs stockées dans une variable utilisant une structure. Les trouver et noter quand est-ce qu'on les utilise.

??? success "Solution"

    Avec une variable, on utilise le `.` 

    Avec un pointeur, on utilise la `->`

    ```c
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    tm.tm_mday

    struct tm * tm2 = localtime(&t);

    tm2->tm_mday
    ```

## Aller plus loin

![aller plus loin](../images/illustration/aller_plus_loin.jpg)

### Déclarer sa propre structure

**Q8** | Proposer la déclaration d'une structure nommée `point` pour stocker les coordonnées entières x et y d’un point sur un graphique.

??? success "Solution"

    ```c
    struct point {
        int x;
        int y;
    };
    ```

**Q9** | Proposer la déclaration d'une structure nommée `student` pour stocker le nom d'un étudiant, son prénom et 10 notes.

??? success "Solution"

    ```c
    struct student {
        char nom[50];
        char prenom[50];
        float notes[10];
    };
    ```
    
**Q10** | Proposer la déclaration d'une structure nommée `releve_temperature` pour stocker un relevé de température en conservant la date et l'heure du relevé.

??? success "Solution"

    ```c
    #include <time.h>

    struct releve_temperature {
        struct tm tm;
        float temperature;
    };

    // ou mieux :

    struct releve_temperature {
        time_t timestamp;
        float temperature;
    };
    ```

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

    La structure `ma_structure` est déclarée dans le `main`, sa portée se limite donc à cette fonction. Il n’est pas possible d’y faire référence dans une fonction `f` déclarée avant le `main`.

    Une structure doit être déclarée **avant** d’être utilisée.

### Utiliser une structure

**Q12** | En utilisant la structure `point` définie plus tôt, **déclarer** deux variables `A` et `B`.

??? success "Solution"

    ```c
    struct point A, B;
    ```

**Q13** | En utilisant la structure `point` définie plus tôt, **initialiser** les points `C(1, 2)` et `D(3, -2)`.

??? success "Solution"

    ```c
    struct point C = { 1, 2 }, D = { 3, -2 };
    ```

**Q14** | En utilisant la structure `student` définie plus tôt, **initialiser** une variable `mf` pour stocker les informations de l'étudiante Micheline FROUBILLON avec les notes suivantes : 18, 13, 17.5 et 19.5.

??? success "Solution"

    ```c
    // Initialisation séquentielle (forcément dans l'ordre de déclaration des attributs)
    struct student mf = { "FROUBILLON", "Micheline", { 18, 13, 17.5, 19.5 } };

    // Initialisation sélective
    struct student mf = { .prenom = "Micheline", .notes = { 18, 13, 17.5, 19.5 }, .nom = "FROUBILLON" };
    ```

**Q15** | En utilisant la structure `student` définie plus tôt, **initialiser** une variable `md` pour stocker les informations de  l'étudiant Michel DURAND, qui n'a pas encore de note.

??? success "Solution"

    ```c
    struct student md = { "DURAND", "Michel" };
    ```

**Q16** | En utilisant la structure `student` définie plus tôt, **initialiser** une variable `xx` pour stocker les informations d'un étudiant anonyme avec un relevé de notes initialisé à -1.

??? success "Solution"

    ```c
    struct student xx = { .notes = { -1 } };
    ```
    
### Accéder aux valeurs des attributs

**Q17** | Afficher les valeurs des champs de la variable `mf` :

```
./programme.exe
Prénom : Micheline
Nom : FROUBILLON
Notes : 18.00, 13.00, 17.50, 19.50
```

??? success "Solution"

    Il faut compléter notre structure `student` pour ajouter le nombre de notes saisies dans le tableau :

    ```c
    struct student {
        char nom [25];
        char prenom [25];
        float notes [10];
        int notesCount;
    };
    ```

    Ce qui permet d'afficher le contenu d'une structure `student` de la manière suivante :

    ```c
    struct student mf = {
        "FROUBILLON", 
        "Micheline",         
        { 18, 13, 17.5, 19.5 },
        4
    };

    printf("Prénom : %s\nNom : %s\nNotes : ", mf.prenom, mf.nom);
    for (int i = 0; i < mf.notesCount; i++) {
        printf("%s%.2f", i == 0 ? "" : ", ", mf.notes[i]);
    }
    ```

**Q18** | Remplacer le code de la question précédente par une fonction nommée display() et l'utiliser pour afficher les valeurs des champs des variables `mf`, `md` et `xx`.

??? success "Solution"

    ```c
    void display(struct student s) {
        printf("Prénom : %s\nNom : %s\nNotes : ", s.prenom, s.nom);
        for (int i = 0; i < s.notesCount; i++) {
            printf("%s%.2f", i == 0 ? "" : ", ", s.notes[i]);
        }
    }
    ```

**Q19** | Créer une fonction nommée `getAverageGrade()` qui renvoie la moyenne d'un `student` passé en paramètre.

??? success "Solution"

    ```c
    float getAverageGrade(struct student s) {
        float result = 0;
        for (int i = 0; i < s.notesCount; i++) {
            result += s.notes[i];
        }
        return result / s.notesCount;
    }
    ```

### Copier une variable de type structuré

Contrairement aux tableaux (et par extension aux chaînes de caractères), il est possible de copier une variable de type structuré dans une autre par *simple* affectation.

**Q20** | Créer la variable `md1` pour Maurice, le frère de Michel DURAND, en l'initialisant avec `md`, puis en changeant son prénom.

??? success "Solution"

    ```c
    #include <string.h>

    // ...

    struct student md = { .prenom = "Michel", .nom = "DURAND", .notesCount = 0 };
    struct student md1;
    md1 = md;
    strcpy(md1.prenom, "Maurice"); // ! Pas d'affectation de chaîne de caractères !
    ```

**Q21** | Pour simplifier le processus de création de `student`, en compilant vos travaux ci-dessus, créer une fonction `createStudent()` qui renvoie une variable `student` avec toutes ses notes initialisées à 0 et les noms et prénoms passés en paramètres.

??? success "Solution"

    ```c
    struct student createStudent(char * nom, char * prenom) {
        struct student newStudent = { 
            .notes = { 0 }, 
            .notesCount = 0 
        };
        strcpy(newStudent.nom, nom);
        strcpy(newStudent.prenom, prenom);
        return newStudent;
    }
    ```

### Modifier les valeurs des champs

**Q22** | Créer dans le `main()`, une variable `student` nommée `js` pour Jacqueline SUPINOT en utilisant la fonction `createStudent()` puis modifier ses 3 premières notes : elle a eu 17, 9.5 et 13.75 aux premiers contrôles.

??? success "Solution"

    ```c
    struct student js = createStudent("SUPINOT", "Jacqueline");
    js.notes[0] = 17;
    js.notes[1] = 9.5;
    js.notes[2] = 13.75;
    js.notesCount = 3;
    display(js);
    ```
  
**Q23** | Créer une fonction `ucFirstFirstname()` qui permet de mettre la première lettre du prénom d'une variable `student` passée en argument en majuscule.

??? success "Solution"

    ```c
    void ucFirstFirstname(struct student * s) {
        s->prenom[0] = toupper(s->prenom[0]);
    }

    // ...

    // Utilisation
    struct student js = createStudent("SUPINOT", "jacqueline");
    ucFirstFirstname(&js);
    ```
    
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

    Modification de `readfile()` :

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    struct releve_temperature {
        time_t timestamp;
        float temperature;
    };

    void readFile(struct releve_temperature * releves) {
        FILE * ftemp = fopen("temp-100-jours.csv", "r");
        float tmax = 0.0f, tmoy = 0.0f;

        if (ftemp == NULL) {
            puts("Problème lors de la lecture du fichier");
            exit(-1);
        }

        for (int i = 0; i < 100; i++) {
            fscanf(ftemp, "%d;%f;%f;%f\r\n", &releves[i].timestamp, &releves[i].temperature, &tmax, &tmoy);
        }

        fclose(ftemp);
    }

    int main() {
        // Encodage et nettoyage de la console
        system("chcp 65001");
        system("cls");

        struct releve_temperature releves[100];

        // Lecture du fichier
        readFile(releves);

        return 0;
    }
    ```


## Exercice bonus

Créer un programme qui reproduit le fonctionnement du site : https://estcequecestbientotleweekend.fr/