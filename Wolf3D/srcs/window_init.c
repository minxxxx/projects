/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:17:48 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 11:32:44 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	window_init(t_env *env)
{
	int		loul;

	env->window->width = 1920;
	env->window->height = 1080;
	env->window->fov = 60;
	env->window->z_far = 30;
	if (!(env->window->mlx = mlx_init()))
		error_quit("Failed to init mlx context");
	if (!(env->window->mlx_window = mlx_new_window(env->window->mlx
					, env->window->width, env->window->height
					, "Gabriel's wolf3D")))
		error_quit("Failed to create window");
	env->window->bpp = 3 * 8;
	env->window->endian = 1;
	loul = env->window->width * env->window->bpp / 8;
	if (!(env->window->img = mlx_new_image(env->window->mlx, env->window->width
					, env->window->height)))
		error_quit("Failed to create image");
	if (!(env->window->data = mlx_get_data_addr(env->window->img
					, &(env->window->bpp), &loul, &(env->window->endian))))
		error_quit("Failed to to get image data");
}
