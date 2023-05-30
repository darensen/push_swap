/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:42:14 by abeaudui          #+#    #+#             */
/*   Updated: 2023/05/22 15:21:34 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*sorted_tab(long *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i != size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			temp = tab[j];
			tab[j] = tab[i];
			tab[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

int	lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	pile_addback(t_pile **lst, t_pile *new)
{
	t_pile	*last;

	if (!(*lst))
		*lst = new;
	else
	{
		last = pile_last(lst);
		last->next = new;
	}
}

void	push_number(t_pile **pile_a, int new_data)
{
	t_pile	*new_element;

	new_element = malloc(sizeof(t_pile));
	if (!new_element)
		return ;
	new_element->content = new_data;
	new_element->next = NULL;
	pile_addback(pile_a, new_element);
}
