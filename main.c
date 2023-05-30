/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:29 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/22 15:22:10 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ac_1_or_2(int ac, char **av)
{
	int	i;
	int	e;

	e = 0;
	if (ac >= 2)
	{
		i = 0;
		ac = ac + 1;
		i = 2;
		while (av[i])
		{
			i++;
			ac++;
		}
		return (ac);
	}
	else
	{
		while (av[e])
			e++;
		return (e);
	}
}

int	ac2(char **av)
{
	int	e;
	int	j;

	j = 0;
	e = 0;
	while (av[1][j])
	{
		if (ft_isdigit2(av[1][j]) == 0)
		{
			e++;
			while ((ft_isdigit2(av[1][j]) == 0))
			{
				j++;
			}
		}
		while (av[1][j] == ' ')
			j++;
	}
	e = (ac_1_or_2(e, av));
	return (e);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	long	*tab;
	long	*second_tab;
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
