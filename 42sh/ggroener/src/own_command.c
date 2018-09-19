/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:25:31 by khansman          #+#    #+#             */
/*   Updated: 2016/09/06 12:51:39 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_own(char *s)
{
	if (ft_memcmp(s, "env", 3) == 0)
		return (1);
	if (ft_memcmp(s, "cd", 2) == 0)
		return (1);
	if (ft_memcmp(s, "setenv", 6) == 0)
		return (1);
	if (ft_memcmp(s, "unsetenv", 8) == 0)
		return (1);
	if (ft_memcmp(s, "echo", 4) == 0)
		return (1);
	if (ft_memcmp(s, "help", 4) == 0)
		return (1);
	if (ft_memcmp(s, "easter", 6) == 0)
		return (1);
	if (ft_memcmp(s, "history", 7) == 0)
		return (1);
	return (0);
}

void	own_command(t_env *env, char **sa, char *s)
{
	if (ft_memcmp(sa[0], "echo", 4) == 0)
		ft_echo(sa);
	else if (ft_memcmp(sa[0], "cd", 2) == 0)
		ft_cd(env, sa);
	else if (ft_memcmp(sa[0], "setenv", 6) == 0)
		ft_setenv(env, sa);
	else if (ft_memcmp(sa[0], "unsetenv", 8) == 0)
		ft_unsetenv(env, sa);
	else if (ft_memcmp(sa[0], "env", 3) == 0)
		call_env(*env, s);
	else if (ft_memcmp(sa[0], "help", 4) == 0)
		ft_help(env, sa);
	else if (ft_memcmp(sa[0], "easter", 6) == 0)
		easteregg(env, sa);
	else if (ft_memcmp(sa[0], "history", 7) == 0)
		list_history(env, sa);
	else
		ft_putstr(E_MESS05);
	FREE_(s);
}
