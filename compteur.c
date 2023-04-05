/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:52:59 by lusezett          #+#    #+#             */
/*   Updated: 2023/04/05 16:54:55 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int which_combo(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b) 
{

    int rotate_all;
    int reverse_rotate_all;
    int rarrb;
    int rrarb;

    reverse_rotate_all = 1 + (pile_last(pile_b)->index - index_b);
    if (pile_last(pile_a)->index - index_a < reverse_rotate_all)
        reverse_rotate_all = 1 + pile_last(pile_a)->index;
    rotate_all = index_b;
    if (index_a < rotate_all)
        rotate_all = index_a;
    rarrb = 1 + index_a + (pile_last(pile_b)->index - index_b);
    rrarb = 1 + index_b + (pile_last(pile_a)->index - index_a);
    if (rotate_all <= rarrb && rotate_all <= reverse_rotate_all && rotate_all <= rrarb)
		return (0);
	if (reverse_rotate_all <= rarrb && reverse_rotate_all <= rotate_all && reverse_rotate_all <= rrarb)
		return (1);
	if (rarrb <= rrarb && rarrb <= reverse_rotate_all && rarrb <= rotate_all)
		return (2);
	if (rrarb <= rarrb && rrarb <= reverse_rotate_all && rrarb <= rotate_all)
		return (3);
}

int how_many_moves(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b)
{
    
    int rotate_all;
    int reverse_rotate_all;
    int rarrb;
    int rrarb;

    reverse_rotate_all = 1 + (pile_last(pile_b)->index - index_b);
    if (pile_last(pile_a)->index - index_a < reverse_rotate_all)
        reverse_rotate_all = 1 + pile_last(pile_a)->index;
    rotate_all = index_b;
    if (index_a < rotate_all)
        rotate_all = index_a;
    rarrb = 1 + index_a + (pile_last(pile_b)->index - index_b);
    rrarb = 1 + index_b + (pile_last(pile_a)->index - index_a);
    if (rotate_all <= rarrb && rotate_all <= reverse_rotate_all && rotate_all <= rrarb)
		return (rotate_all);
	if (reverse_rotate_all <= rarrb && reverse_rotate_all <= rotate_all && reverse_rotate_all <= rrarb)
		return (reverse_rotate_all);
	if (rarrb <= rrarb && rarrb <= reverse_rotate_all && rarrb <= rotate_all)
		return (rarrb);
	if (rrarb <= rarrb && rrarb <= reverse_rotate_all && rrarb <= rotate_all)
		return (rrarb);
}

t_struct optimal_bloc(t_pile **pile_a, t_pile **pile_b)
{
    t_struct tab;
    t_pile *temp;

    temp = *pile_b;
    tab.calcul = 5000;
    tab.val = temp->content;
    while(temp)
    {
        printf("tmp = %d\n", temp->index);
        if(how_many_moves(search(pile_a, temp->content), temp->index, pile_a, pile_b) < tab.calcul) // pour chaque element de la pile B, il va chercher dans la pile a l'element le plus proche et trouver celui qui coute le moins de coups a envoyer
        {
            tab.calcul = how_many_moves(search(pile_a, temp->content), temp->index, pile_a, pile_b);
            tab.val = temp->content;
            tab.index_a = search(pile_a, temp->content);
            tab.index_b = temp->index;
            printf("index a= %d index = b %d\n", tab.index_a, temp->index);
        }
        temp = temp->next;    
    }
    return(tab);
} 

void exec_if(t_pile **pile_a, t_pile **pile_b)
{
    t_struct tab;
    int combo;

    tab = optimal_bloc(pile_a, pile_b);
    combo = which_combo(tab.index_a, tab.index_b, pile_a, pile_b);
    //printf("combo = %d\n", combo);
    if (combo == 0)
		mouv_if_rr(pile_a, pile_b, tab);
	if (combo == 1)
		mouv_if_rrr(pile_a, pile_b, tab);
	if (combo == 2)
		mouv_if_rarrb(pile_a, pile_b, tab);
	if (combo == 3)
		mouv_if_rrarb(pile_a, pile_b, tab);
}


void exec(t_pile **pile_a, t_pile**pile_b)
{
    int i;
    
    add_index(pile_a, pile_b);
    i = pile_last(pile_b)->index;
    print_all(pile_a, pile_b);
    while(i != -1)
    {
        add_index(pile_a, pile_b);
        exec_if(pile_a, pile_b);
        i--;
    }  
}