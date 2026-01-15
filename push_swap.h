/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:35:05 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/15 16:31:35 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b);
int		ft_atoi(const char *nptr);
void	ft_sa(int *s);
void	ft_sb(int *s2);
void	ft_ss(int *s, int *s2);
void	ft_pa(int *s, int *s2, int argc);
void	ft_pb(int *s, int *s2, int argc);
void	ft_ra(int *s, int argc);
void	ft_rb(int *s2, int argc);
void	ft_rr(int *s, int *s2, int argc);
void	ft_rra(int *s, int argc);
void	ft_rrb(int *s2, int argc);
void	ft_rrr(int *s, int *s2, int argc);
int		ft_istrier(int *s, int argc);
int		ft_type(int *s, int *s2);
int		find_min_pos(int *stack, int size);
int		find_max_pos(int *stack, int size);
int		count_elements(int *stack, int max_size);
void	sort_two(int *a);
void	sort_three(int *a);
void	sort_four(int *a, int *b, int total_size);
void	push_small_to_b(int *a, int *b, int total_size, int seuil);
void	copy_array(int *src, int *dst, int size);
void	bubble_sort(int *arr, int size);
int		find_median(int *stack, int size);
void	push_if_small(int *a, int *b, int total_size, int threshold);
void	push_rest_to_b(int *a, int *b, int total_size);
void	rotate_b_up(int *b, int total_size, int max_pos);
void	rotate_b_down(int *b, int size_b, int max_pos);
void 	bring_max_to_top(int *b, int total_size, int size_b);
void	push_back_to_a(int *a, int *b, int total_size);
void	sort_hundred(int *a, int *b, int total_size);
void	simple_sort(int *a, int *b, int size);
int		is_valid_number(char *str);
int		check_args(int argc, char **argv);
int		has_duplicates(int *arr, int size);
int		fill_array(char **argv, int argc, int *a);
int		*ft_calloc(int argc);