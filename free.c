/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:14 by dsenatus          #+#    #+#             */
/*   Updated: 2023/04/28 19:56:57 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*next;

	tmp = *pile;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
