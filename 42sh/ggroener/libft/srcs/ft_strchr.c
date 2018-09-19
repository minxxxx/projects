/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:57:08 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 10:15:17 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (*(s + count) != '\0' || (char)c == '\0')
	{
		if (*(s + count) == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	return (NULL);
}
