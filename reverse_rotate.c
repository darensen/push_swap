/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:08:52 by dsenatus          #+#    #+#             */
/*   Updated: 2023/04/30 17:51:17 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*first;
	t_pile	*last;
	t_pile	*second_to_last;

	ft_printf("rra\n");
	if (!(*pile)->next)
		return ;
	temp = *pile;
	first = temp;
	while (temp->next->next != NULL)
		temp = temp->next;
	second_to_last = temp;
	last = temp->next;
	second_to_last->next = NULL;
	last->next = first;
	*pile = last;
}

void	reverse_rotate_b(t_pile **pile)
{	
	t_pile	*temp;
	t_pile	*first;
	t_pile	*last;
	t_pile	*second_to_last;

	ft_printf("rrb\n");
	if (!(*pile)->next)
		return ;
	temp = *pile;
	first = temp;
	while (temp->next->next != NULL)
		temp = temp->next;
	second_to_last = temp;
	last = temp->next;
	second_to_last->next = NULL;
	last->next = first;
	*pile = last;
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
}
