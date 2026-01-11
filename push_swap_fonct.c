/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fonct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:17:18 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/09 11:17:18 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_rra(int *s, int argc)
{
	int n;
	int i;
	int c[argc + 1];

	n = 0;
	i = 0;
	write(1,"rra\n",4);
	while (i < argc)
		c[i] = s[i++];
	s[n] = c[i];
	while (n < 0)
		s[n] = c[++n];
}

void ft_rrb(int *s2, int argc)
{
	int n;
	int i;
	int c[argc + 1];

	n = 0;
	i = 0;
	write(1,"rrb\n",4);
	while (i < argc)
		c[i] = s2[i++];
	s2[n] = c[i];
	while (n < 0)
		s2[n] = c[++n];
}

int	ft_rrr(int *s, int *s2, int argc)
{
	int	i;
	int n;
	int c[argc+1];

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
		while (n < argc)
		{
			s[i]  = s2[n];
			s2[i--] = c[n];
			n++;
		}
	}
	return (1);
}