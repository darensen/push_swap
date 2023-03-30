/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:56:28 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/30 18:01:21 by dsenatus         ###   ########.fr       */
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

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int *tabb;

	i = 0;
	tabb = malloc(sizeof(int) * size);
	while (i != size)
	{
		tabb[i] = tab[i];
		i++;
	}
	i = 0;
	while (i != size)
	{
		j = i + 1;
		while (j != size)
		{
			if (tabb[i] > tabb[j])
				ft_swap(&tabb[i], &tabb[j]);
			j++;
		}
		i++;
	}
	return (tabb);
}
void tri_3(t_pile **pile_a)
{
    t_pile *tmp;
    
    tmp = *pile_a;
	if (tmp->content < tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& tmp->content < tmp->next->next->content) // 123
	{
		reverse_rotate_a(pile_a);
		swap_a(pile_a);
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

int	lst_cont(t_pile **pile)
{
	t_pile *tmp;

	tmp = *pile;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->content);
}

void	tri_5(t_pile **pile_a, t_pile **pile_b, int *tab)
{
	t_pile *tmp;
	t_pile *oui;
	int i;

	tmp = *pile_a;
	oui = *pile_b;
	printf("%d", tab[2]);
	while (lstsize(*pile_a) != 3)
	{
		if (tab[2] > lst_cont(pile_a))
		{
			push_b(pile_a, pile_b);
			print_all(pile_a, pile_b);
		}
		else
			rotate_a(pile_a);
	}
	tri_3(pile_a);
	if ((*pile_b)->content > (*pile_b)->next->content)
		swap_b(pile_b);
	push_a(pile_a, pile_b);
	push_a(pile_a, pile_b);
	printf("oui");
}
