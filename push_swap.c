/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/13 14:03:34 by lleriche         ###   ########.fr       */
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
	simple_sort(a, b, argc - 1);
	write(1, "ok\n", 3);
	printf("%d%d%d%d\n",a[0],a[1],a[2],a[3]);
}

void	simple_sort(int *a, int *b, int size)
{
	if (ft_istrier(a, size))
		return;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b, size);
	else
		sort_hundred(a, b, size);
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
			if ((argv[i][n] < '0' && argv[i][n] > '9'))
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
