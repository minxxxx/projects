/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:37:19 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/10 12:24:01 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buf;
	int		i;
	int		len;

	buf = (char*)s;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		else
		{
			i++;
			buf++;
		}
	}
	return (NULL);
}
