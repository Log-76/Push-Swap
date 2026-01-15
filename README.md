# Push Swap

*Ce projet a été créé dans le cadre du cursus 42 par lleriche.*

## Description

Push Swap est un projet d'algorithme de tri qui met au défi les étudiants de trier des données sur une pile avec un ensemble limité d'opérations, en utilisant le plus petit nombre d'actions possible. Le projet se compose de deux piles (`a` et `b`) et d'un ensemble d'opérations spécifiques pour les manipuler.

L'objectif est de trier une liste aléatoire d'entiers en ordre croissant sur la pile `a`, en utilisant la pile `b` comme pile auxiliaire, tout en minimisant le nombre d'opérations effectuées.

### Opérations Disponibles

- `sa` : swap a - échange les 2 premiers éléments au sommet de la pile a
- `sb` : swap b - échange les 2 premiers éléments au sommet de la pile b
- `ss` : sa et sb en même temps
- `pa` : push a - prend le premier élément au sommet de b et le met au sommet de a
- `pb` : push b - prend le premier élément au sommet de a et le met au sommet de b
- `ra` : rotate a - décale tous les éléments de la pile a vers le haut de 1
- `rb` : rotate b - décale tous les éléments de la pile b vers le haut de 1
- `rr` : ra et rb en même temps
- `rra` : reverse rotate a - décale tous les éléments de la pile a vers le bas de 1
- `rrb` : reverse rotate b - décale tous les éléments de la pile b vers le bas de 1
- `rrr` : rra et rrb en même temps

## Instructions

### Compilation

Pour compiler le projet, exécutez simplement :

```bash
make
```

Cela générera l'exécutable `push_swap`.

### Exécution

Exécutez le programme avec une liste d'entiers en arguments :

```bash
./push_swap 4 67 3 87 23
```

Le programme affichera la liste des opérations nécessaires pour trier les nombres.

### Exemples

```bash
# Exemple avec 3 nombres
./push_swap 2 1 3
# Sortie : sa

# Exemple avec 5 nombres
./push_swap 5 1 4 2 3
# Sortie : pb pb ra pa pa
```

### Gestion des Erreurs

Le programme affiche "Error" sur stderr dans les cas suivants :
- Les arguments ne sont pas des entiers
- Les arguments dépassent les limites d'entiers (INT_MAX ou INT_MIN)
- Des nombres en double sont présents

```bash
./push_swap 1 2 three    # Error: pas un entier
./push_swap 1 2 1        # Error: doublon
./push_swap 2147483648   # Error: dépasse INT_MAX
```

### Tests

Vous pouvez vérifier si la sortie est correcte en utilisant un checker (non inclus dans ce dépôt) :

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Stratégie de l'Algorithme

L'algorithme de tri s'adapte en fonction du nombre d'éléments :

- **2 éléments** : Simple échange si nécessaire
- **3 éléments** : Algorithme optimisé avec maximum 2 opérations
- **4 éléments** : Pousse le minimum vers la pile b, trie les 3 restants, repousse
- **5+ éléments** : Algorithme basé sur des chunks utilisant la médiane comme seuil
  - Pousse les éléments en dessous de la médiane vers la pile b
  - Trie les 3 éléments restants dans la pile a
  - Repousse depuis la pile b en ordre décroissant (le plus grand en premier)

## Structure du Projet

```
.
├── Makefile
├── README.md
├── push_swap.h
├── push_swap.c              # Programme principal et point d'entrée
├── push_swap_utils.c        # Fonctions utilitaires (swap, atoi, etc.)
├── push_swap_validation.c   # Validation des entrées et gestion d'erreurs
├── push_swap_fonct.c        # Opérations sur les piles (pa, pb, rra, rrb, rrr)
├── push_swap_fonct2.c       # Opérations sur les piles (ra, rb, rr, sa, sb)
├── push_swap_algo.c         # Algorithmes de tri (2, 3 éléments)
├── push_swap_algo2.c        # Algorithme de tri (4 éléments) et helpers
├── push_swap_algo3.c        # Helpers de l'algorithme par chunks
└── push_swap_algo4.c        # Tri final et opérations de repousse
```

## Ressources

### Références Classiques

- [Pile (structure de données) - Wikipedia](https://fr.wikipedia.org/wiki/Pile_(informatique))
- [Algorithme de tri - Wikipedia](https://fr.wikipedia.org/wiki/Algorithme_de_tri)
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [42 Docs - Push Swap](https://harm-smits.github.io/42docs/projects/push_swap)

### Utilisation de l'IA

L'IA (Claude) a été utilisée pour les tâches suivantes :

- **Revue de code et débogage** : Identification des erreurs de logique dans la validation des entrées, en particulier la condition de vérification des caractères de nombres valides
- **Implémentation de la gestion d'erreurs** : Conception de la structure pour gérer les trois cas d'erreur requis (non-entiers, dépassement, doublons)
- **Optimisation du code** : Suggestions de méthodes pour refactoriser les fonctions afin de respecter la limite de 25 lignes par fonction
- **Explication de l'algorithme** : Compréhension des différentes approches du problème de tri et des stratégies basées sur les chunks
- **Documentation** : Assistance dans la structuration de ce fichier README selon les exigences de 42

Toute la logique et l'implémentation de l'algorithme principal ont été développées de manière indépendante, l'IA servant d'outil de débogage et de consultation.

## Benchmarks de Performance

Nombre d'opérations cibles pour l'évaluation :

- 3 nombres : maximum 3 opérations
- 5 nombres : maximum 12 opérations
- 100 nombres : moins de 700 opérations pour tous les points (< 900 pour valider)
- 500 nombres : moins de 5500 opérations pour tous les points (< 7000 pour valider)

---

**Note** : Ce projet fait partie du cursus de l'école 42 et respecte les normes de codage de l'école (Norminette).