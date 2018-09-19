/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 08:50:18 by vivan-de          #+#    #+#             */
/*   Updated: 2016/07/23 09:16:32 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub(char const *s, int i, char c)
{
	int		j;
	int		index;
	int		start;
	char	*str;

	j = 0;
	index = 0;
	while (j <= i)
	{
		start = index;
		while (s[index] && s[index] != c)
			index++;
		index++;
		j++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (index - start) + 1)))
		return (NULL);
	j = 0;
	index = index - start;
	while (j + 1 < index)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}

int		count(char const *s, char c)
{
	int		i;
	int		counter;

	i = 0;
	counter = 1;
	while (s[i])
		if (s[i++] == c)
			counter++;
	return (counter);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**sa;
	int		size;
	int		i;

	size = count(s, c);
	if (!(sa = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	sa[size] = NULL;
	i = 0;
	while (i < size)
	{
		if (!(sa[i] = sub(s, i, c)))
			return (NULL);
		i++;
	}
	return (sa);
}
