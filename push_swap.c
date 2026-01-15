/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/15 15:29:30 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **argv, int argc)
{
	int	*a;
	int	*b;

	a = malloc(argc * sizeof(int));
	b = ft_calloc(argc);
	if (!a || !b || !fill_array(argv, argc, a))
	{
		free(a);
		free(b);
		write(2, "Error\n", 6);
		return ;
	}
	if (has_duplicates(a, argc - 1))
	{
		free(a);
		free(b);
		write(2, "Error\n", 6);
		return ;
	}
	simple_sort(a, b, argc - 1);
	free(a);
	free(b);
}
int *ft_calloc(int argc)
{
	int *b;
	int i;

	i = 0;
	*b = malloc(argc * sizeof(int));
	while (i < argc)
	{
		b[i] = 0;
		i++;
	}
	return(b);
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
	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
		return (0);
	push_swap(argv, argc);
	return (0);
}
