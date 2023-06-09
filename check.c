/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:09 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/22 17:17:32 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double(long *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j != size - 1)
	{	
		i = j + 1;
		while (i != size - 1)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (1);
			}
			i++;
		}
	j++;
	}
	return (0);
}

int	is_number(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			while (tab[i][j] == ' ')
				j++;
			if (tab[i][j] == '-' && ft_isdigit(tab[i][j + 1] == 0))
				j++;
			if (ft_isdigit(tab[i][j]) == 1)
			{
				ft_printf("Error\n");
				return (1);
			}	
			j++;
		}	
		i++;
	}
	return (0);
}

int	is_max_size(long *tab, int size)
{
	int	i;

	i = 0;
	while (i != size -1)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			free(tab);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if ((c >= 48 && c <= 57))
		return (0);
	return (1);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	long	nb;
	int		signe;

	i = 0;
	j = 0;
	signe = 1;
	nb = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i + j] >= '0' && nptr[i + j] <= '9')
	{
		nb = (nptr[i + j] - 48) + nb * 10;
		j++;
		if (j > 10)
			return (2147483649);
	}
	return (nb * signe);
}
