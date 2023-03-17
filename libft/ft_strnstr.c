/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:10:10 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/25 17:57:50 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!str || !to_find) && len == 0)
		return (NULL);
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && i + j < len)
			{
				j++;
				if (to_find[j] == 0)
					return ((char *)(&str[i]));
			}
		}
	i++;
	}
	return (NULL);
}
