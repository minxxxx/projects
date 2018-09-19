/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:15:19 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 09:15:21 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		check_collision(t_env *env, double old_x, double old_y)
{
	if (env->position->x < 0 || env->position->x >= env->map->width)
	{
		env->position->x = old_x;
	}
	if (env->position->y < 0 || env->position->y >= env->map->height)
	{
		env->position->y = old_y;
	}
	if (env->map->data[(int)old_y][(int)env->position->x] == '#')
	{
		env->position->x = old_x;
	}
	if (env->map->data[(int)env->position->y][(int)old_x] == '#')
	{
		env->position->y = old_y;
	}
}

void			move_forward(t_env *env)
{
	double	old_x;
	double	old_y;

	old_x = env->position->x;
	old_y = env->position->y;
	env->position->x += env->direction->x / 10.;
	env->position->y += env->direction->y / 10.;
	check_collision(env, old_x, old_y);
}

void			move_backward(t_env *env)
{
	double	old_x;
	double	old_y;

	old_x = env->position->x;
	old_y = env->position->y;
	env->position->x -= env->direction->x / 10.;
	env->position->y -= env->direction->y / 10.;
	check_collision(env, old_x, old_y);
}
