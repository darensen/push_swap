/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:17:30 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/26 19:20:29 by abeaudui         ###   ########.fr       */
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

int *fill_tab(char **av, int ac)
{
	int i;
	int *tab;
	int temp = ac - 1;
	tab = malloc(sizeof(int) * ac);

	i = 0;
	while(i != ac - 1 ) 
	{
		
		tab[i++] = ft_atoi(av[temp--]);
		
	}
	return (tab);
}