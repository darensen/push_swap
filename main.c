/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/17 18:24:26 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_pile **head) 
{
	if (*head == NULL || (*head)->next == NULL) 
	{
	    return;
	}
	t_pile *temp = *head;
	t_pile *second = (*head)->next;
	t_pile *third = second->next;
    *head = second;
	
	second->next = temp;
	temp->next = third;
}

void rotate_a(t_pile *pile)
{
	t_pile *top = pile;
	t_pile *second = pile->next;
	
	while(pile->next != NULL)
	{	
		printf("%d o\n",pile->content);
		pile = pile->next;
	}
    //printf("%d i\n",second->content);
	second->next = pile->next;
	pile->next = top;
	top->next = second;
}

int main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;
	int *tab;
	int i;
	int temp = ac - 1;
	pile_a = NULL;
	pile_b = NULL;
	i = 0;
	tab = malloc(sizeof(int) * ac);
	
	while(i != ac - 1) 
	{
		
		tab[i] = ft_atoi(av[temp--]);
		i++;
		
	}
	i = 0;
	while(i < ac - 1) 
		push_number(&pile_a, tab[i++]);
	//swap_a(&pile_a);
	rotate_a(pile_a);
	while (pile_a != NULL)
	{
		printf("%d\n", pile_a->content);
		pile_a = pile_a ->next;
	}
	free(tab);
	return(0);
}

