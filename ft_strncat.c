/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:51:47 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/27 09:57:56 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		i++;
		count++;
	}
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[count] = s2[i];
		i++;
		count++;
	}
	s1[count] = '\0';
	return (s1);
}
