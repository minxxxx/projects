/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:43:15 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 11:08:33 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	int				len;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	i = -1;
	src_temp = (unsigned char*)src;
	dst_temp = (unsigned char*)dst;
	len = (int)n;
	while (i++ < len)
		if (src_temp[i] != (unsigned char)c)
			dst_temp[i] = src_temp[i];
		else
			return (&dst_temp[i + 1]);
	return (NULL);
}
