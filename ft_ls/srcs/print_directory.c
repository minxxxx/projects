/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:24:31 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:24:34 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_subdirs(t_env *env, t_directory *dir)
{
	t_file_list		*lst;
	t_file_list		*prv;
	char			*tmp;

	lst = dir->files;
	while (lst)
	{
		if (lst->file->is_dir)
		{
			if (ft_strcmp(lst->file->name, ".")
					&& ft_strcmp(lst->file->name, ".."))
			{
				tmp = ft_strjoin_free1(ft_strjoin(dir->path, "/")
						, lst->file->name);
				print_directory(env, tmp, 1, ft_strdup(tmp));
				free(tmp);
			}
		}
		free_file(env, lst->file);
		prv = lst;
		lst = lst->next;
		free(prv);
	}
}

static void			print_directory_part(int is_recur, char *path, t_env *env)
{
	if (is_recur)
	{
		if (env->printed_file)
			ft_putchar('\n');
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

static void			print_directory_part2(t_env *env, t_directory *dir)
{
	if (env->l && dir->files != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(dir->total_links);
		ft_putchar('\n');
	}
}

void				print_directory(t_env *env, char *path, int is_recur
		, char *display_path)
{
	t_directory			*dir;
	t_file_list			*lst;

	print_directory_part(is_recur, display_path, env);
	if ((dir = load_directory(env, path)))
	{
		print_directory_part2(env, dir);
		lst = dir->files;
		while (lst)
		{
			print_file(env, lst->file, dir);
			lst = lst->next;
		}
		env->printed_file = 1;
		if (env->r_caps)
			print_subdirs(env, dir);
		free(dir);
	}
	free(display_path);
}
