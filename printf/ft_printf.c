/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:36:39 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 14:59:04 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		y;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != '%')
			y += ft_putchar(str[i]);
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				y += ft_putchar(str[i]);
			y += ft_choix(str[i + 1], arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (y);
}
