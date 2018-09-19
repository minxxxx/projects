/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:37:28 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/09 15:56:01 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t		i;
	char		*str;

	str = ft_strdup(s);
	i = 0;
	if (str == NULL || !s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
