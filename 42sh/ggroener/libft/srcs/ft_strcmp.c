/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 11:54:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 11:01:02 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**My old one. Kalilo has too much safety code in his, used his one
**int	ft_strcmp(char const *s1, char const *s2)
**{
**	int				i;
**	unsigned char	*ptr_s1;
**	unsigned char	*ptr_s2;
**
**	ptr_s1 = (unsigned char *)s1;
**	ptr_s2 = (unsigned char *)s2;
**	i = 0;
**	while (ptr_s1[i] != '\0' || ptr_s2[i] != '\0')
**	{
**		if (ptr_s1[i] != ptr_s2[i])
**			return (ptr_s1[i] - ptr_s2[i]);
**		i++;
**	}
**	return (0);
**}
*/

static int	ft_diff(char s1, char s2)
{
	int	l;
	int	m;

	if (s1 < 0)
		m = 256 + s1;
	else
		m = s1;
	if (s2 < 0)
		l = 256 + s2;
	else
		l = s2;
	return (m - l);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int	k;

	k = 0;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && !(s2 == NULL))
			return (s2[0]);
		else if (!(s1 == NULL) && s2 == NULL)
			return (s1[0]);
		return (0);
	}
	while (s1[k] != '\0' && s2[k] != '\0')
	{
		if (s1[k] != s2[k])
			return (ft_diff(s1[k], s2[k]));
		k++;
	}
	if (s1[k] != '\0')
		return (ft_diff(s1[k], 0));
	else if (s2[k] != '\0')
		return (ft_diff(0, s2[k]));
	return (0);
}
