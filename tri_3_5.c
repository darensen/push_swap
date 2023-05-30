/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:26:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/22 15:23:07 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_3(t_pile **pile_a)
{
	t_pile	*tmp;
	int		a;
	int		b;
	int		c;

	tmp = *pile_a;
	a = tmp->content;
	b = tmp->next->content;
	c = tmp->next->next->content;
	if (a > b && b > c && a > c)
	{
		swap_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else if (a > b && b < c && a < c)
		swap_a(pile_a);
	else if (a > b && b < c && a > c)
		rotate_a(pile_a);
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_a(pile_a);
		swap_a(pile_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(pile_a);
}

void	tri_4(t_pile **pile_a, t_pile **pile_b, long *tab)
{
	while (lstsize(*pile_a) != 3)
	{
		if ((*pile_a)->content == tab[0])
			push_b(pile_a, pile_b);
		else
			rotate_a(pile_a);
	}
	tri_3(pile_a);
	push_a(pile_a, pile_b);
}

void	tri_5(t_pile **pile_a, t_pile **pile_b, long *tab)
{
	while (lstsize(*pile_a) != 3)
	{
		if ((*pile_a)->content < tab[2])
			push_b(pile_a, pile_b);
		else
			rotate_a(pile_a);
	}
	tri_3(pile_a);
	if ((*pile_b)->content < (*pile_b)->next->content)
		swap_b(pile_b);
	push_a(pile_a, pile_b);
	push_a(pile_a, pile_b);
}
