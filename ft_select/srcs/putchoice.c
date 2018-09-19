/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchoice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:17:32 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:17:34 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putchoice(int argc, t_choice **c, int p)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (k < argc - 1 && c[0][k].str != NULL)
	{
		if (c[0][k].check)
		{
			if (l++ && p)
				ft_putchar(' ');
			if (p)
				ft_putstr(c[0][k].str);
		}
		k++;
	}
	return (l);
}
