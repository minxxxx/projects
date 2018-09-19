/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:20:40 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/12 16:23:19 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		nr_of_parts(const char *s, char c)
{
	int		i;
	int		len;
	int		word;

	i = 0;
	len = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && word == 1)
			word = 0;
		if (s[i] != c && word == 0)
		{
			word = 1;
			len++;
		}
		i++;
	}
	return (len);
}

static int	len_of_part(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*new_str(const char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**arr;
	int		parts;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		parts = nr_of_parts(s, c);
		if (!(arr = (char **)malloc(sizeof(*arr) * parts + 1)))
			return (NULL);
		while (parts > 0)
		{
			while (s[i] && s[i] == c)
				i++;
			arr[j] = new_str(&s[i], c);
			j++;
			i = i + len_of_part(s, c, i);
			parts--;
		}
		arr[j] = 0;
		return (arr);
	}
	return (NULL);
}
