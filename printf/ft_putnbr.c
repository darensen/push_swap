/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:55:52 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 13:58:07 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-214748364", 10);
		i = 10;
		nb = 8;
	}
	if (nb >= 0 && nb <= 9)
		i += ft_putchar(nb + 48);
	else if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
		i += ft_putnbr(nb);
	}
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}
