/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:19:11 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 11:29:35 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		src_size;
	int		i;

	i = 0;
	while (src[src_size])
		src_size++;
	s = (char*)malloc(sizeof(*s) * (src_size));
	while (i < src_size)
	{
		s[i] = src[i];
		i++;
	}
	s[src_size] = '\0';
	return (s);
}
