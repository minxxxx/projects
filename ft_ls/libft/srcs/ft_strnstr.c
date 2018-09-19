/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:58:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 09:28:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while ((s1[i + j] == s2[j] || !s2[j]))
		{
			if (!s2[j])
				return ((char*)(s1 + i));
			else if (i + j >= n)
				return (NULL);
			j++;
		}
		i++;
	}
	return (NULL);
}
