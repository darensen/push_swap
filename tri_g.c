/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:49:27 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/29 20:06:52 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    tri_g(t_pile **pile_a, t_pile **pile_b, int *tab, int size)
{
    t_pile *tmp;
    int i;

    i  = size / 2;
    tmp = *pile_a;
    printf(" %d ", tab[i]);
    while (lstsize(*pile_a) != i)
    {
        if (tab[i] > lst_cont(pile_a))
            push_b(pile_a, pile_b);
        else 
            rotate_a(pile_a);
        if (inf(pile_a,tab[i]) == 0)
            break;
    }
    suivant(pile_a,pile_b, tab, size);
    //choix(pile_a, pile_b, (size / 4));
}



void suivant(t_pile **pile_a, t_pile **pile_b, int *tab, int size)
{
    t_pile *tmp;
    int i;
    
    tmp = *pile_a;
    i = size / 4;
    /*
    while (inf(pile_b, tab[i]) != 0)
    {
        if (tab[i] > lst_cont(pile_b))
            reverse_rotate_b(pile_b);
        else 
            rotate_b(pile_b);
    }*/
}