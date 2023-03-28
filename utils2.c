/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:56:28 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/28 20:43:04 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i != size)
	{
		j = i + 1;
		while (j != size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
void tri_3(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;
    
    tmp = *pile_a;
	if (tmp->content < tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& tmp->content < tmp->next->next->content) // 123
	{
		reverse_rotate_a(pile_a);
	}
	else if (tmp->content > tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& tmp->content < tmp->next->next->content) // 213
		reverse_rotate_a(pile_a);
	else if (tmp->content > tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& tmp->content > tmp->next->next->content) // 312 ok
		{
			swap_a(pile_a);
		}
	else if (tmp->content < tmp->next->content
		&& tmp->next->content > tmp->next->next->content
		&& tmp->content < tmp->next->next->content) // 132
	{
		rotate_a(pile_a);
	}
	else if (tmp->content < tmp->next->content
		&& tmp->next->content > tmp->next->next->content
		&& tmp->content > tmp->next->next->content) // 231
		{
			rotate_a(pile_a);
			swap_a(pile_a);
		}
}

