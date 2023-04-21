/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:17:30 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/21 16:38:12 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_last(t_pile **pile)
{
	t_pile *lst;

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
	int	i;
	int	*tab;
	int	temp = ac - 1;
	
	tab = malloc(sizeof(int) * ac);
	i = 0;
	while (i != ac - 1) 
	{
		
		tab[i++] = ft_atoi(av[temp--]);
		
	}
	return (tab);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	signe = 1;
	nb = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nptr[i] - 48) + nb * 10;
		i++;
	}
	return (nb * signe);
}