/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/22 17:44:18 by dsenatus         ###   ########.fr       */
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
	tri(&pile_a, &pile_b);
	i = 0;
	printf("\nlast call");
	print_all(&pile_a, &pile_b);
	//printf("/ PILE A /\n");
	/*while (pile_a != NULL)
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
	}*/
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

