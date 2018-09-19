/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:36:11 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:15:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int value, int base)
{
	int		i;

	i = 0;
	if (value < 0 && base == 10)
		i++;
	if (value == 0)
		i++;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	int		sign;

	size = ft_intlen(value, base);
	if ((str = (char *)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	sign = (value < 0) ? -1 : 1;
	str[size--] = '\0';
	if (value < 0 && base == 10)
		str[0] = '-';
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		str[size] = value % base * sign;
		if (str[size] >= 10)
			str[size] += 7;
		str[size] += '0';
		value /= base;
		size--;
	}
	return (str);
}
