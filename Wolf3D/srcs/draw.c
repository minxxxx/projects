/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:10:46 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 09:10:49 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_ray_data_directions(t_ray_data *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->ray_pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - d->ray_pos_x) * d->delta_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->ray_pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - d->ray_pos_y) * d->delta_dist_y;
	}
}

void	init_ray_data(t_env *env, int x, t_ray_data *d)
{
	d->camera_x = 2. * x / env->window->width - 1;
	d->ray_pos_x = env->position->x;
	d->ray_pos_y = env->position->y;
	d->ray_dir_x = env->direction->x + env->plane_x * d->camera_x;
	d->ray_dir_y = env->direction->y + env->plane_y * d->camera_x;
	d->map_x = (int)d->ray_pos_x;
	d->map_y = (int)d->ray_pos_y;
	d->delta_dist_x = sqrt(1 + pow(d->ray_dir_y, 2) / pow(d->ray_dir_x, 2));
	d->delta_dist_y = sqrt(1 + pow(d->ray_dir_x, 2) / pow(d->ray_dir_y, 2));
	d->hit = 0;
	d->side = 0;
	init_ray_data_directions(d);
}

void	ray_loop(t_env *env, t_ray_data *d)
{
	while (!d->hit)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			d->side = d->step_x < 0 ? 0 : 1;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = d->step_y < 0 ? 2 : 3;
		}
		if (d->map_x < 0 || d->map_x >= env->map->width || d->map_y < 0
				|| d->map_y >= env->map->height
				|| env->map->data[d->map_y][d->map_x] == '#')
			d->hit = 1;
	}
}

t_ray	get_ray(t_env *env, int x)
{
	t_ray_data	d;

	init_ray_data(env, x, &d);
	ray_loop(env, &d);
	if (d.side == 0 || d.side == 1)
		d.perp_wall_dist = fabs((d.map_x - d.ray_pos_x + (1 - d.step_x) / 2)
				/ d.ray_dir_x);
	else
		d.perp_wall_dist = fabs((d.map_y - d.ray_pos_y + (1 - d.step_y) / 2)
				/ d.ray_dir_y);
	d.ray.length = abs((int)(env->window->height / d.perp_wall_dist));
	if (d.ray.length > env->window->height)
		d.ray.length = env->window->height;
	if (d.ray.length < 0)
		d.ray.length = 0;
	if (d.side == 0)
		d.ray.colour = EAST;
	else if (d.side == 1)
		d.ray.colour = WEST;
	else if (d.side == 2)
		d.ray.colour = NORTH;
	else
		d.ray.colour = SOUTH;
	return (d.ray);
}

void	draw(t_env *env)
{
	t_ray	ray;
	int		x;
	int		y;

	x = 0;
	while (x < env->window->width)
	{
		ray = get_ray(env, x);
		y = 0;
		while (y < env->window->height / 2 - ray.length / 2)
			pixel_put(env, x, y++, CEIL);
		while (y <= env->window->height / 2 + ray.length / 2)
			pixel_put(env, x, y++, ray.colour);
		while (y < env->window->height)
			pixel_put(env, x, y++, FLOOR);
		x++;
	}
	mlx_put_image_to_window(env->window->mlx, env->window->mlx_window
			, env->window->img, 0, 0);
	put_fps(env);
}
