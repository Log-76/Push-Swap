/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:33:46 by lleriche          #+#    #+#             */
/*   Updated: 2025/12/08 15:42:48 by lleriche         ###   ########.fr       */
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
		if (s[i] > s[i+1] && s[i+1]!='\0')
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	char c[] = "bac";
	printf("%d\n",ft_istrier(c));
}