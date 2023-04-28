/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:39:34 by dsenatus          #+#    #+#             */
/*   Updated: 2023/04/28 16:42:25 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile **pile)
{
	t_pile	*tmp;
	int		i;

	tmp = *pile;
	printf("sa\n");
	i = tmp->content;
	if ((*pile)->next != NULL && pile != NULL)
	{
		(*pile)->content = (*pile)->next->content;
		(*pile)->next->content = i;
	}
}

void	swap_b(t_pile **pile)
{
	t_pile	*tmp;
	int		i;

	printf("sb\n");
	tmp = *pile;
	i = tmp->content;
	if ((*pile)->next != NULL && pile != NULL)
	{
		(*pile)->content = (*pile)->next->content;
		(*pile)->next->content = i;
	}
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
}
