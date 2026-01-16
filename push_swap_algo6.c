/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:34:10 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 15:40:32 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void final_alignment(int *a, int total_size)
{
    int size_a = count_elements(a, total_size);
    int min_pos = find_min_pos(a, size_a);
    
    // On amène le minimum au sommet par le chemin le plus court
    bring_element_to_top(a, total_size, min_pos, 'a');
}