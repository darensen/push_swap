/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:31:32 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/05 16:30:21 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_pile **pile_a, t_pile **pile_b)
{
	//printf("pb\n");
	t_pile *temp;
	temp = *pile_a;
	if(temp == NULL)
		return ;
	if(temp->next == NULL)
	{
		push_number(pile_b, temp->content);
		free(temp);
		*pile_a = NULL;
		return ;
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	t_pile *second_to_last = temp;
	t_pile *last = temp->next;
	second_to_last->next = NULL;
	push_number(pile_b, last->content);
}

void push_a(t_pile **pile_a, t_pile **pile_b)
{
	//printf("pa\n");
	t_pile *temp;
	temp = *pile_b;
	if(temp == NULL)
		return ;
	if(temp->next == NULL)
	{
		push_number(pile_a, temp->content);
		free(temp);
		*pile_b = NULL;
		return ;
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	t_pile *second_to_last = temp;
	t_pile *last = temp->next;
	second_to_last->next = NULL;
	push_number(pile_a, last->content);
}