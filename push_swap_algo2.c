/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:21:31 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 11:40:14 by lleriche         ###   ########.fr       */
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
        ft_sa(a, total_size);
    else if (min_pos == 2)
    {
        ft_rra(a, 4);
        ft_rra(a, 4);
    }
    else if (min_pos == 3)
        ft_rra(a, 4);
    
    // Push le min vers B
    ft_pb(a, b, total_size);
    // Trier les 3 restants
    sort_three(a, total_size);
    // Repousser le min
    ft_pa(a, b, total_size);
}

void push_small_to_b(int *a, int *b, int total_size, int seuil)
{
	int size_a;
	int checked;

	size_a = count_elements(a, total_size);
	checked = 0;
	
	// ✅ Parcourir la stack une seule fois
	while (size_a > 3 && checked < size_a)
	{
		if (a[0] <= seuil)
		{
			ft_pb(a, b, total_size);
			size_a--;
			checked = 0;  // Réinitialiser car la stack a changé
		}
		else
		{
			ft_ra(a, total_size);
			checked++;
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