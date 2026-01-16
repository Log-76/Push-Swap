/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:23:26 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 16:04:31 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back_to_a(int *a, int *b, int total_size)
{
    int best_pos_b;
    int target_pos_a;

    while (count_elements(b, total_size) > 0)
    {
        // 1. On trouve l'élément le plus rentable
        best_pos_b = find_cheapest_element(a, b, total_size);
        
        // 2. On trouve sa place dans A
        target_pos_a = find_target_pos_in_a(a, b[best_pos_b], total_size);
        
        // 3. On utilise ta fonction bring_element_to_top pour les deux
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

int find_threshold_top_three(int *a, int size)
{
    int *tmp;
    int threshold;
    int keep_in_a;
    
    // Adaptation du nombre d'éléments à garder dans A
    if (size <= 100)
        keep_in_a = 3;
    else if (size <= 200)
        keep_in_a = 15;  // On garde les 15 plus grands
    else
        keep_in_a = 20;  // Pour 500, on garde les 20 plus grands
    
    tmp = malloc(sizeof(int) * size);
    if (!tmp)
        return (0);
    
    copy_array(a, tmp, size);
    bubble_sort(tmp, size);
    
    // La valeur limite est le (keep_in_a+1)ème plus grand
    threshold = tmp[size - keep_in_a - 1];
    free(tmp);
    return threshold;
}

void sort_hundred(int *a, int *b, int total_size)
{
    int size_a = count_elements(a, total_size);
    int chunk_size = size_a / 4; // Environ 25 nombres par chunk
    int current_limit = chunk_size;

    // 1. Envoyer par chunks vers B
    while (count_elements(a, total_size) > 3)
    {
        // On cherche les 25 plus petits, puis les 25 suivants...
        int threshold = find_threshold_by_rank(a, size_a, current_limit);
        
        push_chunk_to_b(a, b, total_size, threshold);
        current_limit += chunk_size;
    }

    // 2. Finir le travail
    sort_three(a, total_size);
    push_back_to_a(a, b, total_size);
    final_alignment(a, total_size);
}
