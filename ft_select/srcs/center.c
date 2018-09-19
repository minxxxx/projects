/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:10:58 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:11:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*ft_center(char *str, size_t size)
{
	size_t	k;
	size_t	l;
	size_t	m;
	char	*result;

	k = 0;
	size = ft_strlen(str);
	l = (size) / 2;
	m = 0;
	result = (char *)malloc(size + 1);
	result[size] = '\0';
	while (k < size && str[m])
	{
		if (l < k)
			result[k] = str[m];
		k++;
		m++;
	}
	return (result);
}
