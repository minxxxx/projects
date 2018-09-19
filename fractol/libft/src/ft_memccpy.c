/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:13:08 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/24 10:31:32 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*srcs;

	i = 0;
	dest = (char *)dst;
	srcs = (char *)src;
	while (i < n)
	{
		dest[i] = srcs[i];
		if (dest[i] == (unsigned char)c)
		{
			dest[i] = (unsigned char)srcs[i];
			return (dest + 1);
		}
		i++;
	}
	return (NULL);
}
