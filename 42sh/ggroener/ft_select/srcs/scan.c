/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:18:03 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:18:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		allowed_keys(int key, t_search **s)
{
	if (!(s != NULL && *s != NULL && s[0][0].str != NULL))
		return (0);
	if (key == GKEY_UP || key == GKEY_RIGHT || key == GKEY_LEFT)
		return (1);
	if (key == GKEY_PLUS || key == GKEY_MINUS || key == GKEY_STAR)
		return (1);
	if (key == GKEY_RTN || key == GKEY_ESC || key == GKEY_DEL)
		return (1);
	if (key == GKEY_DIV || key == GKEY_ZERO)
		return (1);
	return (0);
}

int		ft_too_small(int argc)
{
	static int k;

	if (ft_termsize(0) < 60 || ft_termsize(1) < (20 + argc))
	{
		ft_clear();
		ft_cmdgoto(0, 0);
		ft_putstr_fd("\e[41mWindow is too small!\n", isatty(1));
		k = 1;
		return (0);
	}
	if (k == 1)
		ft_clear();
	k = 0;
	return (1);
}
