/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:53:55 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/10 12:35:34 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;
	int		i;

	i = ft_strlen(s);
	buf = (char*)s + i;
	while (i >= 0)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		else
		{
			i--;
			buf--;
		}
	}
	return (NULL);
}
