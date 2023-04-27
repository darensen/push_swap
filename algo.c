/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:09:37 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/27 20:31:00 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_pile **a, t_pile **b, int *tab)
{
	if (lstsize(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			swap_a(a);
	}
	else if (lstsize(*a) == 3)
		tri_3(a);
	else if (lstsize(*a) == 4)
		tri_4(a, b, tab);
	else if (lstsize(*a) == 5)
		tri_5(a, b, tab);
	else if (lstsize(*a) > 5)
	{
		while (lstsize(*a) != 3)
		{
			if (((*a)->content != tab[0])
				&& ((*a)->content != tab[tab_len(tab) / 2])
				&& ((*a)->content != tab[tab_len(tab) - 1]))
				push_b(a, b);
			else
				reverse_rotate_a(a);
		}
		tri_3(a);
		exec(a, b);
	}
}
