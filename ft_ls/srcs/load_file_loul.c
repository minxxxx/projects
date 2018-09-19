/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_loul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:19:36 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:19:38 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*load_file_loul(char *name, t_directory *dir)
{
	char	*tmp;

	if (name[0] == '/')
		return (ft_strdup(name));
	if (!(tmp = ft_strjoin(dir->path, "/")))
		error_quit("Failed to malloc string");
	if (!(tmp = ft_strjoin_free1(tmp, name)))
		error_quit("Failed to malloc string");
	return (tmp);
}
