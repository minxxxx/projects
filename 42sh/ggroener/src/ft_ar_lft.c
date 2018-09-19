/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_lft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:37:09 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:37:11 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		do_dup(int fd, t_pipe **tmp, t_data *env)
{
	int		ret;
	int		save;

	save = dup(0);
	ret = 0;
	if ((ret = dup2(fd, 0)) == -1)
		return (ret);
	if ((*tmp)->rgt)
		ft_read_path((*tmp)->rgt, env, 1);
	else if ((*tmp)->lft)
		ft_read_path((*tmp)->lft, env, 1);
	if ((ret = dup2(save, 0)) == -1)
		return (ret);
	if ((ret = close(fd)) == -1)
		return (ret);
	return (0);
}

int				ft_ar_lft(t_pipe **tmp, t_data *env)
{
	int		fd;
	int		ret;

	fd = -1;
	ret = 0;
	if ((*tmp)->argv[1])
	{
		fd = open((*tmp)->argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr((*tmp)->argv[1]);
			ft_putstr(" No such file or directory\n");
			ret = -1;
		}
		else
		{
			if ((ret = do_dup(fd, tmp, env)) < 0)
				return (ret);
		}
	}
	if (ret < 0)
		return (ret);
	return (0);
}
