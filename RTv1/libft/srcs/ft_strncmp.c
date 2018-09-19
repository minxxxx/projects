/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:03:17 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 13:56:05 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	c2 = (unsigned char)*s2;
	c1 = (unsigned char)*s1;
	while (c1 == c2 && c1 != '\0' && c2 != '\0')
	{
		i++;
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
	}
	while (c1 != '\0' && c2 != '\0' && i < n)
	{
		if (c1 != c2)
			return (c1 - c2);
		i++;
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
	}
	return (0);
}
