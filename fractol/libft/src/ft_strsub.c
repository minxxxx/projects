/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:56:51 by jbuys             #+#    #+#             */
/*   Updated: 2016/07/28 13:10:15 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char *) * (len + 1));
	i = 0;
	if (str == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = str[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
