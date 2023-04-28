/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:31:32 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/28 19:54:51 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_number2(t_pile **pile_a, int new_data)
{
	t_pile	*new_element;

	new_element = malloc(sizeof(t_pile));
	if (!new_element)
		return ;
	new_element->content = new_data;
	new_element->next = NULL;
	pile_addfront(pile_a, new_element);
}

void	push_a(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	printf("pa\n");
	tmp = *pile_b;
	if (tmp == NULL)
		return ;
	*pile_b = tmp->next;
	push_number2(pile_a, tmp->content);
	free(tmp);
}

void	push_b(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	printf("pb\n");
	tmp = *pile_a;
	if (tmp == NULL)
		return ;
	*pile_a = tmp->next;
	push_number2(pile_b, tmp->content);
	free(tmp);
}
