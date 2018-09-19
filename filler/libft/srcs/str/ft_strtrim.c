/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:36:18 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 05:51:12 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(s);
	i = 0;
	k = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i == j)
		return ("");
	j--;
	while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	if ((str = (char *)ft_memalloc((j - i) + 1)) == NULL)
		return (NULL);
	while (s[i] && i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
