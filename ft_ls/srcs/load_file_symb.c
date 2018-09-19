/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_symb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:20:49 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:20:51 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_other_infos(t_env *env, t_file *file, struct stat *info)
{
	file->inode = info->st_ino;
	file->sort_size = info->st_size;
	file->sort_date = file_time(env, info);
}

int				load_file_symb(t_env *env, t_file *file, struct stat *info
		, char *rpath)
{
	ssize_t			r;
	char			*linkname;

	if (!(linkname = malloc(info->st_size + 1)))
		error_quit("Failed to malloc linkname");
	r = readlink(rpath, linkname, info->st_size + 1);
	if (r < 0)
		error_quit("Bad link id, did it changed ?");
	linkname[info->st_size] = '\0';
	file->is_dir = S_ISDIR(info->st_mode);
	if (env->l)
	{
		file->lnk_name = linkname;
		load_file_setinfos(env, file, info);
	}
	set_other_infos(env, file, info);
	return (info->st_blocks);
}
