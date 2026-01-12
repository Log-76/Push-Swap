/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:47:34 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/12 14:47:34 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_pos(int *stack, int size)
{
	int min;
	int min_pos;
	int i;

	min = stack[0];
	min_pos = 0;
	i = 0;
	while (i < size)
	{
		if(stack[i] < min)
		{
			min = stack[i];
			min_pos = i;
		}
		i++;
	}
	return min_pos;
}

int find_max_pos(int *stack, int size)
{
    int max = stack[0];
    int max_pos = 0;
    int i = 1;
    
    while (i < size)
    {
        if (stack[i] > max)
        {
            max = stack[i];
            max_pos = i;
        }
        i++;
    }
    return max_pos;
}

int count_elements(int *stack, int max_size)
{
    int count = 0;
    int i = 0;
    
    while (i < max_size && stack[i] != 0)
    {
        count++;
        i++;
    }
    return count;
}

void sort_two(int *a)
{
    if (a[0] > a[1])
        ft_sa(a, 2);
}

void sort_three(int *a)
{
	int max_pos;

	max_pos = find_max_pos(a, 3);
    // Si le max est en haut
    if (max_pos == 0)
        ft_ra(a, 3);
    // Si le max est au milieu
    else if (max_pos == 1)
        ft_rra(a, 3);
    // Maintenant le max est en bas, on swap si nécessaire
    if (a[0] > a[1])
        ft_sa(a, 3);
}
