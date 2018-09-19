/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:14:54 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/28 17:57:33 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void		sanity_check(void)
{
	write(1, "[ERROR] : Not enough bytes in *s\n", 33);
	write(1, "zsh: abort\n", 11);
	exit(-1);
}

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	while (((char*)s)[j] != '\0')
		j++;
	if (n > j)
		sanity_check();
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((unsigned char*)s + i);
		i++;
	}
	return (NULL);
}
