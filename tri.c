/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:46:34 by dsenatus          #+#    #+#             */
/*   Updated: 2023/03/31 18:56:03 by dsenatus         ###   ########.fr       */
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

     if (!tmp->next->next->next)
        return (1); 
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

int find_min(t_pile **pile_a, t_pile **pile_b, int *tab)
{
    t_pile *tmp;
    int i;

    tmp = *pile_a;
    i = tmp->content;
    while (tmp->next != NULL)
    {
        if (tmp->content > tmp->next->content)
            i = tmp->next->content; 
        tmp = tmp->next;
    }
    return (i);
}

void    tri(t_pile **pile_a, t_pile **pile_b, int *tab)
{
    int i;
    t_pile *tmp;
    int min;

    min = find_min(pile_a, pile_b, tab);
    tmp = *pile_a;
    while (min != tmp->content)
    {
        tmp = tmp->next;
    }
    i = tmp->content;
    while (lst_cont(pile_a) != i)
        rotate_a(pile_a);
    push_b(pile_a, pile_b);
    tri_3(pile_a);
	push_a(pile_a, pile_b);
}
