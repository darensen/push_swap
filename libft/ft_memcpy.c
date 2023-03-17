/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:51:03 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/23 20:36:22 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			y;
	unsigned char	*str;
	unsigned char	*str2;

	y = 0;
	i = 0;
	if (!dest && !src)
		return (NULL);
	str = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (n > i)
	{
		str[y] = str2[y];
		i++;
		y++;
	}
	return ((unsigned char *)dest);
}
