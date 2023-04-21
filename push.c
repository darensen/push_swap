/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:31:32 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/21 16:03:51 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_number2(t_pile **pile_a, int new_data)
{
	
	t_pile *new_element = malloc(sizeof(t_pile));
	if (!new_element)
		return ;
	
	new_element->content = new_data;

	new_element->next = NULL;
	pile_addfront(pile_a, new_element);
}

void push_b(t_pile **pile_a, t_pile **pile_b)
{
	printf("pb\n");
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
	push_number2(pile_b, last->content);
}

void push_a(t_pile **pile_a, t_pile **pile_b)
{
	printf("pa\n");
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
	push_number2(pile_a, last->content);
}

void push_f(t_pile **pile_a, t_pile **pile_b)
{
	printf("pa_f");
	t_pile *tmp;
	tmp = *pile_b;
	if (tmp == NULL)
		return ;
	*pile_b = tmp->next;
	push_number2(pile_a, tmp->content);
}