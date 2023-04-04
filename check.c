/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:29:09 by arnaud            #+#    #+#             */
/*   Updated: 2023/03/23 13:33:07 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int check()
{
	// check si :
	// - pas doublons
	// - si tous des nombres
	// si dépasse pas la taille max d'un int
	// si tout bon -> return(O)
}
*/

int is_double(int *tab)
{
	int i;
	int j;
	
	j = 0;
	while (tab[j])
	{	
		i = j + 1;
		while(tab[i])
		{
			if(tab[i] == tab[j])
				return (1);
			i++;
		}
	j++;
	}
	return (0);	
}

int is_number(char **tab)
{
	int i;
	int j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if(tab[i][j] == '-' && j == 0)
				j++;
			if (ft_isdigit(tab[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


int is_max_size(int *tab)
{
	int i;
	i = 0;
	while(tab[i])
	{
		if(tab[i] > 32767 || tab[i] < -32768)
			return (1);
		i++;
	}
	return (0);
}
