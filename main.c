/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/29 19:10:50 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
	
	t_pile *pile_a;
	t_pile *pile_b;
	t_pile *first;

	int *tab;
	int *bab;
	int i;
	int *c;
	
	i = 0;
	pile_a = NULL;
	pile_b = NULL;
	
	if (is_number(av) == 0 && ac > 3)
		{
			tab = fill_tab(av, ac);
			bab = ft_sort_int_tab(tab, ac - 1);
			if (is_double(tab) == 0 && is_max_size(tab) == 0)
			{
				while(i < ac - 1) 
				{
					push_number(&pile_a, tab[i]);
					i++;
				}
			}
		}
	first = pile_a;
	int b;
	b = 0;
	c = malloc(sizeof(int) * lstsize(pile_a));
	i = 0;
	if (ac == 4)
	{
		print_all(&pile_a, &pile_b);
		tri_3(&pile_a);
		print_all(&pile_a, &pile_b);
		return (0);
	}
	if (ac == 6)
	{
		tri_5(&pile_a, &pile_b, bab);
	}
	if (ac == 5)
	{
		while (first->next->next->next != NULL)
		{
			c[i] = tri(&pile_a, &pile_b, bab);
			if (c[i] != 0)
				i++;
		}
		tri_3(&pile_a);
		push_a(&pile_a, &pile_b);
	}
	if (ac > 5)
	{
		tri_g(&pile_a, &pile_b, bab, ac - 1);
	}
	
	printf("\nlast call");
	print_all(&pile_a, &pile_b);
}

void print_all(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *oui;
	t_pile *non;
	t_pile *o;
	
	oui = *pile_a;
	o = *pile_a;
	non = *pile_b;
	printf("\n");
	printf("\n/ PILE A /\n");
	while (oui != NULL)
	{
		printf("%d===>", oui->content);
		oui = oui->next;
	}
	/*printf("index\n");
	while (o != NULL)
	{
		printf("%d===>", o->index);
		o = o->next;
	}*/
	printf("\n/ PILE B /\n");
	while (non != NULL)
	{
		printf("%d===>", non->content);
		non = non->next;
	}	
}

