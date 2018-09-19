/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:15:38 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 09:15:40 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pixel_put(t_env *env, int x, int y, unsigned int colour)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	c;

	c = mlx_get_color_value(env->window->mlx, colour);
	r = (colour & 0xFF0000) >> 16;
	g = (colour & 0x00FF00) >> 8;
	b = (colour & 0x0000FF);
	if (x >= 0 && x <= env->window->width
			&& y >= 0 && y <= env->window->height)
	{
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x] = b;
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x + 1] = g;
		env->window->data[y * env->window->width * env->window->bpp / 8
			+ env->window->bpp / 8 * x + 2] = r;
	}
}
