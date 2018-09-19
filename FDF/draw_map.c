/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:34:45 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:14:39 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_display *display_struct, t_window *win_struct,
		t_draw *draw_struct, char ***map)
{
	display_struct->i = 0;
	display_struct->j = 0;
	while (display_struct->map_length >= 0)
	{
		while (display_struct->map_width >= 0)
		{
			draw_width(display_struct, win_struct, draw_struct, map);
			display_struct->x += display_struct->size;
			display_struct->y += (display_struct->size / 2);
			display_struct->map_width--;
			display_struct->j++;
		}
		display_struct->y_start += display_struct->size / 2;
		display_struct->y = display_struct->y_start;
		display_struct->map_width = arr_size_2d(*map) - 1;
		display_struct->x_start -= display_struct->size;
		display_struct->x = display_struct->x_start;
		display_struct->map_length--;
		display_struct->i++;
		display_struct->j = 0;
	}
}
