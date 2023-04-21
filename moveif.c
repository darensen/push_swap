/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveif.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:28:49 by dsenatus          #+#    #+#             */
/*   Updated: 2023/04/21 15:56:24 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	mouv_if_rr(t_pile **pile_a, t_pile **pile_b, t_struct tab)
{
	t_struct	info;


	info = tab;
	//printf("VALEUR OUI OUI = %d ", info.);
	while (info.index_a != 0 && info.index_b != 0)
	{
		rr(pile_a, pile_b);
		info.index_a--;
		info.index_b--;
	}
	while (info.index_a != 0)
	{
		rotate_a(pile_a);
		info.index_a--;
	}
	while (info.index_b != 0)
	{
		rotate_b(pile_b);
		info.index_b--;
	}
    push_f(pile_a, pile_b);
}

void	mouv_if_rrr(t_pile **pile_a, t_pile **pile_b, t_struct info)
{

	info.imaxa = pile_last(pile_a)->index + 1;
	info.imaxb = pile_last(pile_b)->index + 1;
	while (info.index_a != info.imaxa && info.index_b != info.imaxb)
	{
		rrr(pile_a, pile_b);
		info.index_a++;
		info.index_b++;
	}
	while (info.index_a != info.imaxa)
	{
		reverse_rotate_a(pile_a);
		info.index_a++;
	}
	while (info.index_b != info.imaxb)
	{
		reverse_rotate_b(pile_b);
		info.index_b++;
	}
    push_f(pile_a, pile_b);
}

void	mouv_if_rrarb(t_pile **pile_a, t_pile **pile_b, t_struct tab)
{
	t_struct	info;

	info = tab;
	info.imaxa = pile_last(pile_a)->index + 1;
	while (info.index_a != info.imaxa)
	{
		reverse_rotate_a(pile_a);
		info.index_a++;
	}
	while (info.index_b != 0)
	{
		rotate_a(pile_a);
		info.index_b--;
	}
    push_f(pile_a, pile_b);
}


void	mouv_if_rarrb(t_pile **pile_a, t_pile **pile_b, t_struct tab)
{
	t_struct info;

	info = tab;
	info.imaxb = pile_last(pile_b)->index + 1;

	while (info.index_a != 0)
	{
		rotate_a(pile_a);
		info.index_a--;
	}
	while (info.index_b != info.imaxb)
	{
		reverse_rotate_b(pile_b);
		info.index_b++;
	}
    push_f(pile_a, pile_b);
}