/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:21:24 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/12 18:21:24 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_if_small(int *a, int *b, int total_size, int threshold)
{
    int size_a = count_elements(a, total_size);
    int rotations = 0;
    
    while (size_a > 3 && rotations < size_a * 2)
    {
        if (a[0] <= threshold)
        {
            ft_pb(a, b, total_size);
            size_a--;
            rotations = 0;
        }
        else
        {
            ft_ra(a, total_size);
            rotations++;
        }
    }
}

void push_rest_to_b(int *a, int *b, int total_size)
{
    while (count_elements(a, total_size) > 3)
        ft_pb(a, b, total_size);
}

void rotate_b_up(int *b, int total_size, int max_pos)
{
    while (max_pos > 0)
    {
        ft_rb(b, total_size);
        max_pos--;
    }
}

void rotate_b_down(int *b, int size_b, int max_pos)
{
    while (max_pos < size_b)
    {
        ft_rrb(b, size_b);
        max_pos++;
    }
}

void bring_max_to_top(int *b, int total_size, int size_b)
{
    int max_pos = find_max_pos(b, size_b);
    
    if (max_pos <= size_b / 2)
        rotate_b_up(b, total_size, max_pos);
    else
        rotate_b_down(b, total_size, max_pos);
}