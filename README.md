# Push-Swap
vous avez 2 stacks nome a et b.

Au debut:
	La stack a contiens a nombre aleatoire d un unique negative et/ou positive entiers.
	La stack b est vide.

L'objectif est de trier les nombres de la pile a par ordre croissant. Pour ce faire, vous disposez des opérations suivantes :

sa (swap a) : Permute les deux premiers éléments en haut de la pile a.
Ne fait rien s'il n'y a qu'un seul élément ou aucun élément.

sb (swap b) : Permute les deux premiers éléments en haut de la pile b.
Ne fait rien s'il n'y a qu'un seul élément ou aucun élément.

ss : sa et sb en même temps.

pa (push a) : prend le premier élément en haut de b et le place en haut de a.
Ne fait rien si b est vide.

pb (push b) : prend le premier élément en haut de a et le place en haut de b.
Ne fait rien si a est vide.

ra (rotate a) : décale tous les éléments de la pile a d'une position vers le haut.
Le premier élément devient le dernier.

rb (rotate b) : déplacez tous les éléments de la pile b vers le haut de 1.
Le premier élément devient le dernier.

rr : ra et rb en même temps.

rra (reverse rotate a) : déplacez tous les éléments de la pile a vers le bas de 1.
Le dernier élément devient le premier.

rrb (rotation inverse de b) : déplace tous les éléments de la pile b vers le bas de 1.
Le dernier élément devient le premier.

rrr : rra et rrb en même temps.