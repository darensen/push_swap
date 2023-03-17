/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:15:18 by dsenatus          #+#    #+#             */
/*   Updated: 2022/11/28 15:45:11 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	count;

	count = 1;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*result;
	long int	num;
	size_t		count;

	num = n;
	count = ft_count(num);
	result = malloc(sizeof(char ) * count);
	if (!result)
		return (NULL);
	if (num < 0)
	{
		result[0] = '-';
		num = num * -1;
	}
	if (num == 0)
		result[0] = '0';
	count--;
	result[count] = '\0';
	while (num)
	{
		result[count - 1] = num % 10 + '0';
		count--;
		num = num / 10;
	}
	return (result);
}
