/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:46 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/22 14:05:54 by lleriche         ###   ########.fr       */
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
	while (i < argc)
	{
		if (s[i] > s[i + 1] && s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(int *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	numb;
	int	signe;

	i = 0;
	signe = 0;
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
	return (numb);
}

void ft_type5(int *s, int *s2)
{
	int i;
	int n;
	int m;

	i = 0;
	n = 0;
	m = 0;
	if (s[i])
	{
		write(1,"ra\n",3);
		while (s[i])
		{
			s2[i] = s[i];
			i++;
		}
		s[n++] = s2[i-1];
		while (n < i)
			s[n++] = s2[m++];
	}
	else if (s2[i])
	{
		write(1,"rb\n",3);
		while (s[i])
		{
			s[i] = s2[i];
			i++;
		}
		s2[n++] = s[i];
		while (n < i)
			s2[n++] = s[m++];
	}
}
