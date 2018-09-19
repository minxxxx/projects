/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:48:42 by amkhuma           #+#    #+#             */
/*   Updated: 2017/06/18 13:40:41 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ds;
	const char	*sr;
	size_t		i;

	i = -1;
	ds = (char *)s1;
	sr = (char *)s2;
	if (sr < ds)
		while ((int)(--n) >= 0)
			*(ds + n) = *(sr + n);
	else
		while (++i < n)
			*(ds + i) = *(sr + i);
	return (s1);
}
