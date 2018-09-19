/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:34:01 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/04 14:34:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float angle, t_mapinfo *map)
{
	float	y1;
	float	z1;
	int		u;
	int		v;

	angle = angle * (M_PI / 180);
	v = 0;
	while (v < map->lines)
	{
		u = 0;
		while (u < map->width)
		{
			z1 = MAP_POINT.z * cos(angle) - MAP_POINT.y * sin(angle);
			y1 = MAP_POINT.y * cos(angle) + MAP_POINT.z * sin(angle);
			MAP_POINT.y = y1;
			MAP_POINT.z = z1;
			u++;
		}
		v++;
	}
}

void	rotate_y(float angle, t_mapinfo *map)
{
	float	x1;
	float	z1;
	int		u;
	int		v;

	v = 0;
	angle = angle * (M_PI / 180);
	while (v < map->lines)
	{
		u = 0;
		while (u < map->width)
		{
			x1 = MAP_POINT.z * cos(angle) + MAP_POINT.x * sin(angle);
			z1 = MAP_POINT.x * cos(angle) - MAP_POINT.z * sin(angle);
			MAP_POINT.x = x1;
			MAP_POINT.z = z1;
			u++;
		}
		v++;
	}
}

void	rotate_z(float angle, t_mapinfo *map)
{
	float	x1;
	float	y1;
	int		u;
	int		v;

	v = 0;
	angle = angle * (M_PI / 180);
	while (v < map->lines)
	{
		u = 0;
		while (u < map->width)
		{
			x1 = MAP_POINT.y * cos(angle) - MAP_POINT.x * sin(angle);
			y1 = MAP_POINT.y * sin(angle) + MAP_POINT.x * cos(angle);
			MAP_POINT.x = x1;
			MAP_POINT.y = y1;
			u++;
		}
		v++;
	}
}
