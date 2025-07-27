![push_swap](https://github.com/user-attachments/assets/1fc72dd1-b032-49a4-a87c-dc8ca507b60c)

# 42.push_swap

Ce projet est une implémentation du célèbre exercice Push swap, réalisé dans le cadre de la formation 42.

## Description

Push swap est un programme qui trie une pile d’entiers à l’aide d’un nombre limité d’opérations basiques (`push`, `swap`, `rotate`, `reverse rotate`). L’objectif est de trouver l’algorithme le plus efficace, c’est-à-dire celui qui effectue le moins d’opérations possibles pour trier la pile.

## Algorithme utilisé

L’algorithme principal employé ici est un **chunk sort custom et optimisé**.  
Il consiste à diviser la pile en plusieurs sous-ensembles ("chunks") pour optimiser le tri, surtout sur de grandes listes.

**Particularité :**  
L’optimisation du tri une fois les chunks pré-faits prend beaucoup de temps à calculer, car le programme cherche systématiquement les mouvements les plus optimaux pour chaque élément à traiter.  
Cela permet de réduire le nombre total d’opérations, mais augmente significativement le temps de calcul lorsque la taille de la pile grandit.

**Avantages :**
- Permet d’obtenir un nombre d’opérations réduit
- Adapté aux listes de taille moyenne à grande

**Limite :**
- Temps de calcul croissant avec la taille de la pile, à cause de la recherche des mouvements les plus efficients pour chaque chunk

## Test de complexité

Pour mesurer la performance du programme, le Complexity tester de [SimonCROS/push_swap_tester](https://github.com/SimonCROS/push_swap_tester) a été utilisé.

## Benchmarks et visualisation

Des benchmarks ont été réalisés à l’aide du script Complexity tester pour mesurer la performance et l’efficacité de l’algorithme sur différentes tailles de piles.

Pour mieux comprendre le déroulement du tri et les mouvements effectués, le projet a également été testé avec [Push swap visualizer](https://github.com/o-reo/push_swap_visualizer).  
Cet outil permet de visualiser en temps réel les opérations et de vérifier la cohérence du tri généré par l’algorithme.

Des exemples de résultats et de visualisations sont visibles ci-dessous :

<img width="790" height="235" alt="Screenshot from 2025-07-27 13-53-24" src="https://github.com/user-attachments/assets/04adce9a-a35e-4104-beee-a65db340b19a" />
<img width="790" height="235" alt="Screenshot from 2025-07-27 13-50-02" src="https://github.com/user-attachments/assets/a1dd7360-3021-4277-8474-019f179ebd2d" />
<img width="790" height="235" alt="Screenshot from 2025-07-27 14-02-41" src="https://github.com/user-attachments/assets/00835368-0ef7-4290-9ce3-73688f17c034" />

<img width="790" alt="Screenshot from 2025-07-27 13-50-02" src=https://github.com/user-attachments/assets/d9160f88-dbe3-41be-93ea-c096418f5ab6 />


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

LolelsayFR Aka Emaillet ou Emilien
