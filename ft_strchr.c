/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:37:13 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/29 16:00:29 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s != (char)c &&  *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
