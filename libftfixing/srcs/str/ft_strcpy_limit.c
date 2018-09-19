/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 04:22:10 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/13 04:22:12 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy_limit(char *str, char n)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] && str[i] != n)
		i++;
	if ((dst = (char *)ft_memalloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
