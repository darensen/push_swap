/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:26:55 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/25 17:44:48 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurence(const char *str, int c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			n++;
		}
		i++;
	}
	return (n);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			o++;
			if (o == occurence(str, c))
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
