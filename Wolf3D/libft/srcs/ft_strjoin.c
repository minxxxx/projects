/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:25:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 09:27:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	size = i;
	i = 0;
	while (s2[i])
		i++;
	size = size + i + 1;
	result = malloc(sizeof(*result) * size);
	if (!result)
		return (result);
	i = -1;
	j = -1;
	while (s1[++i])
		result[++j] = s1[i];
	i = -1;
	while (s2[++i])
		result[++j] = s2[i];
	result[++j] = '\0';
	return (result);
}
