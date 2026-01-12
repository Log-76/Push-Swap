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

void	ft_rra(int *s, int argc)
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

void	ft_rrb(int *s2, int argc)
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

void	ft_rrr(int *s, int *s2, int argc)
{
	int	i;
	int temp;

	i = 0;
	write(1,"rrr\n",4);
	temp = s[argc - 1];
	i = argc - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[0] = temp;
	temp = s2[argc - 1];
	i = argc - 1;
	while (i > 0)
	{
		s2[i] = s2[i - 1];
		i--;
	}
	s2[0] = temp;
}

void ft_pa(int *s, int *s2, int argc)
{
	int i;

	i = argc - 1;
	write(1, "pa\n", 3);
	// systeme de decalage de 1 pour faire de la place au debut de la stack
	while (i > 0)
    {
        s[i] = s[i - 1];
        i--;
    }
	s[0] = s2[0];
	i++;
	// Décaler tous les éléments de a vers le haut
	while (i < argc - 1)
	{
		s[i] = s[i + 1];
        i++;
	}
}

void ft_pb(int *s, int *s2, int argc)
{
	int i;

	i = argc - 1;
	write(1, "pb\n", 3);
	// systeme de decalage de 1 pour faire de la place au debut de la stack
	while (i > 0)
    {
        s2[i] = s2[i - 1];
        i--;
    }
	s2[0] = s[0];
	i++;
	// Décaler tous les éléments de a vers le haut
	while (i < argc - 1)
	{
		s2[i] = s2[i + 1];
        i++;
	}
}