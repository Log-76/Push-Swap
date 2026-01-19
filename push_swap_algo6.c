/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:34:10 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/19 10:08:44 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	final_alignment(int *a, int total_size)
{
	int	size_a;
	int	min_pos;

	size_a = count_elements(a, total_size);
	min_pos = find_min_pos(a, size_a);
	bring_element_to_top(a, total_size, min_pos, 'a');
}

int	find_cheapest_element(int *a, int *b, int total_size)
{
	int	i;
	int	min_cost;
	int	best_pos;
	int	cost;
	int	target;

	i = 0;
	min_cost = INT_MAX;
	best_pos = 0;
	while (i < count_elements(b, total_size))
	{
		cost = calculate_move_cost(count_elements(b, total_size), i);
		target = find_target_pos_in_a(a, b[i], total_size);
		cost += calculate_move_cost(count_elements(a, total_size), target);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pos = i;
		}
		i++;
	}
	return (best_pos);
}

int	find_threshold_by_rank(int *a, int total_size, int rank)
{
	int	*tmp;
	int	size;
	int	threshold;

	size = count_elements(a, total_size);
	if (size == 0)
		return (0);
	if (rank > size)
		rank = size;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	copy_array(a, tmp, size);
	bubble_sort(tmp, size);
	threshold = tmp[rank - 1];
	free(tmp);
	return (threshold);
}

void	push_chunk_to_b(int *a, int *b, int total_size, int threshold)
{
	int	i;
	int	size_a;

	size_a = count_elements(a, total_size);
	i = 0;
	while (i < size_a && count_elements(a, total_size) > 3)
	{
		if (a[0] <= threshold)
		{
			ft_pb(a, b, total_size);
			if (count_elements(b, total_size) > 1
				&& b[0] < threshold - (threshold / 10))
				ft_rb(b, total_size);
		}
		else
			ft_ra(a, total_size);
		i++;
	}
}

void	do_rotate(int *stack, int total_size, char pile, int type)
{
	if (type == 1)
	{
		if (pile == 'a')
			ft_ra(stack, total_size);
		else
			ft_rb(stack, total_size);
	}
	else
	{
		if (pile == 'a')
			ft_rra(stack, total_size);
		else
			ft_rrb(stack, total_size);
	}
}
