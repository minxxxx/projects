/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:16:46 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:16:48 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	file_time(t_env *env, struct stat *info)
{
	if (env->u)
		return (info->st_atimespec.tv_sec);
	else if (env->u_caps)
		return (info->st_birthtimespec.tv_sec);
	else if (env->c)
		return (info->st_ctimespec.tv_sec);
	return (info->st_mtimespec.tv_sec);
}
