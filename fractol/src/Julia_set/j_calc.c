/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:33:02 by jbuys             #+#    #+#             */
/*   Updated: 2016/10/05 13:17:58 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_mlx		j_color_change(t_mlx *env)
{
	env->values.color_iter = find_julia(env);
	env->data[(env->values.x * 4) + ((int)env->values.y * env->size_line)
		+ 1] = env->values.color_iter & 0x7F;
	env->data[(env->values.x * 4) + ((int)env->values.y * env->size_line)] =
		env->values.color_iter & 0x6F;
	env->data[(env->values.x * 4) + ((int)env->values.y * env->size_line)
		+ 2] = env->values.color_iter & 0x5F;
	return (*env);
}

double		j_map_to_real(int x, t_mlx *env)
{
	double		one;
	double		two;

	one = x - WIN_W / 2;
	two = env->values.zoom * WIN_W;
	return (1.5 * one / two + env->values.move_x);
}

double		j_map_to_imaginary(int y, t_mlx *env)
{
	double		one;
	double		two;

	one = y - WIN_H / 2;
	two = env->values.zoom * WIN_H;
	return (one / two + env->values.move_y);
}

int			find_julia(t_mlx *env)
{
	int			i;
	double		or;
	double		oi;

	i = 0;
	or = 0;
	oi = 0;
	while (i < env->values.max_iter && or * or + oi * oi < 4.0)
	{
		or = env->values.nr;
		oi = env->values.ni;
		env->values.nr = (or * or - oi * oi + env->values.cr) -
			env->values.julia_x;
		env->values.ni = (2.0 * or * oi + env->values.ci) - env->values.julia_y;
		i++;
	}
	return (i);
}

void		julia_calc(t_mlx *env)
{
	while (env->values.y < WIN_H)
	{
		env->values.x = 0;
		while (env->values.x < WIN_W)
		{
			env->values.nr = j_map_to_real(env->values.x, env);
			env->values.ni = j_map_to_imaginary(env->values.y, env);
			j_color_change(env);
			env->values.x++;
		}
		env->values.y++;
	}
}
