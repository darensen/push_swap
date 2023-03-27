/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:21:39 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/27 17:45:24 by dsenatus         ###   ########.fr       */
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

void tri2(t_pile **pile_a, t_pile **pile_b, int chunk)
{
    int i;
    int j;
    t_pile *tmp;

    j = 0;
    tmp = *pile_b;
    i = 0;
    if (chunk == 1)
    {
        push_a(pile_a, pile_b);
        return ;
    }
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
     if (inf(pile_a, j) == 0)
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
    }
    printf("new mid %d\n", j);
    print_all(pile_a, pile_b);
    while (addr(pile_b, j) != NULL && sup(pile_b, j) == 1)
    { 
        last_lst2(j, pile_a, pile_b);
        printf("new mid boucle %d\n", j);
    } 
}