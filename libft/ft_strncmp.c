/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:24:28 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/28 17:39:20 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	n = n - 1;
	while ((s1[i] != '\0' && s1[i] == s2[i]) && (n > 0))
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - s2[i]);
}
