/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:42:03 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/14 12:52:12 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = ((unsigned char *)dest);
	str2 = ((unsigned char *)src);
	if (str1 > str2)
	{
		while (i < len)
		{
			str1[len - 1] = str2[len - 1];
			len--;
		}
		return (dest);
	}
	else
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	return (dest);
}
