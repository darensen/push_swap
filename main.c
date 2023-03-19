/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/19 20:23:05 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		push_number(&pile_a, tab[i++]);
	}
	i = 0;
	
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	push_a(&pile_a, &pile_b);
	printf("/ PILE A /\n");
	while (pile_a != NULL)
	{
		printf("%d\n", pile_a->content);
		pile_a = pile_a ->next;
	}
	
	printf("/ PILE B /\n");
	while (pile_b != NULL)
	{
		printf("%d\n", pile_b->content);
		pile_b = pile_b->next;
	}

	return(0);
}

