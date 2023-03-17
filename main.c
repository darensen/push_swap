/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/17 19:03:41 by dsenatus         ###   ########.fr       */
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
	int i;
	
	i = top->content;
    while (top->next != NULL)
	{
		top->content = top->next->content;
		top = top->next;
	}
	top->content = i;
}

void reverse_a(t_pile *pile)
{
	t_pile *top = pile;
	t_pile *tmp = pile;
	int i;
	
	i = top->content;
	while (tmp->next)
		tmp = tmp->next;
	top->content = tmp->content;
    /*while (top->next != NULL)
	{
		top->content = top->next->content;
		top = top->next;
	}*/
	
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
	reverse_a(pile_a);
	while (pile_a != NULL)
	{
		printf("%d\n", pile_a->content);
		pile_a = pile_a ->next;
	}
	free(tab);
	return(0);
}

