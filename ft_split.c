/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:57:50 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/16 17:18:14 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_number_word(char const *s, char c)
{
	int	in_words;
	int	count;

	count = 0;
	in_words = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && in_words == 0)
		{
			in_words = 1;
			count++;
		}
		else if (*s == c)
		{
			in_words = 0;
		}
		s++;
	}
	return (count);
}

static char	*get_next_word(int *index, const char *str, char c)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (str[*index] == c)
		(*index)++;
	while (str[*index + len] && str[*index + len] != c)
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = str[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

void	free_tab(char **tab, int n)
{
	while (n >= 0)
		free(tab[n--]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;
	int		word;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	word = ft_number_word(s, c);
	tab = malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	while (n < word)
	{
		tab[n] = get_next_word(&i, s, c);
		if (tab[n] == NULL)
			free_tab(tab, n);
		n++;
	}
	tab[n] = NULL;
	return (tab);
}
