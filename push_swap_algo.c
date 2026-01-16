/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:47:34 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 16:34:19 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_min_pos(int *stack, int size)
{
	int	min;
	int	min_pos;
	int	i;

	min = stack[0];
	min_pos = 0;
	i = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

int	find_max_pos(int *stack, int size)
{
	int	max;
	int	max_pos;
	int	i;

	max = stack[0];
	max_pos = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

int	count_elements(int *stack, int max_size)
{
	int	i;

	i = 0;
	while (i < max_size && stack[i] != INT_MIN)
	{
		i++;
	}
	return (i);
}

void	sort_two(int *a, int total_size)
{
	if (a[0] > a[1])
		ft_sa(a, total_size);
}

void	sort_three(int *a, int total_size)
{
	int	max_pos;
	int	size;

	size = count_elements(a, total_size);
	if (size < 2)
		return ;
	if (size == 2)
	{
		if (a[0] > a[1])
			ft_sa(a, total_size);
		return ;
	}
	max_pos = find_max_pos(a, 3);
	if (max_pos == 0)
		ft_ra(a, total_size);
	else if (max_pos == 1)
		ft_rra(a, total_size);
	if (a[0] > a[1])
		ft_sa(a, total_size);
}
