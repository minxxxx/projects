/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:17:29 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:17:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		directory_init(t_directory *dir, char *path)
{
	dir->files = NULL;
	dir->path = path;
	dir->total_links = 0;
	dir->links_len = 0;
	dir->user_len = 0;
	dir->group_len = 0;
	dir->size_len = 0;
	dir->date_len = 0;
}

t_directory	*load_directory(t_env *env, char *path)
{
	t_directory		*directory;
	DIR				*dir;
	struct dirent	*ep;

	if ((dir = opendir(path)))
	{
		if (!(directory = malloc(sizeof(*directory))))
			error_quit("Failed to malloc dir");
		directory_init(directory, path);
		while ((ep = readdir(dir)))
		{
			if (env->a || ep->d_name[0] != '.' || (env->a_caps
						&& ft_strcmp(ep->d_name, ".")
						&& ft_strcmp(ep->d_name, "..")))
				directory_add_file(env, directory, ep->d_name);
		}
		closedir(dir);
	}
	else
	{
		perror(ft_strjoin("ls: ", path));
		return (NULL);
	}
	return (directory);
}
