/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:52:30 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/11 11:28:54 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*newstr;

	if (s)
	{
		i = 0;
		while (s[i] && ft_isspace(s[i]))
			i++;
		j = ft_strlen(s) - 1;
		while (s[i] && ft_isspace(s[j]))
			j--;
		newstr = ft_strsub(s, i, j - i + 1);
		return (newstr);
	}
	return (0);
}
