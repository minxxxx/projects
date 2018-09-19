/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 16:10:48 by jbuys             #+#    #+#             */
/*   Updated: 2016/07/22 11:16:28 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*tmp;

	tmp = (char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}
