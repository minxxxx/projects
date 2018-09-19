/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 13:34:41 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/09 16:40:51 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dest;
	const char		*srcs;

	dest = (char *)dst;
	srcs = (char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dest);
}
