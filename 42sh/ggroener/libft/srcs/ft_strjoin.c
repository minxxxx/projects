/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 07:41:18 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 09:35:57 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**My old strjoin that did not check for NULL in any of the strings
**char	*ft_strjoin(char const *s1, char const *s2)
**{
**	int		size;
**	char	*re;
**	int		i;
**
**	size = ft_strlen(s1) + ft_strlen(s2) + 1;
**	if (!(re = (char *)malloc((sizeof(char) * size))))
**		return (NULL);
**	i = 0;
**	while (*s1 && i < size)
**		re[i++] = *s1++;
**	while (*s2 && i < size)
**		re[i++] = *s2++;
**	re[i] = '\0';
**	return (re);
**}
*/

static char	*ft_malloc(char const *s1, char const *s2)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (s1 && s1[k] != '\0')
		k++;
	while (s2 && s2[l] != '\0')
		l++;
	return ((char *)malloc(k + l + 1));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	int		l;
	char	*temp;

	temp = ft_malloc(s1, s2);
	if (temp == NULL)
		return (NULL);
	k = 0;
	while (s1 && s1[k] != '\0')
	{
		temp[k] = s1[k];
		k++;
	}
	l = 0;
	while (s2 && s2[l] != 0)
	{
		temp[k + l] = s2[l];
		l++;
	}
	if (k > 0)
		temp[k + l] = '\0';
	else
		temp[l] = '\0';
	return (temp);
}
