/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:56:38 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 08:56:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_put_char_int(unsigned char c)
{
	if (c >= 10)
		ft_put_char_int(c / 10);
	ft_putchar(c % 10 + '0');
}

void	put_bin(unsigned char *str)
{
	int		k;

	while (*str)
	{
		k = 256;
		while (k >>= 1)
			(k & *str) ? ft_putchar('1') : ft_putchar('0');
		ft_putchar(' ');
		if (*str < 10)
			ft_putstr("00");
		else if (*str < 100)
			ft_putchar('0');
		ft_put_char_int(*str);
		ft_putchar(' ');
		if (ft_isprint(*str))
			ft_putchar(*str);
		ft_putchar('\n');
		++str;
	}
}
