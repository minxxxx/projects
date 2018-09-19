/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:11:17 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/14 07:55:51 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev(char *buf, int i)
{
	char	*fresh;
	int		j;

	j = 0;
	fresh = (char*)malloc(sizeof(char) * i);
	while (i)
		fresh[j++] = buf[--i];
	return (fresh);
}

char		*ft_itoa(int n)
{
	char	buf[12];
	int		i;
	int		min;

	if (n == 0)
		return ("0\0");
	i = 0;
	buf[i++] = '\0';
	min = (n < 0);
	if (min)
		n = n * -1;
	while (n)
	{
		buf[i++] = n % 10 + '0';
		n = (n - n % 10) / 10;
	}
	if (min)
		buf[i++] = '-';
	return (rev(buf, i));
}
