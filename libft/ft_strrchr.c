/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:26:31 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/28 17:40:13 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurence(const char *s, int c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
		n++;
		}
	i++;
	}
	return (n);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
		o++;
			if (o == (occurence(s, c)))
			{
				return ((char *)&s[i]);
			}
		}
	i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (0);
}
