/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:45:46 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 14:40:59 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"
# include "reader.h"

void	free_env(t_env *env);
void	reader(t_env *env);
void	print_file(t_env *env);
int		read_room(t_env *env, t_reader *p, char **split);
int		read_link(t_env *env, t_reader *p, char **split);
void	error_quit(char *str);
void	place_points(t_env *env, t_room *room, int point);
void	print_moves(t_env *env);
int		valid_int(char *line);
void	add_file_line(t_env *env, char *line);
t_room	*create_room(void);
int		del_room_list(t_room *room);
int		del_link_list(t_room_list *link);

#endif
