![push_swap](https://github.com/user-attachments/assets/1fc72dd1-b032-49a4-a87c-dc8ca507b60c)

# 42.push_swap

Ce projet est une implémentation du célèbre exercice Push swap, réalisé dans le cadre de la formation 42.

## Description

Push swap est un programme qui trie une pile d'entiers à l'aide d'un nombre limité d'opérations basiques (push, swap, rotate, reverse rotate). L'objectif est de trouver l'algorithme le plus efficace, c'est-à-dire celui qui effectue le moins d'opérations possibles pour trier la pile.

## Algorithme utilisé

L'algorithme principal employé ici est un chunk sort custom et optimisé.
Il consiste à diviser la pile en plusieurs sous-ensembles ("chunks") pour optimiser le tri, surtout sur de grandes listes.

Particularité :
L'optimisation du tri des chunks pré-faits prend beaucoup de temps à calculer, car le programme cherche systématiquement les mouvements les plus optimaux pour chaque élément à traiter.
Cela permet de réduire le nombre total d'opérations, mais augmente significativement le temps de calcul lorsque la taille de la pile grandit.

Avantages :
- Permet d'obtenir un nombre d'opérations réduit
- Adapté aux listes de taille moyenne à grande

Limite :
- Temps de calcul croissant avec la taille de la pile, à cause de la recherche des mouvements les plus efficients pour chaque chunk

## Test de complexité

Pour mesurer la performance du programme, le Complexity tester de SimonCROS/push_swap_tester a été utilisé.

## Benchmarks et visualisation

Des benchmarks ont été réalisés à l'aide du script Complexity tester pour mesurer la performance et l'efficacité de l'algorithme sur différentes tailles de piles.

Pour mieux comprendre le déroulement du tri et les mouvements effectués, le projet a également été testé avec Push swap visualizer. Cet outil permet de visualiser en temps réel les opérations et de vérifier la cohérence du tri généré par l'algorithme.

Des exemples de résultats et de visualisations sont visibles ci-dessous :

![image1](image1)
![image2](image2)
![image3](image3)

(Les résultats seront ajoutés après upload des images)

## Compilation et utilisation

```
make
./push_swap [liste_d_entiers]
```

## Exemple

```
./push_swap 3 2 1
```

## Auteur

LolelsayFR
