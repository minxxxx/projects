/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:16:24 by jbuys             #+#    #+#             */
/*   Updated: 2016/10/05 13:17:08 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_type(char **av, t_mlx *env)
{
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
		&env->endian);
	ft_putendl(STR1);
	ft_putendl(STR2);
	ft_putendl(STR3);
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		mandelbrot_calc(env);
	else if (ft_strcmp(av[1], "Julia") == 0)
		julia_calc(env);
	else if (ft_strcmp(av[1], "Burningship") == 0)
		burningship_calc(env);
	else
	{
		mlx_destroy_window(env->mlx, env->win);
		error_str();
		quit("Invalid string given");
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int		main(int argc, char **av)
{
	t_mlx mlx;

	if (argc == 2)
	{
		init_all(av, &mlx);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, av[1]);
		check_type(av, &mlx);
		mlx_hook(mlx.win, 2, (1L << 1), &keycode_press, &mlx);
		mlx_hook(mlx.win, 3, (1L << 0), &keycode_release, &mlx);
		mlx_hook(mlx.win, 17, 0L, &quit_program, &mlx);
		mlx_hook(mlx.win, 6, (1 << 6), &mouse_movement, &mlx);
		mlx_mouse_hook(mlx.win, &mouse_scroll, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
	{
		error_str();
		quit("Invalid Arugments given.");
	}
}
