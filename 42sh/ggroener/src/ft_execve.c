/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:27:22 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 13:27:24 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		check_tild(char **argv, t_data *data)
{
	char		*tild;
	int			i;

	i = 0;
	while (argv[i])
		i++;
	--i;
	if (argv[i] && argv[i][0] == '~')
	{
		tild = ft_strjoin(data->home, argv[i] + 1);
		argv[i] = tild;
	}
}

static void		lunch_cmd(char *cmd, char **argv, t_data *data)
{
	int		i;
	char	**paths;
	char	*tmp;
	int		ret;

	check_tild(argv, data);
	i = -1;
	tmp = NULL;
	paths = NULL;
	paths = ft_get_path(data);
	while (paths[++i] != '\0')
	{
		tmp = ft_strjoin(paths[i], cmd);
		ret = execve(tmp, argv, data->env);
		FREE_(tmp);
		if (ret > -1)
			exit(0);
	}
	ret = execve(cmd, argv, data->env);
	if (ret == -1)
		ft_putstr(E_MESS03);
	exit(0);
}

int				ft_execve(char *cmd, char **argv, t_data *data)
{
	pid_t	fork_return;
	int		ret;

	ret = 1;
	fork_return = fork();
	if (fork_return == 0)
		lunch_cmd(cmd, argv, data);
	else
		waitpid(fork_return, &ret, WUNTRACED);
	return (ret);
}
