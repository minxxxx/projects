/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcirc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:17:40 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/17 17:18:36 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_putcirc_infos(int argc, t_choice **c, int y)
{
	int				num;
	char			*temp;

	ft_cmdgoto(3, y);
	num = ft_putchoice(argc, c, 0);
	ft_cmdgoto(3, y);
	ft_putstr_fd("\033[32mSelected: ", isatty(1));
	temp = ft_itoa(num);
	ft_putstr_fd(temp, isatty(1));
	ft_putchar_loop_fd(' ', isatty(1), (ft_termsize(0) - 9) / 2);
	free(temp);
	ft_cmdgoto(ft_termsize(0) - 21, y);
	ft_putstr_fd("khansman & ggroener", isatty(1));
}

static int		ft_putcirc_decal(int argc, t_choice **c)
{
	int				k;

	k = (argc < ft_termsize(1)) ? (ft_termsize(1) - argc) / 2 : 0;
	k += (ft_termsize(1) % 2) ? 1 : 0;
	ft_putcirc_infos(argc, c, k - 1);
	ft_cmdgoto((ft_termsize(0) - 9) / 2, k - 1);
	ft_putstr_fd("<ft_select>", isatty(1));
	ft_cmdgoto(1, k);
	ft_putstr_fd("\033[2;49;90m", isatty(1));
	ft_putchar_fd('/', isatty(1));
	ft_putchar_loop_fd('=', isatty(1), ft_termsize(0) - 4);
	ft_putchar_fd('\\', isatty(1));
	ft_putstr_fd("\033[2;49;90m", isatty(1));
	ft_cmdgoto(1, k + argc);
	ft_putstr_fd("\033[2;49;90m", isatty(1));
	ft_putchar_fd('\\', isatty(1));
	ft_putchar_loop_fd('=', isatty(1), ft_termsize(0) - 4);
	ft_putchar_fd('/', isatty(1));
	ft_putstr_fd("\033[0;49;39m", isatty(1));
	k++;
	return (k);
}

static void		ft_style(int argc, t_choice **c, int pos)
{
	int				k;
	int				l;
	int				m;
	static int		n;

	k = 0;
	n = ft_putcirc_decal(argc, c);
	while (!(l = 0) && k < ft_termsize(1))
	{
		m = k;
		ft_cmdgoto(0, k + n);
		while (k < argc && m < argc - 1 && c[0][m].str != NULL)
		{
			ft_cmdput("me");
			ft_colour(c[0][m].str, 0, m, pos);
			if (c[0][m].check)
				ft_cmdput("mr");
			if (!(ft_putstr_s(c[0][m].str, argc, m, pos)))
				return ;
			ft_cmdput("me");
			ft_putstr_fd("\033[0m", isatty(1));
			m = k + (++l * ft_termsize(1));
		}
		k++;
	}
}

static int		ft_resize(int *argc, t_choice ***c, int **pos, t_putmenu **s)
{
	int				k;

	k = 0;
	if (*c == NULL)
	{
		if (*s == NULL)
			ft_signal(0);
		*argc = s[0][0].argc;
		*pos = s[0][0].pos;
		*c = s[0][0].choice;
		ft_clear();
		k = 1;
	}
	else
	{
		if (*s == NULL && (k = 1))
			*s = (t_putmenu *)malloc(sizeof(t_putmenu));
		s[0][0].argc = *argc;
		s[0][0].pos = *pos;
		s[0][0].choice = *c;
	}
	return (k);
}

void			ft_putcirc(int argc, t_choice **c, int *pos, int key)
{
	int					k;
	static t_putmenu	*menu;

	if (ft_too_small(argc))
	{
		k = ft_termsize(1);
		ft_caption(0, 1);
		ft_resize(&argc, &c, &pos, &menu);
		if (c[0][0].str == NULL)
			ft_signal(1);
		ft_colour(NULL, key, 0, 0);
		ft_check(argc, key, c, pos);
		if (ft_decal(argc, k))
		{
			ft_putmenu(argc, c, *pos, key);
			return ;
		}
		ft_style(argc, c, *pos);
		ft_caption(key, 0);
	}
}
