/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:06:31 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/30 07:45:35 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	
	if (*little == '\0')
		return ((char*)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && big[i] && little[j])
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char*)&big[i - j]);
		}
		i -= j;
		i++;
	}
	return (NULL);
}
