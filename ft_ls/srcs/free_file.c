/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:17:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:17:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_file(t_env *env, struct s_file *file)
{
	if (file)
	{
		if (env->l)
		{
			free(file->perms);
			free(file->links);
			free(file->user);
			free(file->group);
			free(file->size);
			free(file->date);
		}
		free(file->lnk_name);
		free(file->name);
		free(file);
	}
}
