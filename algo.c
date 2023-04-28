/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:09:37 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/28 20:45:31 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_pile **a, t_pile **b, int *tab, int size)
{
	if (is_sorted2(a) == 0)
		return ;
	if ((*a)->content > (*a)->next->content)
		swap_a(a);
	if (lstsize(*a) == 3)
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
				&& ((*a)->content != tab[size / 2])
				&& ((*a)->content != tab[size - 1]))
				push_b(a, b);
			else
				reverse_rotate_a(a);
		}
		tri_3(a);
		exec(a, b);
	}
}
