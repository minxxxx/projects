/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_perms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:19:56 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:19:58 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_char_0(struct stat *info)
{
	if (S_ISLNK(info->st_mode))
		return ('l');
	else if (S_ISSOCK(info->st_mode))
		return ('s');
	else if (S_IFDIR & info->st_mode)
		return ('d');
	else if (S_IFCHR & info->st_mode)
		return ('c');
	else if (S_IFBLK & info->st_mode)
		return ('b');
	else if (S_IFIFO & info->st_mode)
		return ('p');
	else
		return ('-');
}

static char	get_char_3(struct stat *info)
{
	if (info->st_mode & S_ISUID)
	{
		if (info->st_mode & S_IXUSR)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (info->st_mode & S_IXUSR)
			return ('x');
		else
			return ('-');
	}
}

static char	get_char_6(struct stat *info)
{
	if (info->st_mode & S_ISGID)
	{
		if (info->st_mode & S_IXGRP)
			return ('s');
		else
			return ('S');
	}
	else
	{
		if (info->st_mode & S_IXGRP)
			return ('x');
		else
			return ('-');
	}
}

static char	get_char_9(struct stat *info)
{
	if (info->st_mode & S_ISVTX)
	{
		if (info->st_mode & S_IXOTH)
			return ('t');
		else
			return ('T');
	}
	else
	{
		if (info->st_mode & S_IXOTH)
			return ('x');
		else
			return ('-');
	}
}

char		*load_file_perms(struct stat *info)
{
	char	*perms;

	if (!(perms = malloc(sizeof(*perms) * 12)))
		error_quit("Failed to malloc file perms");
	perms[0] = get_char_0(info);
	perms[1] = info->st_mode & S_IRUSR ? 'r' : '-';
	perms[2] = info->st_mode & S_IWUSR ? 'w' : '-';
	perms[3] = get_char_3(info);
	perms[4] = info->st_mode & S_IRGRP ? 'r' : '-';
	perms[5] = info->st_mode & S_IWGRP ? 'w' : '-';
	perms[6] = get_char_6(info);
	perms[7] = info->st_mode & S_IROTH ? 'r' : '-';
	perms[8] = info->st_mode & S_IWOTH ? 'w' : '-';
	perms[9] = get_char_9(info);
	perms[10] = ' ';
	perms[11] = '\0';
	return (perms);
}
