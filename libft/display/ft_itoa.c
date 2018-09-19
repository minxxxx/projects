/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:48:30 by lmucassi          #+#    #+#             */
/*   Updated: 2017/11/20 13:45:38 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static int	ft_sign(int c)
{
	if (c < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_size_base(n, 10);
	str = NULL;
	sign = ft_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (len + sign + 1));
	if (str)
	{
		str = str + sign + len;
		*str = '\0';
		if (!n)
			*--str = '0';
		while (n != 0)
		{
			*--str = ft_abs(n % 10) + '0';
			n /= 10;
		}
		if (sign)
			*--str = '-';
	}
	return (str);
}
