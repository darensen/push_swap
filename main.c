/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/12 18:37:55 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ac2(char **av)
{
	int	i;
	int e;
	int j;

	j = 0;
	e = 0;
	i = 0;
	while (av[1][j])
	{
		if (ft_isdigit(av[1][j]) == 0)
		{
			e++;
			while (ft_isdigit(av[1][j]) == 0)
			{
				j++;
			}
		}
		while (av[1][j] == ' ')
			j++;		
	}
	if (e >= 2)
	{
		e = e + 1;
		i = 2;
		while (av[i])
		{
			i++;
			e++;
		}
		return (e);
	}
	while (av[i])
		i++;
	return (i);
}

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
	if (is_number(av) == 0 && ac > 1)
	{
		tab = fill_tab(av, ac2(av), ac);
		if (is_double(tab, ac2(av)) == 0 && is_max_size(tab, ac2(av)) == 0)
		{
			while (i < ac2(av) - 1)
				push_number(&pile_a, tab[i++]);
			second_tab = sorted_tab(tab, ac2(av) - 1);
			algo(&pile_a, &pile_b, second_tab, ac2(av) - 1);
			free_list(&pile_a);
			free(tab);
		}
		else
			ft_printf("Error\n");
	}
	return (0);
}
