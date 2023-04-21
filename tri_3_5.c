/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:26:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/04/21 16:58:00 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_3(t_pile **pile_a)
{
	t_pile	*tmp;
	int		a;
	int		b;
	int		c;

	tmp = *pile_a;
	a = tmp->content;
	b = tmp->next->content;
	c = tmp->next->next->content;
	if (a > b && b > c && a > c) //3 2 1
	{
		reverse_rotate_a(pile_a);
		swap_a(pile_a);
	}
	else if (a > b && b < c && a < c) // 2 1 3
	{
        rotate_a(pile_a);
        swap_a(pile_a);
    }    
	else if (a > b && b < c && a > c) // 3 1 2 
	{
    	rotate_a(pile_a);
    }
    else if (a < b && b > c && a < c) // 1 3 2
	{
		swap_a(pile_a);
	}
	else if (a < b && b > c && a > c) // 2 3 1
		reverse_rotate_a(pile_a);
}

void    tri_4(t_pile **pile_a, t_pile **pile_b)
{
    int min;

    while (lstsize(*pile_a) != 3)
    {
        if((*pile_a)->content == min)
        {
            rotate_a(pile_a);
            push_b(pile_a, pile_b);

        }  
        else 
            rotate_a(pile_a);
        min = find_smallest(pile_a);
    }
    print_all(pile_a, pile_b);
    tri_3(pile_a);
    push_a(pile_a, pile_b);
}

void    tri_5(t_pile **pile_a, t_pile **pile_b)
{
    int min;

    while (lstsize(*pile_a) != 3)
    {
        if((*pile_a)->content == min)
        {
            rotate_a(pile_a);
            push_b(pile_a, pile_b);

        }  
        else 
            rotate_a(pile_a);
        min = find_smallest(pile_a);
    }
    tri_3(pile_a);
    if ((*pile_b)->content > (*pile_b)->next->content)
        swap_b(pile_b);
    push_a(pile_a, pile_b);
    push_a(pile_a, pile_b);
}