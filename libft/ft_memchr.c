/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:16:58 by amkhuma           #+#    #+#             */
/*   Updated: 2017/06/18 12:17:04 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	char		tmp;
	char		*tmp2;

	tmp = (unsigned char)c;
	tmp2 = (char*)s1;
	while (n--)
	{
		if (*tmp2 == tmp)
			return (tmp2);
		tmp2++;
	}
	return (NULL);
}
