/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:21:39 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/27 15:55:53 by dsenatus         ###   ########.fr       */
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
    else if (nb < (*pile_a)->content)
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

void tri2(t_pile **pile_a, t_pile **pile_b, int chunk)
{
    int i;
    int j;
    t_pile *tmp;
    t_pile *pil;
    
    tmp = *pile_b;
     if (!tmp->next)
        return ;
    i = lstsize(tmp) / 2;
    while (i != 0)
    {
        tmp = tmp->next;
        if (i == 1)
        {
            if (tmp->content > tmp->next->content)
                tmp = tmp->next;
        }
        i--;
    }
    j = tmp->content;
    printf("new mid %d\n", j);
    print_all(pile_a, pile_b);
    if (inf(pile_b, j) == 0)
    {
        rotate_b(pile_b);
        print_all(pile_a, pile_b);
    }
    while (addr(pile_b, j) != NULL && inf(pile_b, j) != 0)
    { 
        last_lst2(j, pile_a, pile_b);   
    } 
}