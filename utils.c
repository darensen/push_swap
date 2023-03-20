/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:17:30 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/20 14:11:02 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_last(t_pile *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


void	pile_addback(t_pile **lst, t_pile *new)
{
	t_pile	*last;

	if (!(*lst))
		*lst = new;
	else
	{
		last = pile_last(*(lst));
		last->next = new;
	}
}

void push_number(t_pile **pile_a, int new_data)
{
	
	t_pile *new_element = malloc(sizeof(t_pile));
	if (!new_element)
		return ;
	
	new_element->content = new_data;
	new_element->next = NULL;
	pile_addback(pile_a, new_element);
}

