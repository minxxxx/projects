/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversebit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:31:03 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:15:26 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reversebit(unsigned char octet)
{
	unsigned char	read;
	unsigned char	write;
	unsigned char	result;

	read = 1;
	write = 128;
	result = 0;
	while (read)
	{
		if (octet & read)
			result |= write;
		read <<= 1;
		write >>= 1;
	}
	return (result);
}
