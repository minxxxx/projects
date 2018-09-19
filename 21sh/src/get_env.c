/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:24:08 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:32:56 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		if (!(env[i] = (char *)malloc(sizeof(char) * ft_strlen(environ[i]))))
		{
			ft_putstr(E_MESS04);
			exit(0);
		}
		env[i] = environ[i];
		i++;
	}
	env[i++] = add_own();
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
