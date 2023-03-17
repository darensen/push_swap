/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:17:13 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/23 16:16:56 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size )
{
	unsigned char	*place;
	size_t			i;

	place = (unsigned char *) memoryBlock;
	i = 0;
	while (i < size)
	{
		if (place[i] == (unsigned char) searchedChar)
			return (&place[i]);
	i++;
	}
	return (NULL);
}
