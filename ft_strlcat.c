/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:18:34 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/30 12:45:00 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t s1;

	s1 = 0;
	i = 0;
	if (n == 0)
		dst = (char*)src;
	else
	{	
		while (dst[i] && i < n)
			i++;
		s1 = i;
		while (src[i - s1] && i < n - 1)
		{
			dst[i] = src[i - s1];
			i++;
		}
		if (s1 < n)
			dst[i] = '\0';
	}
	return (s1 + ft_strlen(src));
}
