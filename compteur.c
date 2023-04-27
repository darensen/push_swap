/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:52:59 by lusezett          #+#    #+#             */
/*   Updated: 2023/04/27 18:16:42 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_combo(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b)
{
	int	rr;
	int	rrr;
	int	rarrb;
	int	rrarb;

	rrr = 1 + (pile_last(pile_b)->index - index_b);
	if (pile_last(pile_a)->index - index_a > rrr)
		rrr = 1 + pile_last(pile_a)->index;
	rr = index_b;
	if (index_a > index_b)
		rr = index_a;
	rarrb = index_a + (pile_last(pile_b)->index - index_b) + 1;
	rrarb = index_b + (pile_last(pile_a)->index - index_a) + 1;
	if (rr <= rarrb && rr <= rrr && rr <= rrarb)
		return (0);
	if (rrr <= rarrb && rrr <= rr && rrr <= rrarb)
		return (1);
	if (rarrb <= rrarb && rarrb <= rrr && rarrb <= rr)
		return (2);
	if (rrarb <= rarrb && rrarb <= rrr && rrarb <= rr)
		return (3);
	return (0);
}

int	nb_moves(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b)
{
	int	rr;
	int	rrr;
	int	rarrb;
	int	rrarb;

	rrr = 1 + (pile_last(pile_b)->index - index_b);
	if ((pile_last(pile_a)->index - index_a) > rrr)
		rrr = pile_last(pile_a)->index;
	rr = index_b;
	if (index_a > index_b)
		rr = index_a;
	rarrb = index_a + (pile_last(pile_b)->index - index_b) + 1;
	rrarb = index_b + (pile_last(pile_a)->index - index_a) + 1;
	if (rr <= rarrb && rr <= rrr && rr <= rrarb)
		return (rr);
	if (rrr <= rarrb && rrr <= rr && rrr <= rrarb)
		return (rrr);
	if (rarrb <= rrarb && rarrb <= rrr && rarrb <= rr)
		return (rarrb);
	if (rrarb <= rarrb && rrarb <= rrr && rrarb <= rr)
		return (rrarb);
	return (rr);
}

t_struct	optimal_bloc(t_pile **a, t_pile **b)
{
	t_struct	tab;
	t_pile		*temp;

	temp = *b;
	tab.calcul = 5000;
	tab.val = temp->content;
	while (temp)
	{
		if (nb_moves(search(a, temp->content), temp->index, a, b) < tab.calcul)
		{
			tab.calcul = nb_moves(search(a, temp->content), temp->index, a, b);
			tab.val = temp->content;
			tab.index_a = search(a, temp->content);
			tab.index_b = temp->index;
		}
		temp = temp->next;
	}
	return (tab);
}

void	exec_if(t_pile **pile_a, t_pile **pile_b)
{
	t_struct	tab;
	int			combo;

	tab = optimal_bloc(pile_a, pile_b);
	combo = which_combo(tab.index_a, tab.index_b, pile_a, pile_b);
	if (combo == 0)
		mouv_if_rr(pile_a, pile_b, tab);
	if (combo == 1)
		mouv_if_rrr(pile_a, pile_b, tab);
	if (combo == 2)
		mouv_if_rarrb(pile_a, pile_b, tab);
	if (combo == 3)
		mouv_if_rrarb(pile_a, pile_b, tab);
}

void	exec(t_pile **pile_a, t_pile**pile_b)
{
	int	i;

	add_index(pile_a, pile_b);
	i = pile_last(pile_b)->index;
	while (i != -1)
	{
		add_index(pile_a, pile_b);
		exec_if(pile_a, pile_b);
		i--;
	}
	sorted_final(pile_a);
}
