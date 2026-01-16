/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fonct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:17:18 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 17:09:18 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_rra(int *s, int argc)
{
	int	i;
	int	temp;
	int	size;

	size = count_elements(s, argc);
	if (size <= 1)
		return ;
	write(1, "rra\n", 4);
	temp = s[size - 1];
	i = size - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[0] = temp;
}

void	ft_rrb(int *s2, int argc)
{
	int	i;
	int	temp;
	int	size;

	size = count_elements(s2, argc);
	if (size <= 1)
		return ;
	write(1, "rrb\n", 4);
	temp = s2[size - 1];
	i = size - 1;
	while (i > 0)
	{
		s2[i] = s2[i - 1];
		i--;
	}
	s2[0] = temp;
}

void	ft_rrr(int *s, int *s2, int argc)
{
	int	i;
	int	t;
	int	sz_a;
	int	sz_b;

	sz_a = count_elements(s, argc);
	sz_b = count_elements(s2, argc);
	write(1, "rrr\n", 4);
	t = s[sz_a - 1];
	if (sz_a > 1 && t)
	{
		i = sz_a;
		while (--i > 0)
			s[i] = s[i - 1];
		s[0] = t;
	}
	t = s2[sz_b - 1];
	if (sz_b > 1 && t)
	{
		i = sz_b;
		while (--i > 0)
			s2[i] = s2[i - 1];
		s2[0] = t;
	}
}

void	ft_pa(int *a, int *b, int argc)
{
	int	i;
	int	size_a;
	int	size_b;

	size_a = count_elements(a, argc);
	size_b = count_elements(b, argc);
	if (size_b == 0)
		return ;
	write(1, "pa\n", 3);
	i = size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = INT_MIN;
}

void	ft_pb(int *a, int *b, int argc)
{
	int	i;
	int	size_a;
	int	size_b;

	size_a = count_elements(a, argc);
	size_b = count_elements(b, argc);
	if (size_a == 0)
		return ;
	write(1, "pb\n", 3);
	i = size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = INT_MIN;
}
