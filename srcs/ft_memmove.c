/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 07:35:56 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 10:57:45 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	k;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (s > d)
	{
		k = -1;
		while (++k < len)
			d[k] = s[k];
	}
	else if (s < d)
	{
		k = len;
		while ((--k) > 0)
			d[k] = s[k];
		d[k] = s[k];
	}
	return (d);
}
