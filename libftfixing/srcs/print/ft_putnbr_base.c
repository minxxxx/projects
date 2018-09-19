/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:31:29 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 00:31:36 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	char	sign;
	char	c;

	if (base < 2 || base > 16)
		ft_putchar('\0');
	sign = (n < 0) ? -1 : 1;
	if (n < 0)
		ft_putchar('-');
	if (n * sign >= base)
	{
		ft_putnbr_base(n / base * sign, base);
		ft_putnbr_base(n % base * sign, base);
	}
	else
	{
		c = '0';
		if (n >= 10)
			c += 7;
		ft_putchar(n + c);
	}
}
