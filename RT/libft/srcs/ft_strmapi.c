/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:08:38 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/14 11:23:06 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fstr;

	i = 0;
	fstr = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	return (fstr);
}
