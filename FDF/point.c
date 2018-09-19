/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:33:38 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/04 14:33:41 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		new_point(int x, int y, int z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	if (new.y > 0)
		new.col = 1;
	else
		new.col = 0;
	return (new);
}

void		translate_point(int x, int y, int z, t_mapinfo *map)
{
	int			i;
	int			k;

	i = 0;
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x += x;
			map->points[i][k].z += z;
			map->points[i][k].y += y;
			k++;
		}
		i++;
	}
}

void		scale_points(t_mapinfo *map, int scale_x, int scale_y)
{
	int			i;
	int			k;
	static int	z_old;
	static int	z_shift;

	i = 0;
	if (scale_y - z_old != 0 && z_old != 0)
		z_shift = z_shift + (scale_y - z_old);
	while (i < map->lines)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x *= scale_x;
			map->points[i][k].y *= scale_x + (z_shift * scale_x / 7);
			map->points[i][k].z *= scale_x;
			k++;
		}
		i++;
	}
	z_old = scale_y;
}
