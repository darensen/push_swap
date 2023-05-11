/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:17:30 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/11 19:58:57 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_last(t_pile **pile)
{
	t_pile	*lst;

	lst = *pile;
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	pile_addfront(t_pile **lst, t_pile *new)
{
	if (!(*lst) || !new)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
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

int	*fill_tab(char **av, int ac, int ac0)
{
	int	i;
	int	*tab;
	int	temp;
	char **str;
	
	tab = malloc(sizeof(int) * ac);
	if (!tab)
		return (0);
	i = 0;
	temp = 1;
	if (ac0 == 2)
	{
		str = ft_split(av[1], ' ');
		temp = 0;
		while (i != ac - 1)
		{		
			tab[i] = ft_atoi(str[temp]);
			i++;
			temp++;
		}
		return (tab);
	}
	while (i != ac0 - 1)
	{
		tab[i] = ft_atoi(av[temp]);
		i++;
		temp++;
	}
	return (tab);
}
