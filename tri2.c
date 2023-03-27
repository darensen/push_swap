/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:21:39 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/27 19:45:42 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  last_lst2(int nb, t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;

    tmp = *pile_b;
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (nb < tmp->content)
    {
        push_a(pile_a, pile_b);
        print_all(pile_a, pile_b);
    }
    else if (nb < (*pile_b)->content)
    {
        rotate_b(pile_b);
        print_all(pile_a, pile_b);
        push_a(pile_a, pile_b);
        print_all(pile_a, pile_b);
    }
    else 
    {
        rotate_b(pile_b);
        print_all(pile_a, pile_b);
    }
}

int  sup(t_pile **pile, int mid)
{
    t_pile *tmp;

    tmp = *pile;
    if (!tmp->next)
        return (0);
    while (tmp)
    {
        if (mid > tmp->content)
        { 
            return (0);
        } 
        tmp = tmp->next;
    }
   
    return (1);
}

void tri2(t_pile **pile_a, t_pile **pile_b, int chunk, int *tab)
{
    int i;
    t_pile *tmp;

    tmp = *pile_b;
    i = 0;
    if (chunk == 1)
    {
        push_a(pile_a, pile_b);
        print_all(pile_a, pile_b);
        return ;
    }
    if (chunk == 2)
    {
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        if (tmp->content > tmp->next->content)
        {
            swap_b(pile_b);
            push_a(pile_a, pile_b);
            push_a(pile_a, pile_b);
            print_all(pile_a, pile_b);
        }
        else
        { 
            push_a(pile_a, pile_b);
            push_a(pile_a, pile_b);
            print_all(pile_a, pile_b);
        }
    }
    if (chunk == 3)
    {
        //tri_3(pile_b, pile_a);
        //print_all(pile_a, pile_b);
    }
}