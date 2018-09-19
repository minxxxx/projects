/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:46:56 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 15:47:00 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	while ((dirp = readdir(fd)) != NULL)
**	in if statement at start
*/

void	auto_complete(void)
{
	DIR				*fd;
	struct dirent	*dirp;

	fd = open_dir("./");
	if (fd != NULL)
	{
		dirp = readdir(fd);
		puts(dirp->d_name);
		close_dir(fd);
	}
}
