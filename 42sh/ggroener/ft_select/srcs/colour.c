/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:15:16 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:15:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_colour_x(char *str)
{
	struct stat		stats;

	if ((stat(str, &stats) > -1) && (!S_ISDIR(stats.st_mode) &&
		(stats.st_mode & S_IXUSR)))
		ft_putstr_fd("\033[31m", isatty(1));
}

void		ft_colour(char *str, int key, int k, int pos)
{
	char			*l;
	static int		status;

	if (key == GKEY_DOT)
		status = status ? 0 : 1;
	if (k == pos)
		return ;
	if (!status && str != NULL && !ft_strncmp(str, "/dev/", 4))
		ft_putstr_fd("\033[31m", isatty(1));
	else if (!status && str != NULL && (l = ft_strrchr(str, '.')) != NULL)
	{
		if (!ft_strcmp(l, ".o"))
			ft_putstr_fd("\033[35m", isatty(1));
		else if (!ft_strcmp(l, ".c"))
			ft_putstr_fd("\033[34m", isatty(1));
		else if (!ft_strcmp(l, ".cpp"))
			ft_putstr_fd("\033[32m", isatty(1));
		else if (!ft_strcmp(l, ".s"))
			ft_putstr_fd("\033[36m", isatty(1));
		else if (!ft_strcmp(l, ".cor"))
			ft_putstr_fd("\033[33m", isatty(1));
	}
	else if (!status && str != NULL && l == NULL)
		ft_colour_x(str);
}
