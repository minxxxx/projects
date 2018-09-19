/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:35:58 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 10:34:16 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_width(t_display *display_struct, t_window *win_struct,
		t_draw *draw_struct, char ***map)
{
	draw_struct->x1 = display_struct->x;
	if (display_struct->map_width)
	{
		draw_struct->x2 = display_struct->x + display_struct->size;
		draw_struct->y1 = display_struct->y - (ft_atoi(map[display_struct->i]
					[display_struct->j]) * display_struct->av_height);
		draw_struct->y2 = display_struct->y + (display_struct->size / 2) -
			(ft_atoi(map[display_struct->i][display_struct->j + 1]) *
			display_struct->av_height);
		if ((ft_atoi(map[display_struct->i][display_struct->j])) != 0)
			draw_struct->colour = 0x000000FF;
		else
			draw_struct->colour = 0x00FFFFFF;
		draw_line(win_struct, draw_struct);
	}
	if (display_struct->map_length)
	{
		draw_struct->x2 = display_struct->x - display_struct->size;
		draw_struct->y1 = display_struct->y - (ft_atoi(map[display_struct->i]
					[display_struct->j]) * display_struct->av_height);
		draw_struct->y2 = display_struct->y + (display_struct->size / 2) -
			(ft_atoi(map[display_struct->i + 1][display_struct->j]) *
			display_struct->av_height);
		draw_line(win_struct, draw_struct);
	}
}
