/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:32:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/04 14:32:28 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_rot(int keycode, t_mapinfo *map)
{
	if (keycode == L_Q)
		map->rot_y += ANGL;
	if (keycode == L_E)
		map->rot_y -= ANGL;
	if (keycode == L_W)
		map->rot_x += ANGL;
	if (keycode == L_S)
		map->rot_x -= ANGL;
	if (keycode == L_D)
		map->rot_z += ANGL;
	if (keycode == L_A)
		map->rot_z -= ANGL;
}

static void	key_scale(int keycode, t_mapinfo *map)
{
	if (keycode == K_LEFT)
		map->scale_x -= 1;
	if (keycode == K_RIGHT)
		map->scale_x += 1;
	if (keycode == K_UP)
		map->scale_y += 1;
	if (keycode == K_DOWN)
		map->scale_y -= 1;
}

static void	key_reset(t_mapinfo *map)
{
	map->rot_x = INIT_X;
	map->rot_y = INIT_Y;
	map->rot_z = INIT_Z;
	map->scale_x = map->ori_x;
	map->scale_y = map->ori_y;
}

int			key_hook(int keycode, t_mapinfo *map)
{
	t_mapinfo mapcpy;

	if (keycode == ESC)
		exit(0);
	else if (keycode == L_R)
		key_reset(map);
	else if (keycode >= L_A && keycode <= L_E)
		key_rot(keycode, map);
	else if (keycode >= K_LEFT && keycode <= K_UP)
		key_scale(keycode, map);
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	mlx_clear_window(0, map->win);
	scale_points(&mapcpy, mapcpy.scale_x, mapcpy.scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
	free_map(mapcpy);
	if (keycode == 15 || keycode == 34)
		ft_draw_instruct(*map);
	return (0);
}
