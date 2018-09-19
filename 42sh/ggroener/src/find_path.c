/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:19:37 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 08:57:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		scan_dir(char *s, char *path)
{
	DIR				*dir;
	struct dirent	*file;

	dir = opendir(path);
	file = NULL;
	while ((file = readdir(dir)) != NULL)
	{
		if (ft_strcmp(file->d_name, s) == 0)
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

char	*add_path(char *path, char *extension)
{
	char	*temp;
	char	*result;

	temp = NULL;
	result = NULL;
	temp = ft_strjoin(path, "/");
	result = ft_strjoin(temp, extension);
	free(temp);
	return (result);
}

char	*find_path(t_env *env, char *s)
{
	int				k;
	int				l;
	char			*p;
	char			**str;

	k = 0;
	l = -1;
	if (s == NULL)
		return (NULL);
	while (E_EN[k] != NULL)
	{
		if (ft_strstr(E_EN[k], "PATH=") != NULL)
		{
			p = ft_strchr(E_EN[k], '=');
			p++;
			str = ft_strsplit(p, ':');
			while (str[++l] != NULL)
				if (scan_dir(s, str[l]))
					return (add_path(str[l], s));
		}
		k++;
	}
	return (NULL);
}
