/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:07:39 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/23 16:27:46 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tab_filler(char *tab, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		tab[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		tab[j] = s2[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		totlen;

	totlen = (ft_strlen(s1) + ft_strlen(s2));
	if (!s1 || !s2)
		return (NULL);
	a = malloc(sizeof(char) * (totlen + 1));
	if (a == NULL)
		return (NULL);
	a = tab_filler(a, s1, s2);
	return (a);
}
