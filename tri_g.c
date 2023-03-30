/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:49:27 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/30 18:35:39 by dsenatus         ###   ########.fr       */
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
    printf(" mid = %d ", tab[i]);
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

int ok(t_pile **pile, int i ,int ta)
{
    t_pile *tmp;
    int y;

    y = 0;
    tmp = *pile;
    while (y != i)
    {
        if (tmp->content > ta)
            return (1);
        tmp = tmp->next;
        y++;
    }
    return(0);
}

void mid(t_pile **pile_a, t_pile **pile_b, int *tab, int size)
{
    t_pile *tmp;
    int i;

    tmp = *pile_b;
    i = size / 4;
    
    while (ok(pile_b, i , tab[i]) != 0)
    {
        if (tab[i] > lst_cont(pile_b))
            reverse_rotate_a(pile_b);
        else 
            rotate_a(pile_b);
        printf("\ntab = %d\n", tab[i]);
        print_all(pile_a, pile_b);
    }
}