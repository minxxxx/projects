/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:24:35 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/05 14:07:28 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <math.h>

# define HEIGHT 600
# define WIDTH 600
# define ABS(x) (x < 0 ? -x : x)
# define MIN -3.20
# define MAX 3.200
# define ERR_MSG_P1 "Usage: ./fractol [Fractal = mandelbrot || "
# define ERR_MSG_P2 "julia || burningship || tricorn || batman || flower]\n"

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_img
{
	void		*img;
	char		*d;
	int			bpp;
	int			s;
	int			e;
}				t_img;

typedef struct	s_values
{
	double		real;
	double		imag;
}				t_values;

typedef struct	s_frac
{
	int			x;
	int			y;
	double		zoom;
	double		move_y;
	double		move_x;
	double		tmp;
	double		z_r;
	double		z_im;
	int			max_iterations;
	t_rgb		color;
	t_color		col;
	t_img		image;
	t_values	cen;
	t_values	pos;
	t_values	neww;
	t_values	old;
	t_values	start;
	t_values	step;
	char		*fractal;
	void		*mlx;
	void		*win;
}				t_frac;

int				move(int keycode, t_frac *s);
void			screen_loop(t_frac *s);
void			ft_error(char *s);
int				key_exit(int keycode, t_frac *s);
int				keyboard(int keycode, t_frac *s);
int				init_mandelbrot(t_frac *s);
int				init_vals(t_frac *s);
void			ft_mandelbrot(t_frac *s);
void			ft_burning_ship(t_frac *s);
void			ft_tricorn(t_frac *s);
void			ft_julia(t_frac *s);
void			ft_batman(t_frac *s);
void			ft_flower(t_frac *s);
int				init_julia(t_frac *s);
int				init_colours(t_frac *s);
int				init_extras(t_frac *s);
void			pixel(t_frac *s, int x, int y);
void			set_colours(t_frac *s, int r, int g, int b);
int				expose(t_frac *s);
int				mouse_zoom(int key, int x, int y, t_frac *s);
int				mouse_hook(int x, int y, t_frac *s);

#endif
