/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:03:33 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/23 13:56:35 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"

void	draw(t_env *env);
void	env_init(t_env *env);
void	error_quit(char *error_message);
int		key_press_listener(int key, void *data);
int		key_release_listener(int key, void *data);
int		loop_listener(void *data);
void	map_init(t_env *env);
void	move_forward(t_env *env);
void	move_backward(t_env *env);
void	pixel_put(t_env *env, int x, int y, unsigned int colour);
void	window_init(t_env *env);
void	map_load(t_map *map, char *file);
int		file_length(char *file);
char	*get_file_content(char *file);
void	place_player(t_env *env);
long	time_elapse(void);
void	put_fps(t_env *env);

void	free_data(t_env *env);
int		free_all(void *data);

#endif
