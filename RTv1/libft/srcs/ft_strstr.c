/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:28:43 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 13:46:35 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		l_len;

	l_len = ft_strlen(little);
	if (ft_strlen(big) >= ft_strlen(little) && little != NULL)
	{
		while (*big)
		{
			i = 0;
			while (big[i] != '\0' && little[i] != '\0' && big[i] == little[i])
				i++;
			if (i == l_len)
				return (ft_strdup(big));
			big++;
		}
	}
	return (NULL);
}
