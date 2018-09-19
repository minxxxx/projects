/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:20:40 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/10 08:27:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_t;
	char	*s2_t;

	i = -1;
	s1_t = (char*)s1;
	s2_t = (char*)s2;
	while (++i < n)
		if (s1_t[i] != s2_t[i])
			return (s1_t[i] - s2_t[i]);
	return (0);
}
