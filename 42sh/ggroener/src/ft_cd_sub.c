/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:23:47 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 15:23:55 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		scan_slash(char *str)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '\\')
			l++;
		k++;
	}
	return (l);
}

void	cd_home(t_env *env)
{
	char	*home;

	home = find_var_val(env, "HOME=");
	chdir(home);
	update_env(env, "PWD", home);
}

char	*clip_path(char *path, int count)
{
	int		i;
	int		j;
	char	*new_path;

	(void)count;
	i = 0;
	j = 0;
	new_path = (char *)malloc(sizeof(char *) * ft_strlen(path));
	while (path[i] != '\0')
		i++;
	while (path[i] != '/')
		i--;
	while (j < i)
	{
		new_path[j] = path[j];
		j++;
	}
	new_path[j] = '\0';
	return (new_path);
}

void	cd_one(t_env *env, char *dir, int count)
{
	char	*path;

	path = NULL;
	path = find_var_val(env, "PWD=");
	update_env(env, "OLDPWD", path);
	if (ft_strcmp(dir, "..") == 0)
	{
		path = clip_path(path, count);
		if (chdir(path) == 0)
			update_env(env, "PWD", path);
		else
			ft_putstr(E_MESS12);
		free(path);
	}
	else if (scan_dir(dir, path) == 1)
	{
		path = add_path(path, dir);
		if (chdir(path) == 0)
			update_env(env, "PWD", path);
		else
			ft_putstr(E_MESS12);
		free(path);
	}
	else
		ft_putstr(E_MESS01);
}

t_env	*ft_cd_sub(t_env *env, char *sa, int count)
{
	if (sa == NULL)
		return (env);
	if (ft_strcmp(sa, "~") == 0)
		cd_home(env);
	else if (ft_strcmp(sa, "-") == 0)
		cd_prev(env);
	else if (ft_strcmp(sa, ".") == 0)
		return (env);
	else if (scan_slash(sa) == 0)
		cd_one(env, sa, count);
	else
		ft_putstr(E_MESS02);
	return (env);
}
