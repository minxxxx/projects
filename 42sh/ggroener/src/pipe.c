/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 08:58:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 15:07:51 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		fork_father(int *fd, t_pipe **tmp, t_data *environ)
{
	if ((*tmp)->rgt->code == DB_AR_LEFT)
		ft_read_path((*tmp)->rgt, environ, 0);
	close(fd[0]);
	dup2(fd[1], 1);
	if ((*tmp)->rgt->code == DB_AR_LEFT)
		ft_read_db_lft(environ);
	else
		ft_read_path((*tmp)->rgt, environ, 0);
	exit(0);
}

static int		fork_child(int fork_ret2, int *fd, t_pipe **tmp, \
		t_data *environ)
{
	if ((fork_ret2 = fork()) == -1)
		return (-1);
	if (fork_ret2 == 0)
	{
		if ((*tmp)->lft->code == DB_AR_LEFT)
			ft_read_path((*tmp)->lft, environ, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		if ((*tmp)->lft->code == DB_AR_LEFT)
			ft_read_db_lft(environ);
		else
			ft_read_path((*tmp)->lft, environ, 0);
		exit(0);
	}
	return (0);
}

static void		end_function_pipe(int *fd, int fork_ret, \
		int fork_ret2, int ret)
{
	close(fd[1]);
	close(fd[0]);
	waitpid(fork_ret, &ret, WUNTRACED);
	waitpid(fork_ret2, &ret, WUNTRACED);
}

int				ft_pipe(t_pipe **tmp, t_data *environ)
{
	int		fd[2];
	int		fork_ret;
	int		fork_ret2;
	int		ret;

	ret = 0;
	fork_ret2 = 0;
	fork_ret = 0;
	if (pipe(fd) == -1)
	{
		ft_putstr("pipe fail");
		return (-1);
	}
	if ((fork_ret = fork()) == -1)
	{
		ft_putstr("fork fail");
		return (-1);
	}
	if (fork_ret == 0)
		fork_father(fd, tmp, environ);
	if (fork_ret != 0)
		fork_child(fork_ret2, fd, tmp, environ);
	end_function_pipe(fd, fork_ret, fork_ret2, ret);
	return (ret);
}
