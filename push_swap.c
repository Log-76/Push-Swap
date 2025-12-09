/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/09 15:36:19 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(char *a)
{
	char b[ft_strlen(a) + 1];
	int i;

	i = 0;
	while (a[i])
	{
		if (a[i]< 48 && a[i] > 57)
		{
			write(1,"error",5);
			return ;
		}
	}
	while (ft_istrier(a) == 0 && ft_istrier(b) == 0)
	{
		ft_type(&a,&b);
	}
}

void ft_type(char **s, char **s2)
{
	int i;

	i = 0;
	if (s[i] > s[i+1] && s[i+1]!='\0')
	{
		write(1,"sa\n",3);
		ft_swap(&s[i],&s[i+1]);
	}
	else if (s2[i] > s2[i+1] && s2[i] && s2[i+1]!='\0')
	{
		write(1,"sb\n",3);
		ft_swap(&s2[i],&s2[i+1]);
	}
	else if (s2[i] > s2[i+1] && s[i] > s[i+1] && s2[i] && s2[i+1] != '\0')
	{
		write(1,"ss\n",3);
		ft_swap(&s[i],&s[i+1]);
		ft_swap(&s2[i],&s2[i+1]);
	}
	else if (s2[i])
	{
		write(1,"pa\n",3);
		s[ft_strlen(s)] = s2[0];
	}
	else if (s[i])
	{
		write(1,"pb\n",3);
		s2[ft_strlen(s)] = s[0];
	}
	else if (s[i] && s2[i])
	{
		write(1,"rr\n",3);
		s[ft_strlen(s)] = s2[0];
		s2[ft_strlen(s)] = s[0];
	}
}
