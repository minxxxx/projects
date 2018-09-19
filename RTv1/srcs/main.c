/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 08:32:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/02 12:32:02 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		expose(t_env *env)
{
	if (env->win && env->img.img)
	{
		mlx_clear_window(0, env->win);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	}
	return (0);
}

void	init_render(t_env *env, int argc, char **argv)
{
	env->render = 1;
	if (argc == 3)
		if (ft_strcmp(argv[2], "-b") == 0)
			env->render = 0;
	init_render_val(env, &env->render_vals);
	set_render_val(env, &env->render_vals);
}

int		main(int argc, char **argv)
{
	t_env	env;
	clock_t start;
	int		ms;

	if (argc < 2)
	{
		ft_printf("Please include a scene file\n");
		return (0);
	}
	ft_get_input(&env, argv[1]);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "RT");
	env.img.img = mlx_new_image(env.mlx, WIN_X, WIN_Y);
	env.img.data = mlx_get_data_addr(env.img.img, &env.img.bpp,
		&env.img.s, &env.img.e);
	init_render(&env, argc, argv);
	start = clock();
	make_threads(&env);
	ms = (clock() - start) * 1000 / CLOCKS_PER_SEC;
	ft_printf("Render time %d s %d ms\n", ms / 1000 / 4, ms % 1000 / 4);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.win, expose, &env);
	mlx_hook(env.win, 17, 0L, &close_window, &env);
	mlx_loop(env.mlx);
	return (0);
}
