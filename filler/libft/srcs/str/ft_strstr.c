/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 02:51:38 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/24 02:51:54 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			while (s2[j] == s1[i] && s2[j])
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)s1 + i - j);
			i = i - (j - 1);
		}
		i++;
	}
	return (NULL);
}
