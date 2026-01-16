/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:05:58 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 14:41:37 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
	if (has_duplicates(a, argc))
	{
		free(a);
		free(b);
		write(2, "Error\n", 6);
		return ;
	}
	simple_sort(a, b, argc);
	free(a);
	free(b);
}
int *ft_calloc(int argc)
{
	int *b;
	int i;

	i = 0;
	b = malloc(argc * sizeof(int));
	if (!b)
    	return (NULL);
	while (i < argc)
	{
		b[i] = INT_MIN;
		i++;
	}
	return(b);
}
void simple_sort(int *a, int *b, int size)
{
    if (ft_istrier(a, size))
        return;
    if (size == 2)
        sort_two(a, size);
    else if (size == 3)
        sort_three(a, size);
    else if (size == 4)
        sort_four(a, b, size);
    else if (size == 5)
        sort_five(a, b, size);
    else
        sort_hundred(a, b, size);
}

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		count;
	int		is_split;

	is_split = 0;
	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] != '\0') // Cas "./push_swap "3 1 2""
	{
		args = ft_split(argv[1], ' ');
		count = count_split(args);
		is_split = 1;
	}
	else // Cas "./push_swap 3 1 2"
	{
		args = argv + 1; // On pointe après le nom du programme
		count = argc - 1;
	}
	// On lance le programme avec le bon tableau et le bon nombre d'éléments
	if (count > 0)
		push_swap(args, count);

	// On libère SEULEMENT si on a alloué avec split
	if (is_split)
		free_tab(args, count - 1);
	return (0);
}
