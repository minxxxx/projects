/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_literal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 14:14:46 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/07 10:28:03 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#define VAR1 char lit; char check; char *dest; size_t i; size_t j
#define INIT_VAR i = -1; j = 0

char	*ft_replace_literal(char *str)
{
	VAR1;
	INIT_VAR;
	dest = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[++i] != '\0' && str[i])
	{
		if ((lit = ft_check_literal(str[i], str[i + 1], str[i + 2])) != 32)
		{
			dest[j] = lit;
			check = 'y';
			i = i + 3;
			j++;
		}
		if (((lit = ft_check_literal2(str[i], str[i + 1])) != 32) && check !=
				'y')
		{
			dest[j] = lit;
			i = i + 2;
			j++;
		}
		dest[j] = str[i];
		check = 'n';
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
