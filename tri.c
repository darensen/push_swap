/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:46:34 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/29 19:40:51 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  last_lst(int nb, t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;
    
    int i;
    i = 0;
    tmp = *pile_a;
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (nb > tmp->content)
    {
        push_b(pile_a, pile_b);
        print_all(pile_a, pile_b);
        i++;
    }
    else if (nb > (*pile_a)->content)
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
        push_b(pile_a, pile_b);
        print_all(pile_a, pile_b);
        i++;
    }
    else 
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
    }
    return (i);
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

t_pile  *addr(t_pile **pile, int mid)
{
    t_pile *tmp;

    tmp = *pile;
    if (!tmp->next->next->next)
        return (NULL); 
    while (tmp->content != mid)
        tmp = tmp->next;
    return (tmp);
}

int  inf(t_pile **pile, int mid)
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

int tri(t_pile **pile_a, t_pile **pile_b, int *tab)
{
    int i;
    int j;
    t_pile *tmp;
    t_pile *pil;
    
    tmp = *pile_a;
    if (!tmp->next->next)
        return (0);
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
    if (inf(pile_a, j) == 0);
    {
        rotate_a(pile_a);
        print_all(pile_a, pile_b);
    }
    i = 0;
    while (addr(pile_a, j) != NULL && inf(pile_a, j) != 0)
        i = i + last_lst(j, pile_a, pile_b);
    return (i);
}
