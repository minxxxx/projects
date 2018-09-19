/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 14:59:59 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/09/11 15:00:03 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

DIR		*open_dir(char *path)
{
	DIR		*fd;

	if ((fd = opendir(path)) != NULL)
		return (fd);
	else
	{
		ft_putendl(DIR_ERROR1);
		return (NULL);
	}
}

void	read_dir(DIR *fd)
{
	struct dirent	*dir;

	if ((dir = readdir(fd)) != NULL)
		return ;
	else
		ft_putendl(DIR_ERROR2);
}

void	close_dir(DIR *fd)
{
	if (closedir(fd) < 0)
		ft_putendl(DIR_ERROR3);
}
