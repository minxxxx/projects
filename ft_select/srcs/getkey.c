/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:16:51 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:16:54 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_getkey_debug(char *str)
{
	if (DEBUG)
	{
		ft_itoa((int)str);
		ft_signal(0);
	}
}

int			ft_getkey(char *str)
{
	int		k;

	ft_getkey_debug(str);
	k = (str[0] == 9 && str[1] == 000 && str[2] == 00) ? GKEY_TAB : -1;
	k = (str[0] == 10 && str[1] == 00 && str[2] == 00) ? GKEY_RTN : k;
	k = (str[0] == 27 && str[1] == 00 && str[2] == 00) ? GKEY_ESC : k;
	k = (str[0] == 32 && str[1] == 00 && str[2] == 00) ? GKEY_ESP : k;
	k = (str[0] == 42 && str[1] == 00 && str[2] == 00) ? GKEY_STAR : k;
	k = (str[0] == 43 && str[1] == 00 && str[2] == 00) ? GKEY_PLUS : k;
	k = (str[0] == 45 && str[1] == 00 && str[2] == 00) ? GKEY_MINUS : k;
	k = (str[0] == 46 && str[1] == 00 && str[2] == 00) ? GKEY_DOT : k;
	k = (str[0] == 47 && str[1] == 00 && str[2] == 00) ? GKEY_DIV : k;
	k = (str[0] == 48 && str[1] == 00 && str[2] == 00) ? GKEY_ZERO : k;
	k = (str[0] == 127 && str[1] == 0 && str[2] == 00) ? GKEY_BSP : k;
	k = (str[0] == 27 && str[1] == 91 && str[2] == 65) ? GKEY_UP : k;
	k = (str[0] == 27 && str[1] == 91 && str[2] == 66) ? GKEY_DOWN : k;
	k = (str[0] == 27 && str[1] == 91 && str[2] == 67) ? GKEY_RIGHT : k;
	k = (str[0] == 27 && str[1] == 91 && str[2] == 68) ? GKEY_LEFT : k;
	if (k != -1 && str[3] != 0)
		return (-1);
	else if (k == -1 && str[3] == 126)
		k = (str[0] == 27 && str[1] == 91 && str[2] == 51) ? GKEY_DEL : k;
	return (k);
}
