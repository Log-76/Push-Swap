/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:46 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/15 17:29:42 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sa
void ft_swap(char **c, char **d)
{
	char **n;
	*n = *c;
	*c = *d;
	*d = *n;
}
// trier ?
int ft_istrier(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] > s[i+1] && s[i+1]!='\0')
			return (0);
		i++;
	}
	return (1);
}
int ft_strlen(char **a)
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}