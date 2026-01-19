/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:15:11 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/19 10:16:39 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_array(int *s, int size)
{
	int	temp;
	int	i;

	if (size < 2)
		return ;
	temp = s[0];
	i = 0;
	while (i < size - 1)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[size - 1] = temp;
}

void	ft_rr(int *s, int *s2, int argc)
{
	int	size_a;
	int	size_b;

	size_a = count_elements(s, argc);
	size_b = count_elements(s2, argc);
	if (size_a < 2 && size_b < 2)
		return ;
	rotate_array(s, size_a);
	rotate_array(s2, size_b);
	write(1, "rr\n", 3);
}
