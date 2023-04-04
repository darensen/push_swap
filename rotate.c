/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:00:25 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/25 13:45:36 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_pile **pile)
{
	printf("ra\n");
	t_pile *tmp;
	int i;
	if ((*pile)->next == NULL)
		return ;
	tmp = *pile;
	i = tmp->content;
	while (tmp->next != NULL)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next; 
	}
	tmp->content = i;
}

void rotate_b(t_pile **pile)
{
	printf("rb\n");
	t_pile *tmp;
	int i;
	if (!(*pile)->next)
		return ;
	tmp = *pile;
	i = tmp->content;
	while (tmp->next != NULL)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next; 
	}
	tmp->content = i;
}

void rr(t_pile **pile_a, t_pile **pile_b)
{
    rotate_a(pile_a);
    rotate_b(pile_b);
}