/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:42:14 by abeaudui          #+#    #+#             */
/*   Updated: 2023/03/26 19:08:42 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *sorted_tab(int *tab)
{
	int i;
	int j;
	int temp;
	
	j = 0;
	i = 0;
	while(tab[i + 1])
	{
		j = i + 1;
		if(tab[i] > tab[j])
		{
			temp = tab[j];
			tab[j] = tab[i];
			tab[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	return(tab);
}