/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:09:14 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/05 13:31:17 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_colours(t_frac *s)
{
	s->col.red = 120;
	s->col.green = 125;
	s->col.blue = 225;
	return (0);
}

int		init_mandelbrot(t_frac *s)
{
	s->zoom = 1;
	s->move_x = 0;
	s->move_y = 0;
	s->max_iterations = 300;
	return (0);
}

int		init_vals(t_frac *s)
{
	s->neww.real = 0;
	s->neww.imag = 0;
	s->old.real = 0;
	s->old.imag = 0;
	return (0);
}

int		init_julia(t_frac *s)
{
	s->zoom = 1;
	s->move_x = -0.5;
	s->move_y = 0;
	s->max_iterations = 300;
	s->cen.real = -0.7;
	s->cen.imag = 0.27015;
	return (0);
}

int		init_extras(t_frac *s)
{
	s->pos.real = (s->x - WIDTH / 2) /
		(0.5 * s->zoom * WIDTH / 2) + s->move_y;
	s->pos.imag = (s->y - HEIGHT / 2) /
		(0.5 * s->zoom * HEIGHT / 2) + s->move_y;
	s->z_r = 0;
	s->z_im = 0;
	return (0);
}
