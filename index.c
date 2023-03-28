/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:57:53 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/28 17:58:44 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile *add_index_a(t_pile **pile_a)
{
    t_pile *temp1;
    int i;
    
    i = 0;
    temp1 = *pile_a;
    while (temp1->next != NULL )
    {
        temp1->index = i;
        temp1 = temp1->next;
        i++;
    }
    temp1->index = i;

    return(temp1);

}

t_pile *add_index_b(t_pile **pile_b)
{
    t_pile *temp1;
    int i;
    
    i = 0;
    temp1 = *pile_b;
    while (temp1->next != NULL)
    {
        temp1->index = i;
        temp1 = temp1->next;
        i++;
    }
    temp1->index = i;
    return(temp1);

}

void add_index(t_pile **pile_a, t_pile **pile_b)
{
    add_index_a(pile_a);
    add_index_b(pile_b);
}