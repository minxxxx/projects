/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:24:55 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/24 17:25:38 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int value)
{
	int		i;

	i = 0;
	if (value < 0)
		i++;
	if (value == 0)
		i++;
	while (value)
	{
		value /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int value)
{
	char	*str;
	int		size;
	int		sign;

	size = ft_intlen(value);
	str = (char *)ft_memalloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	sign = (value < 0) ? -1 : 1;
	str[size--] = '\0';
	if (value < 0)
		str[0] = '-';
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		str[size] = value % 10 * sign + '0';
		value /= 10;
		size--;
	}
	return (str);
}
