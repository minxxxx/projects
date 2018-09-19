/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 02:23:24 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/24 03:09:24 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dst_tmp;
	char		*src_tmp;

	dst_tmp = (char*)dst;
	src_tmp = (char*)src;
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n)
		{
			dst_tmp[n - 1] = src_tmp[n - 1];
			n--;
		}
	}
	return (dst);
}
