/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsenatus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:27:08 by dsenatus          #+#    #+#             */
/*   Updated: 2022/12/15 14:03:45 by dsenatus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_choix(char c, va_list arg);
int	ft_putnbr(int n);
int	ft_putuint(unsigned int nb);
int	ft_puthex(unsigned long int nb);
int	ft_puthexm(unsigned long int nb);
int	ft_putp(unsigned long int nb);

#endif
