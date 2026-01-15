/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:46 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/15 15:20:10 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_istrier(int *s, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	numb;
	int		signe;

	i = 0;
	signe = 1;
	numb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			signe = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		numb = numb * 10 + (nptr[i] - '0');
		i++;
	}
	if (signe == -1)
		numb *= -1;
	return ((int)numb);
}

void	ft_ss(int *s, int *s2)
{
	write(1, "ss\n", 3);
	ft_swap(&s[0], &s[1]);
	ft_swap(&s2[0], &s2[1]);
}