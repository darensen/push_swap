/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:08:52 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/20 14:36:13 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void reverse_rotate_a(t_pile **pile)
{
    t_pile *temp;
    t_pile *first;
    t_pile *last;
    t_pile *second_to_last;
    
    if (!(*pile)->next)
        return ;
    temp = *pile;
    first = temp; 
    while(temp->next->next != NULL)
        temp = temp->next;
    second_to_last = temp;
    last = temp->next;
    second_to_last->next = NULL;
    last->next = first;
    *pile = last;
}

void reverse_rotate_b(t_pile **pile)
{
    if (!(*pile)->next)
        return ;
    t_pile *temp;
    t_pile *first;
    t_pile *last;
    t_pile *second_to_last;
    
    temp = *pile;
    first = temp; 
    while(temp->next->next != NULL)
        temp = temp->next;
    second_to_last = temp;
    last = temp->next;
    second_to_last->next = NULL;
    last->next = first;
    *pile = last;
}

void rrr(t_pile **pile_a, t_pile **pile_b)
{
    reverse_rotate_a(pile_a);
    reverse_rotate_b(pile_b);
}