/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:34:01 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 15:17:25 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_move_cost(int size_b, int pos)
{
    int cost;
    
    // Coût pour amener cet élément en haut de B
    if (pos <= size_b / 2)
        cost = pos;  // Rotation normale
    else
        cost = size_b - pos;  // Reverse rotation
    
    return cost;
}

int find_best_element_to_push(int *b, int total_size)
{
    int size_b;
    int i;
    int best_pos;
    int min_cost;
    int cost;
    
    size_b = count_elements(b, total_size);
    if (size_b == 0)
        return 0;
    // On cherche d'abord le maximum (priorité)
    best_pos = find_max_pos(b, size_b);
    min_cost = calculate_move_cost(size_b, best_pos);
    // Mais si un autre gros élément est plus proche, on le prend
    i = 0;
    while (i < size_b)
    {
        cost = calculate_move_cost(size_b, i);
        // Si c'est beaucoup moins cher et que c'est quand même une grande valeur
        if (cost < min_cost / 2 && b[i] > b[best_pos] - (size_b / 4))
        {
            min_cost = cost;
            best_pos = i;
        }
        i++;
    }
    return best_pos;
}

void final_rotation_a(int *a, int total_size)
{
    int size;
    int min_pos;

    size = count_elements(a, total_size);
    if (size <= 1)
        return ;
    // On trouve où se cache le plus petit nombre (le 1)
    min_pos = find_min_pos(a, size);
    // Si le min est déjà en haut (pos 0), on ne fait rien
    if (min_pos == 0)
        return ;
    // Strategie du chemin le plus court
    if (min_pos <= size / 2)
    {
        // Le min est dans la première moitié : on utilise ra
        while (min_pos > 0)
        {
            ft_ra(a, total_size);
            min_pos--;
        }
    }
    else
    {
        // Le min est dans la seconde moitié : on utilise rra
        int r_moves = size - min_pos;
        while (r_moves > 0)
        {
            ft_rra(a, total_size);
            r_moves--;
        }
    }
}

void push_to_b_smart(int *a, int *b, int total_size, int threshold)
{
    int initial_size_a = count_elements(a, total_size);
    int pushed = 0;
    int i = 0;

    // On ne fait pas plus de tours que d'éléments présents au départ
    while (i < initial_size_a && (initial_size_a - pushed) > 3)
    {
        if (a[0] > threshold)
            ft_ra(a, total_size);
        else
        {
            ft_pb(a, b, total_size);
            pushed++;
            // Optionnel : ft_rb si b[0] < median pour pré-trier B
        }
        i++;
    }
}

void sort_five(int *a, int *b, int total_size)
{
    int min_pos;
    int count;
    
    // Pousse les 2 plus petits vers B
    count = 0;
    while (count < 2)
    {
        min_pos = find_min_pos(a, count_elements(a, total_size));
        // Amène le min en haut par le chemin le plus court
        if (min_pos <= 2)
        {
            while (min_pos > 0)
            {
                ft_ra(a, total_size);
                min_pos--;
            }
        }
        else
        {
            while (min_pos < 5 - count)
            {
                ft_rra(a, total_size);
                min_pos++;
            }
        }
        ft_pb(a, b, total_size);
        count++;
    }
    // Trie les 3 restants
    sort_three(a, total_size);
    // Ramène les 2 éléments
    ft_pa(a, b, total_size);
    ft_pa(a, b, total_size);
}
