/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:34:10 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 16:07:56 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void final_alignment(int *a, int total_size)
{
    int size_a = count_elements(a, total_size);
    int min_pos = find_min_pos(a, size_a);
    
    // On amène le minimum au sommet par le chemin le plus court
    bring_element_to_top(a, total_size, min_pos, 'a');
}

int find_cheapest_element(int *a, int *b, int total_size)
{
    int i = 0;
    int size_b = count_elements(b, total_size);
    int min_cost = INT_MAX;
    int best_pos = 0;

    while (i < size_b)
    {
        int cost_b = (i <= size_b / 2) ? i : (size_b - i);
        int target_a = find_target_pos_in_a(a, b[i], total_size);
        int size_a = count_elements(a, total_size);
        int cost_a = (target_a <= size_a / 2) ? target_a : (size_a - target_a);

        if (cost_a + cost_b < min_cost)
        {
            min_cost = cost_a + cost_b;
            best_pos = i;
        }
        i++;
    }
    return best_pos;
}
int find_threshold_by_rank(int *a, int total_size, int rank)
{
    int *tmp;
    int size;
    int threshold;

    size = count_elements(a, total_size);
    if (size == 0) return (0);
    if (rank > size) rank = size;

    tmp = malloc(sizeof(int) * size);
    if (!tmp) return (0);
    
    copy_array(a, tmp, size);
    bubble_sort(tmp, size);
    
    // Le seuil est la valeur à l'index rank - 1
    threshold = tmp[rank - 1];
    
    free(tmp);
    return (threshold);
}
void push_chunk_to_b(int *a, int *b, int total_size, int threshold)
{
    int i;
    int size_a;

    size_a = count_elements(a, total_size);
    i = 0;
    // On fait un tour complet de la pile A actuelle
    while (i < size_a && count_elements(a, total_size) > 3)
    {
        if (a[0] <= threshold)
        {
            ft_pb(a, b, total_size);
            // OPTI : Si l'élément est petit, on le met au fond de B (pré-tri)
            if (count_elements(b, total_size) > 1 && b[0] < threshold - (threshold / 10))
                ft_rb(b, total_size);
        }
        else
            ft_ra(a, total_size);
        i++;
    }
}