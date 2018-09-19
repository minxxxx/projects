/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:58:06 by lmucassi          #+#    #+#             */
/*   Updated: 2017/08/07 14:01:24 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	else
	{
		str = ft_strnew(ft_strlen(s));
		if (!str)
			return (NULL);
		else
		{
			i = 0;
			while (s[i] != '\0')
			{
				str[i] = f(s[i]);
				i++;
			}
		}
	}
	return (str);
}
