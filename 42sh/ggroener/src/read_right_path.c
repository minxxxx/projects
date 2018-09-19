/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_right_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:44:06 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:44:08 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		do_dup(int fd, t_pipe **tmp, t_data *env)
{
	int		ret;
	int		save;

	save = dup(1);
	ret = 0;
	if ((ret = dup2(fd, 1)) == -1)
		return (ret);
	if ((*tmp)->rgt)
		ft_read_path((*tmp)->rgt, env, 1);
	else if ((*tmp)->lft)
		ft_read_path((*tmp)->lft, env, 1);
	if ((ret = dup2(save, 1)) == -1)
		return (ret);
	if ((ret = close(fd)) == -1)
		return (ret);
	return (0);
}

static int		check_arg(t_pipe **tmp, int i)
{
	ft_putstr((*tmp)->argv[i]);
	ft_putstr("no such files or directory\n");
	return (-1);
}

int				ft_db_ar_rgt(t_pipe **tmp, t_data *env)
{
	int		fd;
	int		ret;
	int		i;

	i = 1;
	ret = 0;
	fd = -1;
	if ((*tmp)->argv[1])
	{
		fd = open((*tmp)->argv[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			ret = -1;
	}
	while ((*tmp)->argv[++i])
		ret = check_arg(tmp, i);
	if (ret > -1)
	{
		if ((ret = do_dup(fd, tmp, env)) < 0)
			return (ret);
	}
	if (ret < 0)
		return (ret);
	return (0);
}
