/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadou <dadou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:46:34 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/24 17:41:05 by dadou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  last_lst(int nb, t_pile **pile_a, t_pile **pile_b)
{
    int i;
    t_pile *tmp;
    int j;
    
    j = 0;
    tmp = *pile_a;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    //printf("\nhaut = %d", (*pile_a)->content);
    if (nb > tmp->content)
    {
        printf("pil %d", tmp->content);
        push_b(pile_a, pile_b);
        print_all(pile_a, pile_b);
        j++;
    }
    else if (nb > (*pile_a)->content)
    {
        printf("\nhaut loop = %d", (*pile_a)->content);
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
        push_b(pile_a, pile_b);
        print_all(pile_a, pile_b);
        j++;
    }
    else 
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
        j++;
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

t_pile  *addr(t_pile **pile_a, int mid)
{
    t_pile *tmp;

    tmp = *pile_a;
    while (tmp->content != mid)
        tmp = tmp->next;
    return (tmp);
}

int  inf(t_pile **pile_a, int mid)
{
    t_pile *tmp;

    tmp = *pile_a;
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

void tri(t_pile **pile_a, t_pile **pile_b)
{
    int i;
    int j;
    t_pile *tmp;
    t_pile *pil;
    
    if ((*pile_a)->next == NULL)
        return ;
    tmp = *pile_a;
    i = lstsize(tmp) / 2;
    while (i != 0)
    {
        tmp = tmp->next;
        i--;
    }
    j  = tmp->content;
    printf("new mid %d", j);
    print_all(pile_a, pile_b);
    if (inf(pile_a, j) == 0)
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
    }
    while (addr(pile_a, j) != NULL && inf(pile_a, j) != 0)
    { 
        last_lst(j, pile_a, pile_b);
        printf("iciozzddzddzi%d", j);
       
    }       
}
