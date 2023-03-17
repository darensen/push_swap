/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:29:00 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/28 15:07:19 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char const *s1, char const *s2, char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[y] != '\0')
	{
		str[i] = s1[y];
		i++;
		y++;
	}
	y = 0;
	while (s2[y] != '\0')
	{
		str[i] = s2[y];
		i++;
		y++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcat(s1, s2, str);
	return (str);
}
