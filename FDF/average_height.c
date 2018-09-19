/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:37:43 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:25:24 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	average_height(char ***buffer)
{
	int		i;
	int		j;
	float	k;
	int		l;

	i = 0;
	k = 0;
	l = 0;
	while (buffer[i])
	{
		j = 0;
		while (buffer[i][j])
		{
			if (ft_atoi(buffer[i][j]) != 0)
				l++;
			if (ft_atoi(buffer[i][j]) < 0)
				k += (ft_atoi(buffer[i][j]) * -1);
			else if (ft_atoi(buffer[i][j]) > 0)
				k += ft_atoi(buffer[i][j]);
			j++;
		}
		i++;
	}
	return (l ? k /= l : k);
}
