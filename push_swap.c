/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/16 09:53:20 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(char **argv,int argc)
{
	int *a;
	int *b;
	int i;
	int n;
	
	a = malloc(argc * sizeof(int));
	b = malloc(argc * sizeof(int));
	i = 0;
	a[i] = ft_atoi(argv[i]);
	printf("%s\n",a[0]);
	while (ft_istrier(argv) == 0 && n == 0 )
	{
		n = ft_type(&argv,&b);
		if (n == 0)
			n = ft_type2(&argv,&b);
		else if (n == 0)
			ft_type3(&argv,&b);
	}
	// printf("%s\n",a);
	write(1,"ok\n",3);
}

int ft_type(char **s, char **s2)
{
	int i;
	char *c;

	i = 0;
	if (*s[0] > *s[1])
	{
		write(1,"sa\n",3);
		ft_swap(&s[0],&s[2]);
	}
	else if (s2[i] > s2[i+1] && s2[i] && s2[i+1]!= 0 )
	{
		write(1,"sb\n",3);
		ft_swap(*s2[i],*s2[i+1]);
	}
	else if (s2[i] > s2[i+1] && s[i] > s[i+1] && s2[i] && s2[i+1] != 0)
	{
		write(1,"ss\n",3);
		ft_swap(*s[i],*s[i+1]);
		ft_swap(*s2[i],*s2[i+1]);
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
int main(int argc, char **argv)
{
	int i = 0;
	int n = 0;
	if (argc == 1)
		return 0;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] !='-' && argv[i][n+1] != '\0' && n == 0)
				i++;
			if ((argv[i][n]<= '0' && argv[i][n] >= '9'))
			{
				write(1,"error\n",5);
				return 0;
			}
			n++;
		}
		i++;
	}
	printf("%s\n",argv[1]);
	push_swap(argv,argc);
}
// faire les verif dans le main envoyer dans push swap une chaine de caractere valide
// passer les valeur en int 
