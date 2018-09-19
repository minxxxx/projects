/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 10:31:02 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/28 22:38:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	temp_dst = (unsigned char*)dst;
	temp_src = (unsigned char*)src;	
	if (temp_src < temp_dst)
	{
		while (len--)
			temp_dst[len] = temp_src[len];
	}
	else
		ft_memcpy(temp_dst, temp_src, len);
	return (temp_dst);
} 
