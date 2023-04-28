/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/28 20:32:38 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		*tab;
	int		*second_tab;
	int		i;

	i = 0;
	pile_a = NULL;
	pile_b = NULL;
	if (is_number(av) == 0 && ac > 2)
	{
		tab = fill_tab(av, ac);
		if (is_double(tab, ac) == 0 && is_max_size(tab, ac) == 0)
		{
			while (i < ac - 1)
				push_number(&pile_a, tab[i++]);
			second_tab = sorted_tab(tab, ac - 1);
			algo(&pile_a, &pile_b, second_tab, ac - 1);
			free_list(&pile_a);
			free(tab);
		}
		else
			printf("error\n");
	}
	return (0);
}
