/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 08:56:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/06 09:14:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill(char const *str, char sp, char **result)
{
	int		start;
	int		pos;
	int		i;

	pos = 0;
	start = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] != sp)
			if (i == 0 || str[i - 1] == sp)
				start = i;
		if (start != -1 && (str[i + 1] == sp || str[i + 1] == '\0'))
		{
			result[pos] = ft_strsub(str, start, i - start + 1);
			start = -1;
			pos++;
		}
		i++;
	}
}

char			**ft_strsplit(char const *str, char sp)
{
	char	**result;
	int		count;
	int		i;

	if (!str)
		return (NULL);
	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] != sp)
			if (i == 0 || str[i - 1] == sp)
				count++;
		i++;
	}
	if (!(result = malloc(sizeof(*result) * count)))
		return (NULL);
	fill(str, sp, result);
	result[count - 1] = NULL;
	return (result);
}
