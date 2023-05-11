/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:00:29 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 13:49:51 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexm(unsigned long int nb)
{
	int	i;

	i = 0;
	if (nb <= 15)
		i += ft_putchar("0123456789ABCDEF"[nb]);
	if (nb > 15)
	{
		i += ft_puthexm(nb / 16);
		i += ft_puthexm(nb % 16);
	}
	return (i);
}
