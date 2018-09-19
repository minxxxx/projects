/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:29:17 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/04 16:11:29 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_compare(char *str)
{
	if (str[0] == 'd' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u')
		return (1);
	if (str[0] == 's' || str[0] == 'c' || str[0] == 'x' || str[0] == 'U')
		return (1);
	if (str[0] == 'D' || str[0] == 'X' || str[0] == 'C' || str[0] == 'O')
		return (1);
	if (str[0] == 'p' || str[0] == 'S' || str[0] == '%')
		return (1);
	if (str[0] == '#' || str[0] == '0' || str[0] == '-' || str[0] == '+')
		return (2);
	if (str[0] == ' ')
		return (2);
	return (0);
}

char	*convert(unsigned int num, int base, int hex_upper)
{
	static char	hexupper[] = "0123456789ABCDEF";
	static char	hexlower[] = "0123456789abcdef";
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		if (hex_upper == 1)
		{
			*--ptr = hexupper[num % base];
			num /= base;
		}
		else
		{
			*--ptr = hexlower[num % base];
			num /= base;
		}
	}
	return (ptr);
}

int		printf_format(va_list ap, char *str)
{
	if (str[0] == '%' || str[0] == 's' || str[0] == 'c' || str[0] == 'C')
		return (printf_format1(ap, str));
	if (str[0] == 'S' || str[0] == 'p' || str[0] == 'd' || str[0] == 'i')
		return (printf_format_mod(ap, str));
	if (str[0] == 'o' || str[0] == 'O' || str[0] == 'u' || str[0] == 'U')
		return (printf_format_mod(ap, str));
	if (str[0] == 'D' || str[0] == 'x' || str[0] == 'X')
		return (printf_format_mod(ap, str));
	return (0);
}

int		printf_format1(va_list ap, char *str)
{
	if (str[0] == '%')
		ft_putchar('%');
	if (str[0] == 's')
		ft_putstr(va_arg(ap, char *));
	if (str[0] == 'c')
		ft_putchar(va_arg(ap, int));
	if (str[0] == 'C')
		ft_putchar(va_arg(ap, unsigned int));
	return (0);
}

int		printf_format_mod(va_list ap, char *str)
{
	if (str[0] == 'S')
		ft_putstr(convert(va_arg(ap, int), 16, 0));
	if (str[0] == 'p')
	{
		ft_putstr("0x7fff");
		ft_putstr(convert((unsigned)va_arg(ap, void *), 16, 0));
	}
	if (str[0] == 'd' || str[0] == 'i')
		ft_putnbr(va_arg(ap, int));
	if (str[0] == 'o' || str[0] == 'O')
		ft_putstr(convert(va_arg(ap, int), 8, 0));
	if (str[0] == 'u' || str[0] == 'U' || str[0] == 'D')
		ft_putstr(convert(va_arg(ap, unsigned int), 10, 0));
	if (str[0] == 'x')
		ft_putstr(convert(va_arg(ap, unsigned int), 16, 0));
	if (str[0] == 'X')
		ft_putstr(convert(va_arg(ap, unsigned int), 16, 1));
	return (0);
}
