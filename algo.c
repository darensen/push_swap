/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:09:37 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/25 19:20:01 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_pile **pile_a, t_pile **pile_b, int *tab)
{
	int len;
	
	len = tab_len(tab);
	if (lstsize(*pile_a) == 2)
	{
		if((*pile_a)->content > (*pile_a)->next->content)
			swap_a(pile_a);
	}
	else if(lstsize(*pile_a) ==  3)
			tri_3(pile_a);
	else if(lstsize(*pile_a) == 4)
			tri_4(pile_a, pile_b, tab);
	else if(lstsize(*pile_a) == 5)
			tri_5(pile_a, pile_b, tab);
	else if(lstsize(*pile_a) > 5)
	{
		while(lstsize(*pile_a) != 3)
		{
			if (((*pile_a)->content != tab[0]) && ((*pile_a)->content != tab[len / 2]) && ((*pile_a)->content != tab[len - 1]))
				pushb_f(pile_a, pile_b);
			else
				reverse_rotate_a(pile_a);
		}
		tri_3(pile_a);
		exec(pile_a, pile_b);
	}
	sorted_final(pile_a);
}
