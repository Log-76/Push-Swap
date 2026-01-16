/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:34:01 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 17:05:00 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_move_cost(int size_b, int pos)
{
	int	cost;

	if (pos <= size_b / 2)
		cost = pos;
	else
		cost = size_b - pos;
	return (cost);
}

int	find_best_element_to_push(int *b, int total_size)
{
	int	size_b;
	int	i;
	int	best_pos;
	int	min_cost;
	int	cost;

	size_b = count_elements(b, total_size);
	if (size_b == 0)
		return 0;
	best_pos = find_max_pos(b, size_b);
	min_cost = calculate_move_cost(size_b, best_pos);
	i = 0;
	while (i < size_b)
	{
		cost = calculate_move_cost(size_b, i);
		if (cost < min_cost / 2 && b[i] > b[best_pos] - (size_b / 4))
		{
			min_cost = cost;
			best_pos = i;
		}
		i++;
	}
	return (best_pos);
}

void	final_rotation_a(int *a, int total_size)
{
	int	size;
	int	min_pos;

	size = count_elements(a, total_size);
	min_pos = find_min_pos(a, size);
	if (size <= 1 || min_pos == 0)
		return ;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ft_ra(a, total_size);
			min_pos--;
		}
	}
	else
	{
		int r_moves = size - min_pos;
		while (r_moves > 0)
		{
			ft_rra(a, total_size);
			r_moves--;
		}
	}
}

void	push_to_b_smart(int *a, int *b, int total_size, int threshold)
{
	int	initial_size_a;
	int	pushed = 0;
	int	i = 0;

	initial_size_a = count_elements(a, total_size);
	while (i < initial_size_a && (initial_size_a - pushed) > 3)
	{
		if (a[0] > threshold)
			ft_ra(a, total_size);
		else
		{
			ft_pb(a, b, total_size);
			pushed++;
		}
		i++;
	}
}

void	sort_five(int *a, int *b, int total_size)
{
	int	min_pos;
	int	count;

	count = 0;
	while (count < 2)
	{
		min_pos = find_min_pos(a, count_elements(a, total_size));
		bring_element_to_top(a, total_size, min_pos, 'a');
		ft_pb(a, b, total_size);
		count++;
	}
	sort_three(a, total_size);
	ft_pa(a, b, total_size);
	ft_pa(a, b, total_size);
}
