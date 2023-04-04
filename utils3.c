/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusezett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:11:21 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/04 17:19:16 by lusezett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return(i);
	
}

int	ft_mediane(int *tab)
{
	int	i;
	int size;
	int mediane;
	
	size = tab_len(tab);
	
	if (size % 2 == 0)
		mediane = size / 2;
	else if (size % 2 != 0)
	{
		i = size / 2;
		i++;
		mediane = i;
	}
	return(mediane);
}

int    lst_cont(t_pile **pile)
{
    t_pile *tmp;

    tmp = *pile;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->content);
}

int search(t_pile **pile, int val)

{
	
	t_pile *temp;
	int i;
	int j;

	temp = *pile;
	i = 32767;
	j = find_biggest(pile);
	while(temp)
	{
		if(temp->content <= j && temp->content > val)
		{
			j = temp->content;
			i = temp->index;
		}
		temp = temp->next;
			
	}
	printf("%d", i);
	



	t_pile *oui;
	oui = *pile;
	printf("\n");
	printf("\n/ PILE A /\n");
	while (oui != NULL)
	{
		printf("| content is %d |", oui->content);		
		printf("| index is %d |", oui->index);
		printf("\n");

		oui = oui->next;
	}
	return(i);

	
}