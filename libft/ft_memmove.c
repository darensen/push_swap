/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:43:47 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/28 15:43:54 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	if (!src && !dest)
		return (NULL);
	str1 = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (str1 <= str)
	{
		while (i < n)
		{
			str1[i] = str[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			str1[n] = str[n];
	}
	return (dest);
}
