/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:05:59 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/25 17:48:54 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newtab;
	int		j;
	int		len;
	int		z;

	len = ft_strlen(s1);
	j = 0;
	z = 0;
	if (!s1)
		return (NULL);
	while ((ft_find(s1[j], set)) && s1[j])
		j++;
	while ((ft_find(s1[len - 1], set)) && len > j)
		len--;
	newtab = malloc(sizeof(char) *((len - j) + 1));
	if (!newtab)
		return (NULL);
	while (j < len)
	{
		newtab[z] = s1[j];
		j++;
		z++;
	}
	newtab[z] = '\0';
	return (newtab);
}
