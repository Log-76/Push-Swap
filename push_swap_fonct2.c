/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fonct2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleriche <lleriche@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:14:24 by lleriche          #+#    #+#             */
/*   Updated: 2026/01/12 09:14:24 by lleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ra(int *s, int argc)
{
	int i;
	int temp;

	i = 0;
	write(1, "ra\n", 3);
	temp = s[0]; // sauvegarde
	while (i < argc - 1)
	{
		s[i] = s[i+1];
		i++;
	} // decalage vers le haut 
	s[i] = temp;
}

void	ft_rb(int *s2, int argc)
{
	int i;
	int temp;

	i = 0;
	write(1, "rb\n", 3);
	temp = s2[0]; // sauvegarde
	while (i < argc - 1)
	{
		s2[i] = s2[i+1];
		i++;
	} // decalage vers le haut 
	s2[i] = temp;
}

void	ft_rr(int *s, int *s2, int argc)
{
	int i;
	int temp;

	i = 0;
	write(1, "rr\n", 3);
	if(argc > 1)
	{
		temp = s[0]; // sauvegarde
		while (i < argc - 1)
		{
			s[i] = s[i+1];
			i++;
		} // decalage vers le haut 
		s[i] = temp;
	}
	if(argc > 1)
	{
		temp = s2[0]; // sauvegarde
		while (i < argc - 1)
		{
			s2[i] = s2[i+1];
			i++;
		} // decalage vers le haut 
		s2[i] = temp;
	}
}

void	ft_sa(int *s, int argc)
{
	write(1, "sa\n", 3);
	ft_swap(&s[0], &s[1]);
}

void	ft_sb(int *s2, int argc)
{
	write(1, "sb\n", 3);
	ft_swap(&s2[0], &s2[1]);
}