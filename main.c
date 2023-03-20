/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/20 14:35:01 by dsenatus         ###   ########.fr       */
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
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//push_a(&pile_a, &pile_b);
	//rotate(&pile_a);
	reverse_rotate_b(&pile_b);
	//rrr(&pile_a, &pile_b);
	//ss(&pile_a, &pile_b);
	
	printf("/ PILE A /\n");
	while (pile_a != NULL)
	{
		printf("| %d |", pile_a->content);
		//printf("| %d |", pile_a->index);

		pile_a = pile_a ->next;
	}
	
	printf("\n/ PILE B /\n");
	while (pile_b != NULL)
	{
		printf("| %d |", pile_b->content);
		pile_b = pile_b->next;
	}

	return(0);
}

