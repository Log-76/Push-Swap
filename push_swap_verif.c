/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:46:29 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 16:19:46 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int has_duplicates(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	// On doit aller jusqu'à l'avant dernier élément (i < size) 
	// et comparer avec le suivant jusqu'au dernier inclus (j <= size)
	while (i < size)
	{
		j = i + 1;
		while (j <= size) // <--- ICI : le "=" est crucial
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_array(char **argv, int argc, int *a)
{
	int	i;

	i = 0; // On commence à 0 car le main a déjà fait le tri
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		a[i] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}
int find_target_pos_in_a(int *a, int val_b, int total_size)
{
	int i;
	int size_a = count_elements(a, total_size);
	int target_pos = 0;
	long closest_higher = LONG_MAX;

	i = 0;
	// On cherche le plus petit nombre dans A qui est supérieur à val_b
	while (i < size_a)
	{
		if (a[i] > val_b && a[i] < closest_higher)
		{
			closest_higher = a[i];
			target_pos = i;
		}
		i++;
	}
	// Si val_b est plus grand que tout le monde dans A, 
	// il doit se placer au-dessus du MINIMUM de A pour boucler le cycle
	if (closest_higher == LONG_MAX)
		return (find_min_pos(a, size_a));
	return (target_pos);
}
