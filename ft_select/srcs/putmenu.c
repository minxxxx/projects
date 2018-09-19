/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmenu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:17:46 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/17 09:44:43 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_infos(int argc, t_choice **c)
{
	int			k;
	int			num;
	char		*temp;
	char		*tty;

	k = ft_termsize(1);
	ft_cmdgoto(0, k - 1);
	ft_cmdput("mr");
	ft_putstr_fd("\033[2;49;90m", isatty(1));
	ft_putchar_loop_fd(' ', isatty(1), ft_termsize(0));
	ft_cmdgoto(0, k - 1);
	num = ft_putchoice(argc, c, 0);
	ft_putstr_fd("Selected: (removed)", isatty(1));
	ft_cmdgoto((ft_termsize(0) - 24) / 2, k - 1);
	ft_putstr_fd("Multi Selector", isatty(1));
	if ((temp = ttyname(isatty(1))) != NULL)
	{
		temp = ft_strdup(temp);
		tty = ft_strncmp(temp, "/dev/", 4) ? temp : temp + 5;
		ft_cmdgoto(ft_termsize(0) - ft_strlen(tty) - 1, k - 1);
		ft_putstr_fd(tty, isatty(1));
		free(temp);
	}
	ft_putstr_fd(" \033[049;39m", isatty(1));
	ft_cmdput("me");
}

void			ft_putmenu(int argc, t_choice **c, int pos, int key)
{
	int			k;
	int			l;
	int			m;

	if ((k = -1) && c[0][0].str == NULL)
		ft_signal(1);
	while (++k < (ft_termsize(1) - 1) && !(l = 0))
	{
		m = k;
		while (k < argc && m < argc - 1 && c[m]->str != NULL)
		{
			ft_cmdgoto(0, k);
			ft_cmdput("me");
			ft_colour(c[m]->str, 0, m, pos);
			if (c[m]->check)
				ft_cmdput("mr");
			if (!ft_putstr_s(c[m]->str, argc, m, pos))
				return ;
			ft_cmdput("me");
			ft_putstr_fd("033[0m", isatty(1));
			m = k + (++l * (ft_termsize(1) - 1));
		}
	}
	ft_infos(argc, c);
	ft_caption(key, 0);
}
