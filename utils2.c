/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:35:54 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/26 19:47:06 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest(t_pile **pile)
{
	int max;
	t_pile *temp;
	
	temp = *pile;
	max = temp->content;
	while (temp->next != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return(max);
}

int find_smallest(t_pile **pile)
{
	int min;
	t_pile *temp;
	
	temp = *pile;
	min = temp->content;
	while (temp->next != NULL)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return(min);
}

t_pile *add_index_a(t_pile **pile_a)
{
	t_pile *temp1;
	int i;
	
	i = 0;
	temp1 = *pile_a;
	while (temp1->next != NULL )
	{
		temp1->index = i;
		temp1 = temp1->next;
		i++;
	}
	temp1->index = i;

	return(temp1);

}

t_pile *add_index_b(t_pile **pile_b)
{
	t_pile *temp1;
	int i;
	
	i = 0;
	temp1 = *pile_b;
	while (temp1->next != NULL )
	{
		temp1->index = i;
		temp1 = temp1->next;
		i++;
	}
	temp1->index = i;
	return(temp1);

}

void add_index(t_pile **pile_a, t_pile **pile_b)
{
	add_index_a(pile_a);
	add_index_b(pile_b);
}