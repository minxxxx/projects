/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 07:35:04 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/02 11:49:48 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	re_render(t_env *env, int r)
{
	ft_init_cam(env, OBJ.cam_rot, r);
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	env->img.data = mlx_get_data_addr(env->img.img, &env->img.bpp, &env->img.s,
			&env->img.e);
	make_threads(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

void	move_cam(t_env *env, int dir)
{
	if (dir == 1)
		CAM.pos = vector_add(CAM.pos, vector_scale(10, CAM.dir));
	else
		CAM.pos = vector_add(CAM.pos, vector_scale(10, vector_sub((t_vector)
						{0.0F, 0.0F, 0.0F}, CAM.dir)));
}

int		keyhook2(int keycode, t_env *env)
{
	if (keycode == KEY_LEFT)
	{
		OBJ.cam_rot.z -= ROT_DELTA;
		re_render(env, 1);
	}
	if (keycode == KEY_RIGHT)
	{
		OBJ.cam_rot.z += ROT_DELTA;
		re_render(env, 1);
	}
	if (keycode == KEY_W)
	{
		move_cam(env, 1);
		re_render(env, 0);
	}
	if (keycode == KEY_S)
	{
		move_cam(env, -1);
		re_render(env, 0);
	}
	return (1);
}

int		key_hook(int keycode, t_env *env)
{
	ft_printf("key = %d\n", keycode);
	if (keycode == KEY_R)
	{
		env->render = (env->render == 1) ? 0 : 1;
		set_render_val(env, &env->render_vals);
		re_render(env, 0);
	}
	if (keycode == EXIT)
	{
		cleanup(env);
		exit(0);
	}
	if (keycode == KEY_UP)
	{
		OBJ.cam_rot.x -= ROT_DELTA;
		re_render(env, 1);
	}
	if (keycode == KEY_DOWN)
	{
		OBJ.cam_rot.x += ROT_DELTA;
		re_render(env, 1);
	}
	return (keyhook2(keycode, env));
}
