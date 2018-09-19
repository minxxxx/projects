/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:34:03 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:10:16 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_map(int win_width, int border, char ***map, char *map_name)
{
	t_display	*display_struct;
	t_window	*win_struct;
	t_draw		*draw_struct;

	display_struct = (t_display *)malloc(sizeof(t_display));
	set_map(display_struct, win_width, border, map);
	win_struct = (t_window *)malloc(sizeof(t_window));
	draw_struct = (t_draw *)malloc(sizeof(t_draw));
	win_struct->display_link = mlx_init();
	win_struct->win = mlx_new_window(win_struct->display_link,
			win_width, display_struct->window_height, map_name);
	draw_map(display_struct, win_struct, draw_struct, map);
	mlx_key_hook(win_struct->win, ft_exit, 0);
	mlx_loop(win_struct->display_link);
}
