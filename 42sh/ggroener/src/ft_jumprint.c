/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jumprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:38:12 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/10 16:38:14 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**Take out this function if not needed
*/

void		ft_jumprint(t_edit **lst)
{
	int				jump;
	int				i;
	struct winsize	ws;

	get_winsize(&ws);
	i = 0;
	jump = ((l_list(lst) + 3) / ws.ws_col) - ((ft_pcur(lst) + 3) / ws.ws_col);
	if (((l_list(lst) + 3) % ws.ws_col) != 0)
	{
		while (i < jump)
		{
			ft_tputs("do");
			i++;
		}
	}
}
