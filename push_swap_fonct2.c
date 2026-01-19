/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fonct2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:14:24 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/19 10:16:51 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	ft_ra(int *s, int argc)
{
	int	i;
	int	temp;
	int	size;

	size = count_elements(s, argc);
	if (size <= 1)
		return ;
	write(1, "ra\n", 3);
	temp = s[0];
	i = 0;
	while (i < size - 1)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[size - 1] = temp;
}

void	ft_rb(int *s2, int argc)
{
	int	i;
	int	temp;
	int	size;

	size = count_elements(s2, argc);
	if (size <= 1)
		return ;
	write(1, "rb\n", 3);
	temp = s2[0];
	i = 0;
	while (i < size - 1)
	{
		s2[i] = s2[i + 1];
		i++;
	}
	s2[size - 1] = temp;
}

void	ft_sa(int *s, int total_size)
{
	if (count_elements(s, total_size) < 2)
		return ;
	write(1, "sa\n", 3);
	ft_swap(&s[0], &s[1]);
}

void	ft_sb(int *s2)
{
	write(1, "sb\n", 3);
	ft_swap(&s2[0], &s2[1]);
}
