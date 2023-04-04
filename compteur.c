/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:52:59 by lusezett          #+#    #+#             */
/*   Updated: 2023/04/04 19:20:29 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void exec(t_pile **pile_a, t_pile **pile_b)
{
    add_index(pile_a, pile_b);
    
}


int which_combo(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b)
{

    int rotate_all;
    int reverse_rotate_all;
    int rarrb;
    int rrarb;

    reverse_rotate_all = 1 + (pile_last(pile_b)->index - index_b);
    if (pile_last(pile_a)->index - index_a < rotate_all)
        reverse_rotate_all = 1 + pile_last(pile_a)->index;
    rotate_all = index_b;
    if (index_a < rotate_all)
        rotate_all = index_a;
    rarrb = 1 + index_a + (pile_last(pile_b)->index - index_b);
    rrarb = 1 + index_b + (pile_last(pile_a)->index - index_a);
    if (rotate_all <= rarrb && rotate_all <= reverse_rotate_all && rotate_all <= rrarb)
		return (0);
	if (reverse_rotate_all <= rarrb && reverse_rotate_all <= rotate_all && reverse_rotate_all <= rrarb)
		return (1);
	if (rarrb <= rrarb && rarrb <= reverse_rotate_all && rarrb <= rotate_all)
		return (2);
	if (rrarb <= rarrb && rrarb <= reverse_rotate_all && rrarb <= rotate_all)
		return (3);
}