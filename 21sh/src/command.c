/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:18:14 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 15:20:06 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		do_command(t_env *env, char *com)
{
	char	*str;
	char	**arr;
	pid_t	forked;
	t_env	*pid;

	str = NULL;
	arr = NULL;
	forked = fork();
	env->pid = forked;
	if (forked == 0)
	{
		arr = ft_strsplit(com, ' ');
		execve(com, arr, E_EN);
		str = find_path(env, arr[0]);
		if (str == NULL)
			ft_putstr(E_MESS02);
		else
			execve(str, arr, E_EN);
		exit(0);
	}
	else
		wait(0);
	return (1);
}

void	com_sep(t_env *env, char *s)
{
	char	**sa;
	int		k;

	if (s == NULL)
		return ;
	sa = NULL;
	rm_tabs(&s);
	k = 0;
	if (!ft_strchr(s, ';'))
		command(env, s);
	else
	{
		sa = ft_strsplit(s, ';');
		while (sa && sa[k] && *sa[k])
		{
			command(env, sa[k]);
			k++;
		}
		free2d(sa);
	}
}

void	command(t_env *env, char *s)
{
	char	**sa;

	if (s == NULL)
		return ;
	sa = NULL;
	rm_tabs(&s);
	sa = ft_strsplit(s, ' ');
	if (arg_valid(sa, count(s, ' ')))
	{
		if (is_own(sa[0]))
			own_command(env, sa, s);
		else
			do_command(env, s);
	}
	else
		error(1);
	free2d(sa);
}
