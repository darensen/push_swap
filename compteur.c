/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:52:59 by lusezett          #+#    #+#             */
/*   Updated: 2023/04/14 18:02:17 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int which_combo(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b) 
{

    int rotate_all;
    int revrse_rotate_all;
    int rarrb;
    int rrarb;

    revrse_rotate_all = (pile_last(pile_b)->index - index_b);
    if (pile_last(pile_a)->index - index_a < revrse_rotate_all)
        revrse_rotate_all = pile_last(pile_a)->index;
    rotate_all = 1 + index_b;
    if (index_a < index_b)
        rotate_all = 1 + index_a;
    rarrb = index_a + (pile_last(pile_b)->index - index_b) + 1;
    rrarb = index_b + (pile_last(pile_a)->index - index_a) + 1;
    printf("\nrotate all = %d,", revrse_rotate_all);
    printf(" revesre rotate all = %d,", rotate_all);
    printf(" rarrb = %d,", rarrb);
    printf(" rrarb = %d\n", rrarb);
    if (rotate_all <= rarrb && rotate_all <= revrse_rotate_all && rotate_all <= rrarb)
		return (0);
	if (revrse_rotate_all <= rarrb && revrse_rotate_all <= rotate_all && revrse_rotate_all <= rrarb)
		return (1);
	if (rarrb <= rrarb && rarrb <= revrse_rotate_all && rarrb <= rotate_all)
		return (2);
	if (rrarb <= rarrb && rrarb <= revrse_rotate_all && rrarb <= rotate_all)
		return (3);
}

int how_many_moves(int index_a, int index_b, t_pile **pile_a, t_pile **pile_b)
{
    int rotate_all;
    int revrse_rotate_all;
    int rarrb;
    int rrarb;

    printf("index de a = %d et index de b = %d\n ", index_a, index_b);
    revrse_rotate_all = (pile_last(pile_b)->index - index_b);
    if ((pile_last(pile_a)->index - index_a) < (pile_last(pile_b)->index - index_b))
        revrse_rotate_all = pile_last(pile_a)->index;
    rotate_all = 1 + index_b;
    if (index_a < index_b)
        rotate_all = 1 + index_a;
    rarrb = index_a + (pile_last(pile_b)->index - index_b) + 1;
    rrarb = index_b + (pile_last(pile_a)->index - index_a) + 1;
    if (rotate_all < rarrb && rotate_all < revrse_rotate_all && rotate_all < rrarb)
		return (rotate_all);
	if (revrse_rotate_all < rarrb && revrse_rotate_all < rotate_all && revrse_rotate_all < rrarb)
		return (revrse_rotate_all);
	if (rarrb < rrarb && rarrb < revrse_rotate_all && rarrb < rotate_all)
		return (rarrb);
	if (rrarb < rarrb && rrarb < revrse_rotate_all && rrarb < rotate_all)
		return (rrarb);
}

t_struct optimal_bloc(t_pile **pile_a, t_pile **pile_b)
{
    t_struct tab;
    t_pile *temp;
    int i = 0;
    int a;

    temp = *pile_b;
    tab.calcul = 5000;
    tab.val = temp->content;
    while(temp)
    {

        //a = how_many_moves(search(pile_a, temp->content), temp->index, pile_a, pile_b);
        //printf("a = %d\n", a);
        //printf("index de b = %d\n", temp->index);
        if(how_many_moves(search(pile_a, temp->content), temp->index, pile_a, pile_b) < tab.calcul) // pour chaque element de la pile B, il va chercher dans la pile a l'element le plus proche et trouver celui qui coute le moins de coups a envoyer
        {
            //printf("tmp2 = %d\n", temp->index);
            tab.calcul = how_many_moves(search(pile_a, temp->content), temp->index, pile_a, pile_b);
            tab.val = temp->content;
            tab.index_a = search(pile_a, temp->content);
            tab.index_b = temp->index;
            //print_all(pile_a, pile_b);
            //printf("index a= %d index = b %d\n", tab.index_a, temp->index);
        }
        temp = temp->next;    
    }
    printf("\nboucle\n");
    return(tab);
} 

void exec_if(t_pile **pile_a, t_pile **pile_b)
{

    t_struct tab;
    int combo;

    tab = optimal_bloc(pile_a, pile_b);
    combo = which_combo(tab.index_a, tab.index_b, pile_a, pile_b);
    printf("combo = %d\n", combo);
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
    while(i != -1)
    {
        printf("oui");
        add_index(pile_a, pile_b);
        print_all(pile_a, pile_b);
        exec_if(pile_a, pile_b);
        i--;
    }
}