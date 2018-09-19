/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:50:07 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:32:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	ptr;

	i = 0;
	j = 0;
	j = ft_strlen(str);
	j -= 1;
	while (i < j)
	{
		ptr = str[j];
		str[j] = str[i];
		str[i] = ptr;
		i++;
		j--;
	}
	return (str);
}
