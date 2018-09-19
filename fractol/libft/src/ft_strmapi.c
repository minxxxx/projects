/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:44:03 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/09 15:59:45 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		i;

	i = 0;
	str = ft_strdup(s);
	if (str == NULL || !s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
