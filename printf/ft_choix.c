/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:44:15 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 13:45:10 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choix(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(arg, int));
	if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		i += ft_putp(va_arg(arg, unsigned long int));
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		i += ft_putuint(va_arg(arg, unsigned int));
	if (c == 'x')
		i += ft_puthex(va_arg(arg, unsigned int));
	if (c == 'X')
		i += ft_puthexm(va_arg(arg, unsigned int));
	return (i);
}
