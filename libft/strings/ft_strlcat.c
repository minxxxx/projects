/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 12:36:59 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/14 14:35:01 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t c;
	size_t res;

	i = 0;
	c = 0;
	res = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] != '\0' && i < size)
		i++;
	if ((size - i) == 0)
		return (i + ft_strlen(src));
	while (i != (size - 1) && src[c] != '\0')
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	dest[i] = '\0';
	return (res);
}
