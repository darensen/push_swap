/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:09:36 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/04 15:24:22 by dsenatus         ###   ########.fr       */
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
