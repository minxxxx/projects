/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:23:20 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:23:22 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir(t_env *env, t_directory *dir)
{
	t_file_list		*lst;
	t_file_list		*prv;

	lst = dir->files;
	while (lst)
	{
		print_file(env, lst->file, dir);
		free_file(env, lst->file);
		prv = lst;
		lst = lst->next;
		free(prv);
	}
}

static void		print_sources(t_env *env, int recur)
{
	t_source		*lst;

	lst = env->sources;
	while (lst)
	{
		print_directory(env, lst->path, recur, lst->display_path);
		lst = lst->next;
	}
}

static void		push_source(t_env *env, char *path, char *display_path
		, struct stat *info)
{
	t_source		*new;

	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed");
	new->display_path = display_path;
	new->path = path;
	new->sort_date = file_time(env, info);
	new->next = NULL;
	parse_source_push(env, new);
}

static int		add_source(t_env *env, char *path, t_directory *dir
		, char *display_path)
{
	struct stat		info;
	struct stat		linfo;

	if (stat(path, &info) == -1 & lstat(path, &linfo) == -1)
	{
		ft_putstr_fd("ls: ", 2);
		perror(path);
		return (0);
	}
	if (S_ISDIR(info.st_mode) && (!env->l || S_ISDIR(linfo.st_mode)))
	{
		push_source(env, path, display_path, &info);
		return (0);
	}
	directory_add_file(env, dir, path);
	return (1);
}

void			parse_sources(t_env *env, int ac, char **av, int c)
{
	t_directory		dir;
	char			*display_path;
	int				printed_file;
	int				printed;
	int				i;

	directory_init(&dir, ".");
	printed = 0;
	printed_file = 0;
	parse_sources_empty(av, c);
	i = c;
	while (av[i])
	{
		display_path = ft_strdup(av[i]);
		if (av[i][ft_strlen(av[i]) - 1] == '/' && ft_strlen(av[i]) > 1)
			av[i][ft_strlen(av[i]) - 1] = '\0';
		printed_file += add_source(env, av[i], &dir, display_path);
		printed = 1;
		i++;
	}
	print_dir(env, &dir);
	if (!printed)
		print_directory(env, ".", 0, ft_strdup("."));
	else
		print_sources(env, printed_file || ac - c >= 2);
}
