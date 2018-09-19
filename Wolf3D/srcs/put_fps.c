/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:17:18 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 09:17:20 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_fps(t_env *env)
{
	char	*fps;

	if ((fps = ft_itoa(env->fps)))
	{
		mlx_string_put(env->window->mlx, env->window->mlx_window
				, 11, 11, 0x000000, fps);
		mlx_string_put(env->window->mlx, env->window->mlx_window
				, 10, 10, 0xFF0000, fps);
		free(fps);
	}
}
