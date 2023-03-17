/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:27:16 by abeaudui          #+#    #+#             */
/*   Updated: 2022/11/23 16:09:03 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	unsigned char	*bridge1;
	unsigned char	*bridge2;
	size_t			i;

	bridge1 = (unsigned char *)pointer1;
	bridge2 = (unsigned char *)pointer2;
	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (bridge1[i] != bridge2[i])
			return ((int)(bridge1[i] - bridge2[i]));
		i++;
	}
	return (0);
}
