/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_setinfos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:20:27 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:20:29 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		load_file_setinfos(t_env *env, t_file *file, struct stat *info)
{
	struct passwd	*pw;
	struct group	*gr;

	if (env->n)
	{
		file->user = ft_itoa(info->st_uid);
		file->group = ft_itoa(info->st_gid);
	}
	else
	{
		pw = getpwuid(info->st_uid);
		gr = getgrgid(info->st_gid);
		file->user = ft_strdup(pw->pw_name ? pw->pw_name : "");
		file->group = ft_strdup(gr->gr_name ? gr->gr_name : "");
	}
	file->links = ft_itoa(info->st_nlink);
	file->perms = load_file_perms(info);
	if (file->perms[0] == 'c' || file->perms[0] == 'b')
		file->size = load_file_driver(info);
	else
		file->size = ft_itoa(info->st_size);
	file->date = load_file_date(env, info);
}
