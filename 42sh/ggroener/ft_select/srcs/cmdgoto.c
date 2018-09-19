/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdgoto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:14:29 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:14:30 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_cmdgoto(int x, int y)
{
	char	*k;
	char	*l;

	if (((k = tgetstr("cm", NULL)) != NULL) && \
		(l = tgoto(k, x, y)) != NULL)
		ft_putstr_fd(l, isatty(1));
	return (1);
}
