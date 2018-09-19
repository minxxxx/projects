/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:21:17 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:21:21 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	load_file_type(t_file *file, struct stat *info, int is_lnk)
{
	file->is_dir = S_ISDIR(info->st_mode);
	file->is_exe = (S_IXUSR & info->st_mode) || (S_IXGRP & info->st_mode)
		|| (S_IXOTH & info->st_mode);
	file->is_lnk = is_lnk;
	file->is_sock = S_ISSOCK(info->st_mode);
	file->is_whout = S_ISWHT(info->st_mode);
	file->is_fifo = S_ISFIFO(info->st_mode);
}
