# Allocation dynamique

![cubes](../images/illustration/cubes.jpg)

## Cours

[:material-presentation-play: Afficher le cours :octicons-link-external-24:](https://slides.com/redmo53/optimiser-la-memoire/fullscreen){ .md-button .md-button--primary target="_blank" }

## Exercice 1

Afin de réaliser la saisie une chaîne de caractères, on désire allouer dynamiquement de la mémoire. La taille de cette chaîne sera de 25 caractères. Ecrire la ligne de code nécessaire à cette allocation :

1. avec la fonction `malloc`
 
2. avec la fonction `calloc`
        
3. avec la fonction `realloc`

Refaire l’exercice avec un tableau de 100 `float`.

## Exercice 2

Ecrire un programme permettant de saisir un tableau de nombres décimaux. Ce programme allouera la mémoire pour ce tableau dynamiquement. Le programme :

1. Demandera de saisir la taille n du tableau.

2. Allouera la mémoire nécessaire avec la fonction adaptée (penser à gérer le cas ou l’allocation s’avère impossible à effectuer).

3. Effectuera la saisie des n éléments du tableau.

4. Affichera le tableau.

5. Libèrera l’espace mémoire alloué.