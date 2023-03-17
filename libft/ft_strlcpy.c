/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:59:42 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/22 16:06:48 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	if (size != 0)
	{
		while (src[i] && size - 1 > 0)
		{
			dst[i] = src[i];
			i++;
			size--;
		}
	}
	dst[i] = '\0';
	return (len);
}
