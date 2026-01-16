/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:21:24 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 16:52:55 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_if_small(int *a, int *b, int total_size, int threshold)
{
	int	size_a;
	int	i;

	size_a = count_elements(a, total_size);
	i = 0;
	while (i < size_a && count_elements(a, total_size) > 3)
	{
		if (a[0] <= threshold)
			ft_pb(a, b, total_size);
		else
			ft_ra(a, total_size);
		i++;
	}
}

void	push_rest_to_b(int *a, int *b, int total_size)
{
	int	size_a;
	int	max;

	while (count_elements(a, total_size) > 3)
	{
		size_a = count_elements(a, total_size);
		max = find_max_val(a, size_a);
		if (a[0] == max)
			ft_ra(a, total_size);
		else
			ft_pb(a, b, total_size);
	}
}

void	rotate_b_up(int *b, int total_size, int max_pos)
{
	while (max_pos > 0)
	{
		ft_rb(b, total_size);
		max_pos--;
	}
}

void	rotate_b_down(int *b, int total_size, int max_pos)
{
	int	size_b;
	int	rotations_needed;

	size_b = count_elements(b, total_size);
	rotations_needed = size_b - max_pos;
	if (rotations_needed < 0)
		return ;
	while (rotations_needed > 0)
	{
		ft_rrb(b, total_size);
		rotations_needed--;
	}
}

void	bring_element_to_top(int *stack, int total_size, int pos, char pile)
{
	int	size;
	int	moves;

	size = count_elements(stack, total_size);
	if (pos == 0 || size <= 1)
		return ;
	if (pos <= size / 2)
	{
		while (pos--)
			do_rotate(stack, total_size, pile, 1);
	}
	else
	{
		moves = size - pos;
		while (moves--)
			do_rotate(stack, total_size, pile, 2);
	}
}
