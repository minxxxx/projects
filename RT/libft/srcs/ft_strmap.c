/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:08:38 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/11 11:28:17 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fstr;

	i = 0;
	fstr = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		fstr[i] = f(s[i]);
		i++;
	}
	return (fstr);
}
