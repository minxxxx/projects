/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 09:24:29 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/05 14:14:57 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

int				expose(t_frac *s)
{
	s->image.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->image.d = mlx_get_data_addr(s->image.img,
			&s->image.bpp, &s->image.s, &s->image.e);
	screen_loop(s);
	mlx_put_image_to_window(s->mlx, s->win, s->image.img, 0, 0);
	return (0);
}

static	void	init(t_frac *s)
{
	s->mlx = mlx_init();
	if (s->mlx == NULL)
		ft_error("Could not init mlx");
	s->win = mlx_new_window(s->mlx, WIDTH, HEIGHT, "Fractol");
	init_colours(s);
	init_mandelbrot(s);
	init_julia(s);
	expose(s);
	mlx_expose_hook(s->win, expose, s);
	mlx_key_hook(s->win, keyboard, s);
	mlx_mouse_hook(s->win, &mouse_zoom, s);
	mlx_hook(s->win, 6, (1 << 6), &mouse_hook, s);
	mlx_loop(s->mlx);
}

int				main(int argc, char **argv)
{
	t_frac *s;

	if (argc != 2)
		ft_error("Usage: ./fractol [Fractal]");
	if (!(ft_strequ("mandelbrot", argv[1])
				|| ft_strequ("julia", argv[1])
				|| ft_strequ("burningship", argv[1])
				|| ft_strequ("tricorn", argv[1])
				|| ft_strequ("flower", argv[1])
				|| ft_strequ("batman", argv[1])))
	{
		ft_putstr(ERR_MSG_P1);
		ft_error(ERR_MSG_P2);
	}
	s = (t_frac *)ft_memalloc(sizeof(t_frac));
	s->fractal = argv[1];
	init(s);
	return (0);
}
