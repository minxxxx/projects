/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:44:36 by jbuys             #+#    #+#             */
/*   Updated: 2016/10/05 13:16:53 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <libc.h>
# include <math.h>
# include <mlx.h>

# define WIN_H 400
# define WIN_W 400

# define SPACE 49
# define ESCAPE 53
# define MWHEEL_UP 4
# define MWHEEL_DOWN 5
# define PLUS 69
# define EQUALS 24
# define STR1 "\n\033[1;33mSpacebar to reset position.\033[0m"
# define STR2 "\033[1;33mScroll mouse to zoom IN and OUT.\033[0m"
# define STR3 "\033[1;33mUse + to initialize Julia.\033[0m"

typedef struct	s_init
{
	int			max_n;
	double		cr;
	double		ci;
	double		nr;
	double		ni;
	double		move_x;
	double		move_y;
	double		zoom;
	char		**av;
	int			max_iter;
	int			x;
	int			y;
	int			color_iter;
	double		julia_x;
	double		julia_y;
	int			check;
}				t_init;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	double		x_original;
	char		*data;
	int			size_line;
	int			endian;
	t_init		values;
}				t_mlx;

void			init_all(char **av, t_mlx *env);
void			check_type(char **av, t_mlx *env);
void			redraw(t_mlx *env);

t_mlx			m_color_change(t_mlx *env);
void			mandelbrot_calc(t_mlx *env);
double			m_map_to_real(int x, t_mlx *env);
double			m_map_to_imaginary(int y, t_mlx *env);
int				find_mandelbrot(t_mlx *env);

t_mlx			j_color_change(t_mlx *env);
void			julia_calc(t_mlx *env);
double			j_map_to_real(int x, t_mlx *env);
double			j_map_to_imaginary(int y, t_mlx *env);
int				find_julia(t_mlx *env);

t_mlx			b_color_change(t_mlx *env);
double			b_map_to_real(int x, t_mlx *env);
double			b_map_to_imaginary(int y, t_mlx *env);
int				find_burningship(t_mlx *env);
void			burningship_calc(t_mlx *env);

int				keycode_press(int keypress, t_mlx *env);
int				keycode_release(int keyrelease, t_mlx *env);
int				mouse_scroll(int mouseevent, int x, int y, t_mlx *env);
int				mouse_movement(int x, int y, t_mlx *env);

void			error_str(void);
void			quit(char *str);
int				quit_program(void);

#endif
