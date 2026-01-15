/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:23:26 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/15 15:15:54 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back_to_a(int *a, int *b, int total_size)
{
    int size_b;
    
    size_b = count_elements(b, total_size);
    while (size_b > 0)
    {
        size_b = count_elements(b, total_size);
        bring_max_to_top(b, total_size, size_b);
        ft_pa(a, b, total_size);
    }
}

void sort_hundred(int *a, int *b, int total_size)
{
    int median;
    int size_a;
    
    size_a = count_elements(a, total_size);
    median = find_median(a, size_a);
    push_if_small(a, b, total_size, median);
    push_rest_to_b(a, b, total_size);
    if (count_elements(a, total_size) == 3)
        sort_three(a);
    push_back_to_a(a, b, total_size);
}