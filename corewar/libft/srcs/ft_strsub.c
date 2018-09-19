/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:00:07 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/11 13:16:40 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*fresh;

	i = start;
	l = 0;
	fresh = ft_strnew(len + 1);
	while (s[i] != '\0' && l < len)
	{
		fresh[l] = s[i];
		i++;
		l++;
	}
	if (*fresh)
		fresh[l] = '\0';
	return (fresh);
}
