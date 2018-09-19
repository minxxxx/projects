/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:59:42 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/24 10:33:14 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*srcs;

	i = 0;
	dest = (char *)dst;
	srcs = (char *)src;
	if (len == 0)
		return (dest);
	while (i < len)
	{
		dest[i] = srcs[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
