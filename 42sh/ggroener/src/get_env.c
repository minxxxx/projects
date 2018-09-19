/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:24:08 by khansman          #+#    #+#             */
/*   Updated: 2016/08/22 11:26:48 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**		No longer using this function
*/

char	*add_own(void)
{
	char	*s;

	s = (char *)malloc(sizeof(char) + 1);
	s[0] = '#';
	s[1] = '\0';
	return (s);
}

char	**get_env(char **environ)
{
	int		i;
	char	**env;

	i = 0;
	while (environ[i])
		i++;
	if (!(env = (char **)malloc(sizeof(char *) * (i + 100))))
	{
		ft_putstr(E_MESS04);
		exit(0);
	}
	i = 0;
	while (environ[i])
	{
		if (!(env[i] = ft_strdup(environ[i])))
		{
			ft_putstr(E_MESS04);
			exit(0);
		}
		i++;
	}
	env[i] = NULL;
	return (env);
}

int		get_envsize(char **env)
{
	int		k;

	k = 0;
	while (env[k] != NULL)
		k++;
	return (k);
}
