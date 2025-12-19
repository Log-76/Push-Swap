/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/19 17:50:12 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **argv, int argc)
{
	int	*a;
	int	*b;
	int	i;
	int	n;

	a = malloc(argc * sizeof(int) + 1);
	b = malloc(argc * sizeof(int) + 1);
	i = 1;
	n = 0;
	while (i < argc)
		a[n++] = ft_atoi(argv[i++]);
	n = 0;
	while (ft_istrier(a, argc) == 0)
	{
		n = ft_type(a, b);
		if (n == 0)
			n = ft_type2(a, b);
		if (n == 0)
		{
			printf("%d\n",n);
			ft_type5(a, b);
			return ;
		}
		// if (n == 0)
		// 	ft_type4(a, b);
		// if (n == 0)
		// 	ft_type3(a, b);
			
	}
	write(1, "ok\n", 3);
	printf("%d%d%d",a[0],a[1],a[2]);
}

int	ft_type(int *s, int *s2)
{
	int		i;

	i = 0;
	if (s[0] > s[1])
	{
		write(1, "sa\n", 3);
		ft_swap(&s[0], &s[1]);
	}
	else if (s2[i] > s2[i + 1] && s2[i] && s2[i + 1] != 0)
	{
		write(1, "sb\n", 3);
		ft_swap(&s2[i], &s2[i + 1]);
	}
	else if (s2[i] > s2[i + 1] && s[i] > s[i + 1] && s2[i] && s2[i + 1] != 0)
	{
		write(1, "ss\n", 3);
		ft_swap(&s[i], &s[i + 1]);
		ft_swap(&s2[i], &s2[i + 1]);
	}
	else
		return (0);
	return (1);
}

int	ft_type2(int *s, int *s2)
{
	int	n;
	int	i;

	n = 0;
	i = ft_strlen(s);
	if (s2[i])
	{
		write(1, "pa\n", 3);
		s[i] = s2[0];
	}
	else if (s[i])
	{
		write(1, "pb\n", 3);
		s2[i] = s[0];
	}
	else if (s[i] && s2[i])
	{
		write(1, "rr\n", 3);
		s[i] = s2[0];
		s2[i] = s[0];
	}
	else
		return (0);
	return (1);
}

int	ft_type3(int *s, int *s2)
{
	int n;
	int i;
	int c[ft_strlen(s)+1];

	n = 0;
	i = 0;
	if (s[n])
	{
		write(1,"rra\n",4);
		while (s[i])
			c[i] = s[i];
		s[n] = c[i];
		while (n < 0)
			s[--i] = c[++n];
	}
	else if (s[n])
	{
		write(1,"rrb\n",4);
		while (n < 0)
			s[i--] = s2[n++];
	}
	else
		return (0);
	return (1);
}

int	ft_type4(int *s, int *s2)
{
	int	i;
	int n;
	int c[ft_strlen(s)+1];

	i = 0;
	n = 0;
	if (s[i] && s2[i])
	{
		write(1,"rrr\n",4);
		while (s[n])
		{
			c[n] = s[n];
			n++;
		}
		n = 0;
		while (n < ft_strlen(s))
		{
			s[i]  = s2[n];
			s2[i--] = c[n];
			n++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] != '-' && argv[i][n + 1] != '\0' && n == 0)
				i++;
			if ((argv[i][n] <= '0' && argv[i][n] >= '9'))
			{
				write(1, "error\n", 5);
				return (0);
			}
			n++;
		}
		i++;
	}
	push_swap(argv, argc);
}
// faire les verif dans le main envoyer 
// dans push swap une chaine de caractere valide
// passer les valeur en int
// penser a faire ra et rb  
