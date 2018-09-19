/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:18:12 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/23 13:54:06 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env	*env;
	char	*map_name;

	if (ac != 1 && ac != 2)
		error_quit("./wolf3d map_name");
	if (ac == 1)
		map_name = "maps/map3";
	else
		map_name = av[1];
	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env struct");
	env_init(env);
	map_load(env->map, map_name);
	place_player(env);
	window_init(env);
	mlx_do_key_autorepeatoff(env->window->mlx);
	mlx_hook(env->window->mlx_window, 2, 1, &key_press_listener, env);
	mlx_hook(env->window->mlx_window, 3, 2, &key_release_listener, env);
	mlx_hook(env->window->mlx_window, 17, 0L, free_all, env);
	mlx_loop_hook(env->window->mlx, loop_listener, env);
	mlx_loop(env->window->mlx);
}
