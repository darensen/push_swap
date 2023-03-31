/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:49:27 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/31 18:08:02 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  inf2(t_pile **pile, int mid)
{
    t_pile *tmp;

    tmp = *pile;
    while (tmp)
    {
        if (mid > tmp->content)
        { 
            return (1);
        } 
        tmp = tmp->next;
    }
   
    return (0);
}

void    tri_g(t_pile **pile_a, t_pile **pile_b, int *tab, int size)
{
    t_pile *tmp;
    int i;

    i  = size / 2;
    tmp = *pile_a;
    while (lstsize(*pile_a) != i)
    {
        if (tab[i] > lst_cont(pile_a))
            push_b(pile_a, pile_b);
        else 
            rotate_a(pile_a);
        if (inf2(pile_a,tab[i]) == 0)
            break;
    }
    mid(pile_a,pile_b, tab, size);
}

int ok(t_pile **pile_b, t_pile **pile_a, int i ,int ta)
{
    t_pile *tmp;
    int y;

    y = 0;
    tmp = *pile_b;
    while (y != i + 1)
    { 
        if (tmp->content > ta)
            return (1);
       tmp = tmp->next;
        y++;
    }
    printf(" oui%d ", tmp->content);
    if (tmp->content > ta)
        push_a(pile_a, pile_b);
    return(0);
}

void mid(t_pile **pile_a, t_pile **pile_b, int *tab, int size)
{
    t_pile *tmp;
    int i;

    tmp = *pile_b;
    i = size / 4;
    i = i / 2;
    while (ok(pile_b, pile_a,  i , tab[i]) != 0)
    { 
        if (tab[i] < lst_cont(pile_b))
            push_a(pile_a, pile_b);
        else
            rotate_b(pile_b);
    }
    choix(pile_a, pile_b, tab);
}

void choix(t_pile **pile_a, t_pile **pile_b, int *tab)
{
    int i;
    t_pile *tmp;
    
    tmp = *pile_b;
    i = lstsize(*pile_b);
    printf(" size = %d", i);
    if (i == 2)
    {
        if (tmp->content < tmp->next->content)
            swap_b(pile_b);
    }
    else if (i == 3)
        tri_3(pile_b);
    else if (i == 4)
        tri(pile_a, pile_b, tab);
    else if (i == 5)
        tri_5(pile_a, pile_b, tab);
}