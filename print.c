/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:28:00 by arnaud            #+#    #+#             */
/*   Updated: 2023/04/21 15:36:31 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("| content is %d |", oui->content);		
		printf("| index is %d |", oui->index);
		printf("\n");

		oui = oui->next;
	}
	printf("\n/ PILE B /\n");
	while (non != NULL)
	{
		printf("| content is %d |", non->content);		
		printf("| index is %d |", non->index);
		printf("\n");		
		non = non->next;
	}	
}