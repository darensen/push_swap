/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:09:37 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/21 18:32:19 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_pile **pile_a, t_pile **pile_b, int *tab)
{
	int len;
	
	len = tab_len(tab);
	if(lstsize(*pile_a) ==  3)
			tri_3(pile_a);
	else if(lstsize(*pile_a) == 4)
			tri_4(pile_a, pile_b);
	else if(lstsize(*pile_a) == 5)
			tri_5(pile_a, pile_b);
	else if(lstsize(*pile_a) > 5)
	{
		while(lstsize(*pile_a) != 3)
		{
			if ((lst_cont(pile_a) != tab[0]) && (lst_cont(pile_a) != tab[len / 2]) && (lst_cont(pile_a) != tab[len - 1]))
				push_b(pile_a, pile_b);
			else
				rotate_a(pile_a);
		}
		tri_3(pile_a);
		exec(pile_a, pile_b);
	}
}
