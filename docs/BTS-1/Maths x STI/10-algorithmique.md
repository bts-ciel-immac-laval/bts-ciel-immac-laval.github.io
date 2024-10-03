# 01 - Algorithmique

## MxSTI 1.1

Dans chaque cas un booléen est renvoyé. Lequel ?

+ `2 > 4`
+ `3 != 4`
+ `2 < 5 && 5 >= 3`
+ `2 < 5 || 4 < 0`
+ `! (2 < 3 || 1 > 2)`

## MxSTI 1.2

Qu'affiche le programme suivant si on saisit `Sacha` à la ligne 7 ?

```c linenums="1"
#include <stdio.h>

int main() {
    
    char a, b, c, d, e, f, g, h = 0;

    scanf("%c%c%c%c%c", &a, &b, &c, &d, &e);

    f = c - '1' + '\n' * 3;

    g = ++d + 0xA - sizeof(1234567890) * 2;
    
    h = d - !(b == e && h);

    printf("%c%c%c%xc%c%c", f, d, g, 's' - d, h, a + 34);

    return 0;
}
```

??? tip "A toutes fins utiles"

	![Table ASCII](../../images/cours/bts-1/maths-sti-1/table-ascii.svg)

## MxSTI 1.3

On exécute l’algorithme suivant en saisissant `N = 2`

```
VARIABLES :
	N est un entier
	U, V, W sont des réels
	K est un entier
DEBUT :
	Affecter 0 à K
	Affecter 2 à U
	Affecter 10 à V
	Saisir N
	Tant que K < N
		Affecter K + 1 à K
		Affecter U à W
		Affecter (2 * U + V) / 3 à U
		Affecter (W + 3 * V) / 4 à V
	Fin tant que
	Afficher U
	Afficher V
FIN
```

Donner l’état des variables au cours de l’exécution de l’algorithme.

Traduire en C et vérifier les résultats trouvés.

??? question "Tu ne sais pas traduire le "tant que..." ?"

	[Documentation en ligne :material-play:](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/14722-repetez-des-instructions-grace-aux-boucles#/id/r-14682){ .md-button .md-button--primary }

## MxSTI 1.4

On souhaite écrire une séquence d’instructions qui calcule :

$$
\frac{1}{1}\times\frac{1}{3}...\times\frac{1}{2k+1}\times...\times\frac{1}{51}
$$

Un élève propose le programme suivant, mais rien ne s’affiche dans la console.

```c
#include <stdio.h>

int main() {
	float p = 1;
	int k = 0;
	while (2 * k + 1 <= 51) {
		p = p * 1 / (2 * k + 1);
	}
	printf("%f", p);
} 
```

1. Expliquer ce qu’il se passe et rectifier le programme.
2. Proposer un autre programme qui effectue la même tâche avec une boucle bornée (boucle `for`).