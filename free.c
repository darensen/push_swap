/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:14 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/20 13:03:38 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_list(t_pile **pile)
{
    t_pile *tmp;
    
    tmp = *pile;
    while (pile != NULL)
    {
        tmp = (*pile)->next;
        free(pile);
        *pile = tmp;
    }
}