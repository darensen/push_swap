/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <dsenatus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:17:30 by arnaud            #+#    #+#             */
/*   Updated: 2023/05/22 16:33:29 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*pile_last(t_pile **pile)
{
	t_pile	*lst;

	lst = *pile;
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	pile_addfront(t_pile **lst, t_pile *new)
{
	if (!(*lst) || !new)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free (tab);
	return (NULL);
}

long	*o(int ac0, long *tab, char **av)
{
	int	i;
	int	temp;

	temp = 1;
	i = 0;
	while (i != ac0 - 1)
	{
		tab[i] = ft_atoi(av[temp]);
		i++;
		temp++;
	}
	return (tab);
}

long	*fill_tab(char **av, int ac, int ac0)
{
	int		i;
	long	*tab;
	int		temp;
	char	**str;

	tab = malloc(sizeof(long) * ac);
	if (!tab)
		return (0);
	i = 0;
	temp = 1;
	if (ac0 == 2)
	{
		str = ft_split(av[1], ' ');
		temp = 0;
		while (i != ac - 1)
		{	
			tab[i] = ft_atoi(str[temp]);
			i++;
			temp++;
		}
		ft_free(str);
		return (tab);
	}
	tab = o(ac0, tab, av);
	return (tab);
}
