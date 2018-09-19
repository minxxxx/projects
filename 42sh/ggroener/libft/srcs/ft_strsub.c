/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 07:38:14 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 10:32:04 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*re;
	int		i;

	i = 0;
	re = ft_strnew(len + 1);
	if (re == NULL)
		return (NULL);
	len = len + start;
	if (start < ft_strlen(s))
	{
		while (s[start] != '\0' && start < len)
		{
			re[i] = s[start];
			start++;
			i++;
		}
	}
	re[i] = '\0';
	return (re);
}
