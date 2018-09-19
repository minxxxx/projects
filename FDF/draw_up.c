/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:38:44 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:14:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_up(t_window *win_struct, t_draw *draw_struct)
{
	int	i;
	int	error;

	error = draw_struct->Dy / 2;
	i = 0;
	while (i < draw_struct->Dy)
	{
		draw_struct->y += draw_struct->yincr;
		error += draw_struct->Dx;
		if (error > draw_struct->Dy)
		{
			error -= draw_struct->Dy;
			draw_struct->x += draw_struct->xincr;
		}
		mlx_pixel_put(win_struct->display_link, win_struct->win,
				draw_struct->x, draw_struct->y, draw_struct->colour);
		i++;
	}
}
