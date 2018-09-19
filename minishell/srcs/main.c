/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 12:35:20 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/10 13:30:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		doif(char **args)
{
	char	*eexit;
	char	*cd;
	char	*qit;

	qit = "closed\n";
	cd = "cd";
	eexit = "exit";
	if (ft_strcmp(args[0], cd) == 0)
	{
		if (!args[1])
			chdir("/nfs/zfs-student-6/users/ggroener");
		chdir(args[1]);
	}
	if (ft_strcmp(args[0], eexit) == 0)
	{
		ft_putstr("\e[31mexiting minishell\e[0m\n");
		ft_exit(qit, -1);
	}
}

int				main(void)
{
	char	*line;
	char	**args;
	char	*excute;
	int		signal;
	pid_t	father;

	while (1)
	{
		father = fork();
		if (father > 0)
		{
			wait(&signal);
			ft_putstr("\e[31m$>\e[0m");
			get_next_line(0, &line);
			args = ft_strsplit(line, ' ');
			doif(args);
		}
		if (father == 0)
		{
			excute = ft_strjoin("/bin/", args[0]);
			execve(excute, args, NULL);
			signal = 0;
		}
	}
	return (0);
}
