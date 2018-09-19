/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:15:26 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:15:28 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_columns(int rows)
{
	int		result;
	int		k;

	result = 1;
	k = ft_termsize(1);
	if (ft_decal(rows, k))
		k--;
	rows -= k;
	while (rows > k && result >= 0)
	{
		result++;
		rows -= k;
	}
	if (rows > 1)
		result += 1;
	return (result);
}
