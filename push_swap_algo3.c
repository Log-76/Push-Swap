/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:21:24 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 15:37:45 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_if_small(int *a, int *b, int total_size, int threshold)
{
    int size_a;
    int i;
    
    size_a = count_elements(a, total_size);
    i = 0;
    // On ne boucle pas plus de fois qu'il n'y a d'éléments au départ
    while (i < size_a && count_elements(a, total_size) > 3)
    {
        if (a[0] <= threshold)
            ft_pb(a, b, total_size);
        else
            ft_ra(a, total_size);
        i++;
    }
}

void push_rest_to_b(int *a, int *b, int total_size)
{
    int size_a;
    int max;

    while (count_elements(a, total_size) > 3)
    {
        size_a = count_elements(a, total_size);
        max = find_max_val(a, size_a); // Il te faut une fonction qui trouve la VALEUR max
    
        if (a[0] == max) // Si c'est le plus grand, on le met au fond pour le protéger
            ft_ra(a, total_size);
        else
            ft_pb(a, b, total_size);
    }
}

void rotate_b_up(int *b, int total_size, int max_pos)
{
    while (max_pos > 0)
    {
        ft_rb(b, total_size);
        max_pos--;
    }
}

void rotate_b_down(int *b, int total_size, int max_pos)
{
    int size_b = count_elements(b, total_size);
    int rotations_needed = size_b - max_pos;
    
    // Sécurité pour éviter la boucle infinie
    if (rotations_needed < 0)
        return ;
    while (rotations_needed > 0)
    {
        ft_rrb(b, total_size);
        rotations_needed--;
    }
}

void bring_element_to_top(int *stack, int total_size, int pos, char pile_name)
{
    int size = count_elements(stack, total_size);
    if (pos == 0) return;
    if (pos <= size / 2)
        while (pos-- > 0)
            (pile_name == 'a') ? ft_ra(stack, total_size) : ft_rb(stack, total_size);
    else
    {
        int r_moves = size - pos;
        while (r_moves-- > 0)
            (pile_name == 'a') ? ft_rra(stack, total_size) : ft_rrb(stack, total_size);
    }
}
