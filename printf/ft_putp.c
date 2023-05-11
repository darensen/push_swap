/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:42:47 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 14:00:05 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(unsigned long int nb)
{
	int	res;

	res = 0;
	if (!nb)
	{
		ft_putstr("(nil)");
		return (5);
	}
	res += ft_putstr("0x");
	res += ft_puthex(nb);
	return (res);
}
