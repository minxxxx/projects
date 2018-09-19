/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:15:36 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/30 10:40:49 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *littl, size_t len)
{
	size_t	i;

	if ((*littl == '\0'))
		return ((char*)big);
	i = 0;
	while (*big && len)
	{
		if (*big == littl[i])
			i++;
		else
			i = 0;
		if (littl[i] == '\0')
			return ((char*)(big - i + 1));
		big++;
		len--;
	}
	return (NULL);
}
