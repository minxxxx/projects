/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:35:28 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/04 17:11:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_octal(unsigned int n)
{
	if (n >= 8)
		return (ft_printf_octal(n / 8) + ft_printf_hex(n % 8));
	else
		return (ft_printf_char(48 + n));
}

void	ft_putnbr_lf(double n)
{
	long	nb;

	ft_putnbr_ld((long)n);
	nb = n * 1000000;
	n = (long)n * 1000000;
	ft_putchar('.');
	ft_putnbr_ld(nb - n);
}

void	ft_putnbr_ld(long n)
{
	if (n == -9223372036854775807)
		ft_putstr("-9223372036854775807");
	else if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
		ft_putnbr_ld(n);
	}
	else if (n >= 10)
	{
		ft_putnbr_ld(n / 10);
		ft_putnbr_ld(n % 10);
	}
	else
		ft_putchar(48 + n);
}

int		ft_printf_nbr_lf(double n)
{
	long	nb;

	ft_printf_nbr_ld((long)n);
	nb = n * 1000000;
	n = (long)n * 1000000;
	ft_printf_char('.');
	return (ft_printf_nbr_ld(nb - n) + 1);
}
