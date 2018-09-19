/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delmenu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:15:42 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:15:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_delmenu(int *argc, t_choice **c, int *pos)
{
	int		k;
	int		l;

	k = *pos - 1;
	l = 0;
	while (++k < (*argc - 2) && c[0][k + 1].str != NULL)
	{
		c[0][k].str = c[0][k + 1].str;
		c[0][k].check = c[0][k + 1].check;
		c[0][k + 1].str = NULL;
		c[0][k + 1].check = 0;
		l++;
	}
	if (!(l))
	{
		if (!(*pos))
			ft_signal(1);
		c[0][*pos].str = NULL;
		c[0][*pos].check = 0;
		*pos -= 1;
	}
	*argc -= 1;
}
