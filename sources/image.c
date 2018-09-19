/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:24:15 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/05 13:29:45 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	screen_loop(t_frac *s)
{
	s->y = 0;
	while (s->y < HEIGHT)
	{
		s->x = 0;
		while (s->x < WIDTH)
		{
			if (ft_strequ("mandelbrot", s->fractal))
				ft_mandelbrot(s);
			else if (ft_strequ("julia", s->fractal))
				ft_julia(s);
			else if (ft_strequ("burningship", s->fractal))
				ft_burning_ship(s);
			else if (ft_strequ("tricorn", s->fractal))
				ft_tricorn(s);
			else if (ft_strequ("batman", s->fractal))
				ft_batman(s);
			else if (ft_strequ("flower", s->fractal))
				ft_flower(s);
			s->x++;
		}
		s->y++;
	}
}

void	pixel(t_frac *s, int x, int y)
{
	s->image.d[y * s->image.s + x *
		s->image.bpp / 8 + 0] = mlx_get_color_value(s->mlx, s->color.r);
	s->image.d[y * s->image.s + x *
		s->image.bpp / 8 + 1] = mlx_get_color_value(s->mlx, s->color.g);
	s->image.d[y * s->image.s + x *
		s->image.bpp / 8 + 2] = mlx_get_color_value(s->mlx, s->color.b);
}

void	set_colours(t_frac *s, int r, int g, int b)
{
	s->color.r = r;
	s->color.g = g;
	s->color.b = b;
}

void	ft_burning_ship(t_frac *s)
{
	int i;

	i = 0;
	init_extras(s);
	s->z_im = 0;
	while (s->z_r * s->z_r + s->z_im * s->z_im < 4 && i < s->max_iterations)
	{
		s->tmp = s->z_r;
		s->z_r = s->z_r * s->z_r - s->z_im * s->z_im - s->pos.real;
		s->z_im = 2 * fabs(s->tmp) * fabs(s->z_im) + s->pos.imag;
		set_colours(s, i * s->col.red, s->col.green * i * i / 3,
				s->col.blue * (i < s->max_iterations));
		pixel(s, s->x, s->y);
		++i;
	}
}
