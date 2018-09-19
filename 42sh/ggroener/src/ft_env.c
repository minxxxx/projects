/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 15:17:46 by ehansman          #+#    #+#             */
/*   Updated: 2016/09/11 11:14:02 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(char **sa)
{
	int		i;

	i = 0;
	while (sa[i])
	{
		ft_putstr(sa[i++]);
		ft_putchar('\n');
	}
}

void	call_env(t_env env, char *s)
{
	int		k;
	char	**sa;
	pid_t	forked;

	k = 1;
	if (ft_strchr(s, ' ') == NULL)
	{
		ft_env(env.environ);
		return ;
	}
	forked = fork();
	if (forked == 0)
	{
		sa = ft_strsplit(s, ' ');
		if (sa[k] != NULL)
		{
			ft_setenv(&env, sa);
			k++;
		}
		free2d(sa);
		ft_env(env.environ);
		exit(0);
	}
	else
		wait(0);
}

char	*find_var_val(t_env *env, const char *var)
{
	char	*seeked;
	int		k;

	k = 0;
	if (var == NULL)
		return (NULL);
	seeked = NULL;
	while (E_EN[k] != NULL)
	{
		if (ft_strstr(E_EN[k], var) != NULL)
		{
			seeked = ft_strchr(E_EN[k], '=');
			seeked++;
			return (seeked);
		}
		k++;
	}
	return (NULL);
}

void	update_env(t_env *env, char *var, char *n)
{
	char	*temp;
	int		k;

	k = 0;
	while (E_EN[k] != NULL)
	{
		if (ft_strncmp(E_EN[k], var, ft_strlen(var)) == 0)
		{
			temp = ft_strjoin(var, "=");
			E_EN[k] = ft_strjoin(temp, n);
			free(temp);
		}
		k++;
	}
}
