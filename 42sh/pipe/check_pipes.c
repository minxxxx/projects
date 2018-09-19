/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:45:41 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 12:45:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char	**argv)
{
	t_env	*env;

	env = NULL;
	if (argc == 2)
	{
		pipe(env, argv[1]);
	}
}

int		ft_check_pipes(t_pipe **lst)
{
	t_pipe	*tmp;

	tmp = *lst;
	if (tmp->code == PIPE)
	{
		ft_putstr_fd("pipe error: pipe has no first argument\n", 2);
		return (0);
	}
	while (tmp)
	{
		if (tmp->code == PIPE)
		{
			if (!tmp->next)
			{
				ft_putstr_fd("pipe error: pipe has no second argument\n", 2);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
