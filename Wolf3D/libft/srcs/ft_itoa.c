/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:38:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/05 09:37:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;

	size = n < 0 ? 2 : 1;
	n = n < 0 ? -n : n;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	size;
	size_t	j;
	size_t	i;
	size_t	nb;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n < 0 ? -n : n;
	size = get_size(n);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	if (n < 0)
		result[0] = '-';
	j = 1;
	i = 1;
	while (nb / j > 0)
	{
		result[size - i++ - 1] = (nb / j) % 10 + '0';
		j = j * 10;
	}
	result[size - 1] = '\0';
	return (result);
}
