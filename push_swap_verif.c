/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:46:29 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/19 10:01:41 by lleriche         ###   ########.fr       */
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

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
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

	i = 0;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		a[i] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int	find_target_pos_in_a(int *a, int val_b, int total_size)
{
	int		i;
	int		size_a;
	int		target_pos;
	long	closest_higher;

	i = 0;
	size_a = count_elements(a, total_size);
	target_pos = 0;
	closest_higher = LONG_MAX;
	while (i < size_a)
	{
		if (a[i] > val_b && a[i] < closest_higher)
		{
			closest_higher = a[i];
			target_pos = i;
		}
		i++;
	}
	if (closest_higher == LONG_MAX)
		return (find_min_pos(a, size_a));
	return (target_pos);
}
