/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/21 19:30:39 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;
	int *tab;
	int *second_tab;
	int i;
	
	i = 0;
	pile_a = NULL;
	pile_b = NULL;
	
	if (is_number(av) == 0 && ac > 3)
	{
		tab = fill_tab(av, ac);
		if (is_double(tab) == 0 && is_max_size(tab) == 0)
		{
			while(i < ac - 1) 
			{
				push_number(&pile_a, tab[i]);
				i++;
			}
		}
		else
		{
			printf("error\n");
			return (0);
		}
	}
	second_tab = sorted_tab(tab);	
	algo(&pile_a, &pile_b, second_tab);
	//print_all(&pile_a, &pile_b);
	return(0);
}

