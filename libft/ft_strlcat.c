/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:54:42 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/30 14:53:57 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size3;

	if (!dest && !size)
		return (0);
	size3 = ft_strlen(src);
	i = 0;
	j = 0;
	j = ft_strlen(dest);
	if (size == 0 || size <= j)
		return (size3 + size);
	while (src[i] && size - j - 1 > i)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + size3);
}
