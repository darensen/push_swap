/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:46:34 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/22 17:57:28 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void last_lst(int nb, t_pile **pile_a, t_pile **pile_b)
{
    int i;
    t_pile *tmp;

    tmp = *pile_a;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if (nb < tmp->content)
    {
        push_b(pile_a, pile_b);
        print_all(pile_a, pile_b);
    }
    else 
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
    }

}

int	lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void tri(t_pile **pile_a, t_pile **pile_b)
{
    int i;
    int j;
    t_pile *tmp;
    t_pile *pil;
    
    tmp = *pile_a;
    i = lstsize(tmp) / 2;
    while (i != 0)
    {
        tmp = tmp->next;
        i--;
    }
    j = tmp->content;
    //tmp = tmp->next;
    while (tmp)
    {
        last_lst(j, pile_a, pile_b);
        printf("ici %d et la ", tmp->content);
        tmp = tmp->next;
    }       
}