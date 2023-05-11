/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:36:41 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 13:48:24 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int nb)
{
	int	i;

	i = 0;
	if (nb <= 15)
		i += ft_putchar("0123456789abcdef"[nb]);
	if (nb > 15)
	{
		i += ft_puthex(nb / 16);
		i += ft_puthex(nb % 16);
	}
	return (i);
}
