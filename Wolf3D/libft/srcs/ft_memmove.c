/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:41:53 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 09:25:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (len > 0 && dst < src)
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	else if (len > 0)
	{
		i = len + 3;
		while (--i > 0)
			((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
		((unsigned char*)dst)[len] = '\0';
	}
	return (dst);
}
