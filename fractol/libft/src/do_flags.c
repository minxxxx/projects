/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 07:59:18 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/10 08:46:35 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		do_flags(va_list ap, char *str)
{
	if (str[0] == '+')
		return (do_plus(ap, str));
	if (str[0] == '-')
		return (do_minus(ap, str));
	if (str[0] == '#')
		return (do_hash(ap, str));
	if (str[0] == ' ')
		return (do_space(ap, str));
	return (0);
}

int		do_hash(va_list ap, char *str)
{
	int		len;
	int		i;

	len = 0;
	i = 1;
	while (str[i] >= '0' && str[i] <= 9)
		i++;
	if (str[i] == 'o' || str[i] == 'O')
	{
		ft_putchar('0');
		len = printf_format(ap, &str[i]);
	}
	if (str[i] == 'x')
	{
		ft_putstr("0x");
		len = printf_format(ap, &str[i]);
	}
	if (str[i] == 'X')
	{
		ft_putstr("0X");
		len = printf_format(ap, &str[i]);
	}
	return (1 + i);
}

int		do_plus(va_list ap, char *str)
{
	int		num;

	if (str[0] == '+' && (str[1] == 'd' || str[1] == 'i'))
	{
		if ((num = va_arg(ap, int)) > 0)
		{
			ft_putchar('+');
			ft_putnbr(num);
		}
		else
			ft_putnbr(num);
	}
	return (2);
}

int		do_minus(va_list ap, char *str)
{
	int		i;
	size_t	num;
	size_t	len;
	char	temp[10];

	i = 0;
	str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	num = ft_atoi(temp);
	len = printf_format(ap, &str[i]) + ft_count_ui_num(num, 10);
	if (str[i] == 'c' || str[i] == 'C')
		len = 1;
	while (num-- > len)
		ft_putchar(' ');
	return (2 + i);
}

int		do_space(va_list ap, char *str)
{
	int		i;
	size_t	num;
	size_t	src;
	char	temp[10];

	i = 0;
	if (str[0] == '+')
		return (1 + do_plus(ap, str));
	src = va_arg(ap, int);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] != 'i' || str[i] != 'd')
		exit(-1);
	num = ft_atoi(temp);
	if (src > 0)
		ft_putchar(' ');
	ft_putnbr(src);
	return (2 + i);
}
