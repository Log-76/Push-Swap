/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:21:31 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/13 09:42:57 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_four(int *a, int *b, int total_size)
{
    int min_pos;
    
    // Trouver le minimum et le pousser vers B
    min_pos = find_min_pos(a, 4);
    // Amener le min en haut
    if (min_pos == 1)
        ft_sa(a);
    else if (min_pos == 2)
    {
        ft_rra(a, total_size);
        ft_rra(a, total_size);
    }
    else if (min_pos == 3)
        ft_rra(a, total_size);
    
    // Push le min vers B
    ft_pb(a, b, total_size);
    // Trier les 3 restants
    sort_three(a);
    // Repousser le min
    ft_pa(a, b, total_size);
}

void push_small_to_b(int *a, int *b, int total_size, int seuil)
{
    int size_a;
    int rotations;

	size_a = count_elements(a, total_size);
	rotations = 0;
    while (size_a > 3 && rotations < size_a * 2)
    {
        // Si l'élément en haut est petit (sous le seuil)
        if (a[0] <= seuil)
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

void copy_array(int *src, int *dst, int size)
{
    int i = 0;
    
    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
}

void bubble_sort(int *arr, int size)
{
    int i = 0;
    int j, temp;
    
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int find_median(int *stack, int size)
{
    int *sorted = malloc(sizeof(int) * size);
    int median;
    
    copy_array(stack, sorted, size);
    bubble_sort(sorted, size);
    median = sorted[size / 2];
    free(sorted);
    return median;
}