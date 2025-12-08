/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:46 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/08 15:11:09 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//sa
void ft_swap(char *c, char *d)
{
	char n;
	n = *c;
	*c = *d;
	*d = n;
}
// trier ?
int ft_istrier(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	char c = 'a';
	char b = 'b';
	printf("%c %c\n",c ,b);
	ft_swap(&c,&b);
	printf("%c %c\n",c ,b);
}