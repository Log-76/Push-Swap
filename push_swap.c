/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/11 17:03:47 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(char *a)
{
	char *b = NULL;
	int i;

	i = 0;
	
	while (a[i])
	{
		if ((a[i]>= 48 && a[i] <= 57))
		{
			write(1,"error\n",5);
			return ;
		}
		i++;
	}
	i = 0;
	while(a[i])
	{
		if(a[i] == a[i+1])
		{
			write(1,"error\n",5);
			return ;
		}
		i++;		
	}
	while (ft_istrier(a) == 0 && ft_istrier(b) == 0)
	{
		ft_type(&a,&b);
		if (ft_type(&a,&b) == 0)
			ft_type2(&a,&b);
		else if (ft_type2(&a,&b) == 0)
			ft_type3(&a,&b);
	}	
}

int ft_type(char **s, char **s2)
{
	int i;

	i = 0;
	if (s[i] > s[i+1] && s[i+1] != 0)
	{
		write(1,"sa\n",3);
		ft_swap(&s[i],&s[i+1]);
	}
	else if (s2[i] > s2[i+1] && s2[i] && s2[i+1]!= 0 )
	{
		write(1,"sb\n",3);
		ft_swap(&s2[i],&s2[i+1]);
	}
	else if (s2[i] > s2[i+1] && s[i] > s[i+1] && s2[i] && s2[i+1] != 0)
	{
		write(1,"ss\n",3);
		ft_swap(&s[i],&s[i+1]);
		ft_swap(&s2[i],&s2[i+1]);
	}
	else
		return(0);
	return (1);
}
int ft_type2(char **s, char **s2)
{
	int n;
	int i;
	
	n = 0;
	i = ft_strlen(s);
	if (s2[i])
	{
		write(1,"pa\n",3);
		s[i] = s2[0];
	}
	else if (s[i])
	{
		write(1,"pb\n",3);
		s2[i] = s[0];
	}
	else if (s[i] && s2[i])
	{
		write(1,"rr\n",3);
		s[i] = s2[0];
		s2[i] = s[0];
	}
	else
		return(0);
	return (1);
}
void ft_type3(char **s, char **s2)
{
	int n;
	int i;
	char c[ft_strlen(s)+1];

	n = 0;
	i = ft_strlen(s);
	if (s[n])
	{
		write(1,"rra\n",3);
		while (n < 0)
			s2[i--] = s[n++];
	}
	else if (s[n])
	{
		write(1,"rrb\n",3);
		while (n < 0)
			s[i--] = s2[n++];
	}
	else if (s[i] && s2[i])
	{
		write(1,"rrb\n",3);
		while (s[n])
		{
			c[n] = *s[n];
			n++;
		}
		n = 0;
		while (n < ft_strlen(s))
		{
			s[i]  = s2[n];
			s2[i--] = &c[n];
			n++;
		}
	}
}
