/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:52:30 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/27 12:06:41 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;
	size_t			size;
	unsigned int	k;

	size = ft_strlen((char*)(s + start));
	if (len > size)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len));
	k = start + len;
	i = 0;
	while (start < k)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
