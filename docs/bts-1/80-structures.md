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

**Q9** | Proposer la déclaration d'une structure nommée `student` pour stocker le nom d'un étudiant, son prénom et 10 notes.

**Q10** | Proposer la déclaration d'une structure nommée `releve_temperature` pour stocker un relevé de température en conservant la date et l'heure du relevé.

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