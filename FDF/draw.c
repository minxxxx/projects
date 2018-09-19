/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:30:43 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/04 14:30:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_map(t_mapinfo *map)
{
	t_mapinfo	mapcpy;

	map->rot_x = INIT_X;
	map->rot_y = INIT_Y;
	map->rot_z = INIT_Z;
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	scale_points(&mapcpy, map->scale_x, map->scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
	free_map(mapcpy);
}

void		ft_draw_map(t_mapinfo map)
{
	int			k;
	int			l;

	k = 0;
	while (k < map.lines)
	{
		l = 0;
		while (l < map.width)
		{
			if (k + 1 < map.lines)
				draw_line(map.points[k][l], map.points[k + 1][l], &map);
			if (l + 1 < map.width)
				draw_line(map.points[k][l], map.points[k][l + 1], &map);
			l++;
		}
		k++;
	}
}

void		ft_draw_instruct(t_mapinfo map)
{
	mlx_string_put(map.mlx, map.win, 5, 5, WHITE, INFO01);
	mlx_string_put(map.mlx, map.win, 5, 20, WHITE, INFO02);
	mlx_string_put(map.mlx, map.win, 5, 35, WHITE, INFO03);
	mlx_string_put(map.mlx, map.win, 5, 50, WHITE, INFO04);
	mlx_string_put(map.mlx, map.win, 5, 65, WHITE, INFO05);
}
