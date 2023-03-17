/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:43:49 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/25 17:58:35 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	max(const char *s, size_t len, int start)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		i++;
		start++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	if (ft_strlen(s) < start)
	{
		tab = malloc(sizeof(char) * 1);
		if (!tab)
			return (NULL);
		tab[i] = '\0';
		return (tab);
	}
	tab = malloc(sizeof(char) * (max(s, len, (int)start) + 1));
	if (!tab)
		return (NULL);
	while (s[start] && i < len)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}
