/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:21 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/16 17:08:07 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit2(char c)
{
	if ((c >= 48 && c <= 57) || (c == '-'))
		return (0);
	return (1);
}

int	is_sorted2(t_pile **pile_a)
{
	t_pile	*tmp;

	tmp = *pile_a;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sorted_final(t_pile **pile_a)
{
	while (is_sorted2(pile_a) == 1)
		reverse_rotate_a(pile_a);
}

int	lst_cont(t_pile **pile)
{
	t_pile	*tmp;

	tmp = *pile;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->content);
}

int	search(t_pile **pile, int val)
{
	t_pile	*temp;
	int		i;
	int		j;

	temp = *pile;
	i = 32767;
	j = find_biggest(pile);
	while (temp)
	{
		if (temp->content <= j && temp->content > val)
		{
			j = temp->content;
			i = temp->index;
		}
		temp = temp->next;
	}
	if (i == 32767)
		return (find_smallest(pile));
	return (i);
}
