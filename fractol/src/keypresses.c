/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypresses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 08:46:05 by jbuys             #+#    #+#             */
/*   Updated: 2016/10/05 13:10:23 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		keycode_press(int keypress, t_mlx *env)
{
	if (keypress == SPACE)
	{
		env->values.move_x = 0;
		env->values.move_y = 0;
		env->values.zoom = 1;
		mlx_destroy_image(env->mlx, env->img);
		redraw(env);
	}
	if (keypress == PLUS)
	{
		if (env->values.check == 0)
			env->values.check = 1;
		else
			env->values.check = 0;
	}
	return (0);
}

int		keycode_release(int keyrelease, t_mlx *env)
{
	if (keyrelease == ESCAPE)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

int		quit_program(void)
{
	exit(0);
}

int		mouse_scroll(int mouseevent, int x, int y, t_mlx *env)
{
	if (mouseevent == MWHEEL_UP)
	{
		env->values.zoom *= 1.2;
		env->values.move_x += 0.625 * ((x - (WIN_W / 2)) /
				(WIN_W * env->values.zoom));
		env->values.move_y += 0.625 * ((y - (WIN_H / 2)) /
				(WIN_H * env->values.zoom));
		mlx_destroy_image(env->mlx, env->img);
		redraw(env);
	}
	if (mouseevent == MWHEEL_DOWN && env->values.zoom > 0)
	{
		env->values.zoom /= 1.2;
		env->values.move_x -= 0.625 * ((x - (WIN_W / 2)) /
				(WIN_W * env->values.zoom));
		env->values.move_y -= 0.625 * ((y - (WIN_H / 2)) /
				(WIN_H * env->values.zoom));
		mlx_destroy_image(env->mlx, env->img);
		redraw(env);
	}
	return (0);
}

int		mouse_movement(int x, int y, t_mlx *env)
{
	if (strcmp(*env->values.av, "Julia") == 0 && env->values.check == 1)
	{
		env->values.julia_x = ((double)x / (double)WIN_W) / 7;
		env->values.julia_y = ((double)y / (double)WIN_H) / 7;
		mlx_destroy_image(env->mlx, env->img);
		redraw(env);
	}
	return (0);
}
