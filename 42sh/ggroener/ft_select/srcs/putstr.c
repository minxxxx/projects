/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:17:55 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:17:56 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_cursor(char *str, int argc, int end)
{
	int		k;
	int		l;

	l = ft_termsize(0) / ft_columns(argc);
	k = (l - ft_strlen(str)) / 2;
	if (end)
		k = l - (k + ft_strlen(str));
	return (k);
}

int			ft_putstr_s(char *str, int argc, int col, int pos)
{
	int		num;
	char	*p;

	if ((num = ft_cursor(str, argc, 0)) > 0)
		ft_putchar_loop_fd(' ', isatty(1), num);
	else
	{
		ft_clear();
		num = ft_termsize(1) / 2;
		num -= (ft_termsize(1) % 2) ? 0 : 1;
		ft_cmdgoto((ft_termsize(0) - 36) / 2, num);
		p = ft_strdup("\033[49;31mWindow is too small for selection\033[0m");
		ft_putstr_fd(p, isatty(1));
		free(p);
		return (0);
	}
	if (col == pos)
		ft_cmdput("us");
	ft_putstr_fd(str, isatty(1));
	ft_cmdput("ue");
	if ((num = ft_cursor(str, argc, 1)) > 0)
		ft_putchar_loop_fd(' ', isatty(1), num);
	return (1);
}
