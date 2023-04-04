/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:26:09 by abeaudui          #+#    #+#             */
/*   Updated: 2023/03/30 17:53:19 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    tri_4(t_pile **pile_a, t_pile **pile_b, int *tab)
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

void    tri_5(t_pile **pile_a, t_pile **pile_b, int *tab)
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