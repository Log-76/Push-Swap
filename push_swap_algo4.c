/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:23:26 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 15:40:17 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back_to_a(int *a, int *b, int total_size)
{
    int best_pos_b;
    int target_pos_a;

    while (count_elements(b, total_size) > 0)
    {
        // 1. On choisit quel élément de B on veut remonter
        best_pos_b = find_best_element_to_push(b, total_size);
        
        // 2. On calcule sa place exacte dans A
        target_pos_a = find_target_pos_in_a(a, b[best_pos_b], total_size);
        
        // 3. On aligne les deux piles
        bring_element_to_top(b, total_size, best_pos_b, 'b');
        bring_element_to_top(a, total_size, target_pos_a, 'a');
        
        // 4. On pousse : l'élément arrive exactement au bon endroit
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
    int threshold;
    int size_a;
    
    // 1. On isole les plus grands dans A
    size_a = count_elements(a, total_size);
    threshold = find_threshold_top_three(a, size_a);
    push_to_b_smart(a, b, total_size, threshold);

    // 2. On vide A vers B jusqu'à ce qu'il n'en reste que 3
    // C'est beaucoup plus sûr que le "while !ft_istrier"
    while (count_elements(a, total_size) > 3)
    {
        ft_pb(a, b, total_size);
    }

    // 3. On trie les 3 piliers (les plus grands du set)
    sort_three(a, total_size);

    // 4. On remonte tout B vers A proprement
    push_back_to_a(a, b, total_size);

    // 5. Rotation finale pour aligner le 1 au sommet
    final_rotation_a(a, total_size);
}
