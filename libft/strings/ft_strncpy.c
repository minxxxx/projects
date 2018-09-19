/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:03:07 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/31 17:32:13 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	ft_memset(dest, '\0', len);
	while (src[i] != '\0' && len > 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	return (dest);
}
