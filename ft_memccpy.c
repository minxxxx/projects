/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:03:58 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/28 21:25:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char 		*dest;
	const unsigned char	*sour;
	unsigned char		ch;

	dest = (unsigned char *)dst;
	sour = (const unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dest++ = *sour++) == ch)
			return (dest);
		i++;
	}
	return (NULL);
}
