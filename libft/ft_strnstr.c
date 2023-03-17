/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:19:25 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/28 14:54:34 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	g;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (!n)
		return (NULL);
	while (str[i])
	{
		g = i;
		j = 0;
		while (str[g] == to_find[j] && g < n)
		{
			g++;
			j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
