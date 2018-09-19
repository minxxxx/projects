/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:31:58 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:15:14 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbit(unsigned char octet)
{
	unsigned char	i;

	i = 1 << 7;
	while (i > 0)
	{
		if (octet & i)
			ft_putchar('1');
		else
			ft_putchar('0');
		i >>= 1;
	}
}
