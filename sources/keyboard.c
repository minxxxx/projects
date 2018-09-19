/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:24:22 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/05 14:00:08 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	re_do(t_frac *s)
{
	mlx_destroy_image(s->mlx, s->image.img);
	mlx_clear_window(s->mlx, s->win);
	expose(s);
}

int				move(int keycode, t_frac *s)
{
	if (keycode == 123)
		s->move_x += 0.3;
	if (keycode == 126)
		s->move_y += 0.3;
	if (keycode == 124)
		s->move_x -= 0.3;
	if (keycode == 125)
		s->move_y -= 0.3;
	return (0);
}

int				keyboard(int keycode, t_frac *s)
{
	if (keycode >= 1 && keycode <= 126)
	{
		move(keycode, s);
		if (keycode == 53)
			exit(0);
		if (keycode == 8)
		{
			s->col.red += 50;
			s->col.blue += 50;
			s->col.green += 50;
		}
		if (keycode == 9)
		{
			s->col.red -= 40;
			s->col.blue -= 50;
			s->col.green -= 50;
		}
		re_do(s);
	}
	return (0);
}

int				mouse_hook(int x, int y, t_frac *s)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y <= HEIGHT)
	{
		s->cen.real = (((MAX - MIN) / ((double)(WIDTH) - 0.0))
				* ((double)(x) - 0.0)) + MIN;
		s->cen.imag = (((MAX - MIN) / ((double)(HEIGHT) - 0.0))
				* ((double)(y) - 0.0)) + MIN;
		re_do(s);
	}
	return (0);
}

int				mouse_zoom(int key, int x, int y, t_frac *s)
{
	(void)x;
	(void)y;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (key == 5 || key == 2)
			s->zoom += (s->zoom * 0.30);
		else if (key == 4 || key == 1)
			s->zoom -= (s->zoom * 0.30);
		re_do(s);
	}
	return (0);
}
