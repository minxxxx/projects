/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:36:36 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:25:07 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_map(t_display *display_struct, int win_width, int border,
		char ***map)
{
	display_struct->y_start = border;
	display_struct->av_height = average_height(map);
	display_struct->map_width = arr_size_2d(*map) - 1;
	display_struct->map_length = arr_size_3d(map) - 1;
	display_struct->size = ((win_width - (2 * border))
			/ ((display_struct->map_width + display_struct->map_length)));
	if (display_struct->av_height)
		display_struct->av_height = display_struct->size
			/ display_struct->av_height / 1.3;
	display_struct->ratio = ((100 / (display_struct->map_width
					+ display_struct->map_length)) *
			display_struct->map_length) / 100;
	display_struct->x_start = win_width * display_struct->ratio;
	display_struct->window_height = (win_width / 2) + border;
	display_struct->x = display_struct->x_start;
	display_struct->y = display_struct->y_start;
}
