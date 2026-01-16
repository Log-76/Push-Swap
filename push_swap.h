/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:35:05 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 15:39:33 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

/* ************************************************************************** */
/*                         OPERATIONS DE BASE                                 */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);
void	ft_sa(int *s, int total_size);
void	ft_sb(int *s2);
void	ft_ss(int *s, int *s2);

/* ************************************************************************** */
/*                         OPERATIONS PUSH                                    */
/* ************************************************************************** */

void	ft_pa(int *s, int *s2, int argc);
void	ft_pb(int *s, int *s2, int argc);

/* ************************************************************************** */
/*                         OPERATIONS ROTATE                                  */
/* ************************************************************************** */

void	ft_ra(int *s, int argc);
void	ft_rb(int *s2, int argc);
void	ft_rr(int *s, int *s2, int argc);

/* ************************************************************************** */
/*                         OPERATIONS REVERSE ROTATE                          */
/* ************************************************************************** */

void	ft_rra(int *s, int argc);
void	ft_rrb(int *s2, int argc);
void	ft_rrr(int *s, int *s2, int argc);

/* ************************************************************************** */
/*                         FONCTIONS UTILITAIRES                              */
/* ************************************************************************** */

int		ft_atoi(const char *nptr);
int		ft_istrier(int *s, int argc);
int		count_elements(int *stack, int max_size);
int		*ft_calloc(int argc);

/* ************************************************************************** */
/*                         FONCTIONS DE RECHERCHE                             */
/* ************************************************************************** */

int		find_min_pos(int *stack, int size);
int		find_max_pos(int *stack, int size);
int		find_max_val(int *stack, int size);
int		find_median(int *stack, int size);
int		find_threshold_top_three(int *a, int size);

/* ************************************************************************** */
/*                         ALGORITHMES DE TRI                                 */
/* ************************************************************************** */

void	simple_sort(int *a, int *b, int size);
void	sort_two(int *a, int total_size);
void	sort_three(int *a, int total_size);
void	sort_four(int *a, int *b, int total_size);
void	sort_five(int *a, int *b, int total_size);
void	sort_hundred(int *a, int *b, int total_size);

/* ************************************************************************** */
/*                         FONCTIONS HELPER ALGO                              */
/* ************************************************************************** */

void	copy_array(int *src, int *dst, int size);
void	bubble_sort(int *arr, int size);
void	push_back_to_a(int *a, int *b, int total_size);
void	bring_max_to_top(int *b, int total_size, int size_b);

/* ************************************************************************** */
/*                         NOUVELLES FONCTIONS OPTIMISÉES                     */
/* ************************************************************************** */

int		calculate_move_cost(int size_b, int pos);
int		find_best_element_to_push(int *b, int total_size);
void	bring_element_to_top(int *stack, int total_size, int pos, char pile_name);
void	push_to_b_smart(int *a, int *b, int total_size, int threshold);
void	final_rotation_a(int *a, int total_size);

/* ************************************************************************** */
/*                         VALIDATION ET PARSING                              */
/* ************************************************************************** */

int		is_valid_number(char *str);
int		check_args(int argc, char **argv);
int		has_duplicates(int *arr, int size);
int		fill_array(char **argv, int argc, int *a);

/* ************************************************************************** */
/*                         GESTION DES STRINGS                                */
/* ************************************************************************** */

int		count_split(char **split);
int		ft_number_word(char const *s, char c);
void	free_tab(char **tab, int n);
char	**ft_split(char const *s, char c);
int		find_target_pos_in_a(int *a, int val_b, int total_size);
void	final_alignment(int *a, int total_size);
#endif