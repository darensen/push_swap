/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudui <abeaudui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:15:05 by abeaudui          #+#    #+#             */
/*   Updated: 2022/12/06 16:19:53 by abeaudui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if ((nmemb >= SIZE_MAX) || (size >= SIZE_MAX))
		return (NULL);
	str = malloc(nmemb * size);
	if (str == 0)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}
