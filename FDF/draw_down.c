/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:39:09 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:21:22 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_down(t_window *win_struct, t_draw *draw_struct)
{
	int	i;
	int	error;

	error = draw_struct->Dx / 2;
	i = 0;
	while (i < draw_struct->Dx)
	{
		draw_struct->x += draw_struct->xincr;
		error += draw_struct->Dy;
		if (error > draw_struct->Dx)
		{
			error -= draw_struct->Dx;
			draw_struct->y += draw_struct->yincr;
		}
		mlx_pixel_put(win_struct->display_link, win_struct->win,
				draw_struct->x, draw_struct->y, draw_struct->colour);
		i++;
	}
}
