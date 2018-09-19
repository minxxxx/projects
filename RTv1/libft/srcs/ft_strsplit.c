/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:14:44 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/30 12:06:57 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	parts;

	i = 0;
	parts = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			parts++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (parts);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**fresh;
	int		len;

	i = 0;
	while (*s && *s == c)
		s++;
	fresh = (char**)malloc(sizeof(char*) * word_count(s, c) + 1);
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		fresh[i] = ft_strnew(len);
		ft_strncpy(fresh[i], s, len);
		s = s + len;
		i++;
	}
	fresh[i] = NULL;
	return (fresh);
}
