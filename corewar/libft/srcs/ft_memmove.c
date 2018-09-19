/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:56:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/14 08:35:50 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src_temp;
	char	*dst_temp;

	if (n == 0)
		return ((char*)dst);
	i = 0;
	src_temp = (char*)ft_strdup(src);
	dst_temp = (char*)dst;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	i = n;
	return (dst);
}
