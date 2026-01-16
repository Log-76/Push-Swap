/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:23:26 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 16:58:50 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(int *a, int *b, int total_size)
{
	int	best_pos_b;
	int	target_pos_a;

	while (count_elements(b, total_size) > 0)
	{
		best_pos_b = find_cheapest_element(a, b, total_size);
		target_pos_a = find_target_pos_in_a(a, b[best_pos_b], total_size);
		bring_element_to_top(b, total_size, best_pos_b, 'b');
		bring_element_to_top(a, total_size, target_pos_a, 'a');
		ft_pa(a, b, total_size);
	}
}

int	find_max_val(int *stack, int size)
{
	int	max;
	int	i;

	if (size <= 0)
		return (0);
	max = stack[0];
	i = 1;
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int	find_threshold_top_three(int *a, int size)
{
	int	*tmp;
	int	threshold;
	int	keep_in_a;

	if (size <= 100)
		keep_in_a = 3;
	else if (size <= 200)
		keep_in_a = 15;
	else
		keep_in_a = 20;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	copy_array(a, tmp, size);
	bubble_sort(tmp, size);
	threshold = tmp[size - keep_in_a - 1];
	free (tmp);
	return (threshold);
}

void	sort_hundred(int *a, int *b, int total_size)
{
	int	size_a;
	int	chunk_size;
	int	current_limit;
	int	threshold;

	size_a = count_elements(a, total_size);
	chunk_size = size_a / 4;
	current_limit = chunk_size;
	while (count_elements(a, total_size) > 3)
	{
		threshold = find_threshold_by_rank(a, size_a, current_limit);
		push_chunk_to_b(a, b, total_size, threshold);
		current_limit += chunk_size;
	}
	sort_three(a, total_size);
	push_back_to_a(a, b, total_size);
	final_alignment(a, total_size);
}
