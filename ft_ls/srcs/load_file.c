/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:18:12 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:18:15 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_other_infos(t_env *env, t_file *pfile, struct stat *sinfo)
{
	pfile->inode = sinfo->st_ino;
	pfile->sort_size = sinfo->st_size;
	pfile->sort_date = file_time(env, sinfo);
}

static void		init_file(t_file *pfile, char *name)
{
	pfile->name = ft_strdup(name);
	pfile->lnk_name = NULL;
}

void			load_file(t_env *env, t_file *pfile, char *fname
		, t_directory *fdir)
{
	struct stat		linfo;
	struct stat		ninfo;
	char			*loul;
	int				is_lnk;

	init_file(pfile, fname);
	loul = load_file_loul(fname, fdir);
	if (stat(loul, &ninfo) == -1)
		error_quit("Failed to read stats");
	is_lnk = (lstat(loul, &linfo) == 0) && (ninfo.st_ino != linfo.st_ino);
	pfile->is_dir = S_ISDIR(ninfo.st_mode)
		&& (!env->l || S_ISDIR(linfo.st_mode));
	load_file_type(pfile, &ninfo, is_lnk);
	set_other_infos(env, pfile, &ninfo);
	if (!env->p_caps && is_lnk)
	{
		fdir->total_links += load_file_symb(env, pfile, &linfo, loul);
		free(loul);
		return ;
	}
	if (env->l)
		load_file_setinfos(env, pfile, &ninfo);
	if (env->l)
		fdir->total_links += ninfo.st_blocks;
	free(loul);
}
