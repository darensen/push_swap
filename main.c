/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadou <dadou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/24 17:41:35 by dadou            ###   ########.fr       */
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
	if (!tab)
		return (0);
	if (is_number(av) == 1)
	{
		printf("oui");
		return (1);
	}
	while(i != ac - 1) 
	{
		
		tab[i] = ft_atoi(av[temp--]);
		i++;
	}
	if (is_double(tab) == 1)
		return (1);
	if (is_max_size(tab) == 1)
		return (1);
	i = 0;
	while(i < ac - 1) 
	{
		push_number(&pile_a, tab[i++]);
	}
	printf("fist call");
	print_all(&pile_a, &pile_b);
	t_pile *first;
	first = pile_a;
	
	while (first->next != NULL)
		tri(&pile_a, &pile_b);
	printf("\nlast call");
	print_all(&pile_a, &pile_b);
	return(0);
}

void print_all(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *oui;
	t_pile *non;
	
	oui = *pile_a;
	non = *pile_b;
	printf("\n");
	printf("\n/ PILE A /\n");
	while (oui != NULL)
	{
		printf("| %d |", oui->content);
		oui = oui->next;
	}
	printf("\n/ PILE B /\n");
	while (non != NULL)
	{
		printf("| %d |", non->content);
		non = non->next;
	}	
}

