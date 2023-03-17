/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:16:47 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/25 17:55:17 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_fill(char *tab, int count, int i, long int longn)

{
	if (longn < 0)
	{
		tab[0] = '-';
		i++;
		longn = longn * -1;
	}
	tab[count] = '\0';
	while (count > i)
	{
		count--;
		tab[count] = (longn % 10) + '0';
		longn = longn / 10;
	}
	return (longn);
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			count;
	int			i;
	long int	longn;

	longn = n;
	count = ft_count(longn);
	i = 0;
	if (longn < 0 || count == 0)
		count++;
	tab = malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (NULL);
	ft_fill(tab, count, i, longn);
	return (tab);
}
