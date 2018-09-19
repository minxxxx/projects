/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:06:53 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:06:55 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <unistd.h>
# include "directory.h"
# include "file.h"
# include "env.h"

int				parse_params(t_env *env, int ac, char **av);
void			check4(t_env *env, char c);
void			parse_sources(t_env *env, int ac, char **av, int c);
void			print_directory(t_env *env, char *dir, int is_recur
		, char *display_path);
void			print_file(t_env *env, t_file *file, t_directory *dir);
void			error_quit(char *error);
void			directory_add_file(t_env *env, t_directory *dir, char *name);
void			directory_init(t_directory *dir, char *path);
t_directory		*load_directory(t_env *env, char *path);
void			add_file(t_env *env, t_directory *dir, t_file_list *list);
void			free_file(t_env *env, struct s_file *file);
char			*load_file_driver(struct stat *info);
int				load_file_symb(t_env *env, t_file *file, struct stat *info
		, char *rpath);
void			load_file(t_env *env, t_file *file, char *name
		, t_directory *dir);
char			*load_file_perms(struct stat *info);
char			*load_file_date(t_env *env, struct stat *info);
void			load_file_type(t_file *file, struct stat *info, int is_lnk);
time_t			file_time(t_env *env, struct stat *info);
void			parse_source_push(t_env *env, t_source *source);
void			parse_sources_empty(char **av, int c);
char			*load_file_loul(char *name, t_directory *dir);
void			load_file_setinfos(t_env *env, t_file *file, struct stat *info);

#endif
