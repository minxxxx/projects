/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:18:00 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 09:15:52 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*fresh;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	fresh = ft_strnew(len);
	while (*s1)
	{
		fresh[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		fresh[i++] = *s2;
		s2++;
	}
	fresh[len] = '\0';
	return (fresh);
}
