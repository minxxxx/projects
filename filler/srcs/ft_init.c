/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:44:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:44:27 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_board_or_piece(t_app *app, char *str)
{
	if (ft_strstr(str, "Plateau"))
	{
		if (!app->board.x)
		{
			app->board.y = ft_atoi(str += 8);
			app->board.x = ft_atoi(str += 2);
		}
		ft_clear_tab(app->board.tab);
		app->mode = 1;
	}
	else if (ft_strstr(str, "Piece"))
	{
		app->piece.y = ft_atoi(str += 6);
		app->piece.x = ft_atoi(str += 2);
		ft_clear_tab(app->piece.tab);
		app->mode = 2;
	}
}

void	ft_init_way(t_app *app)
{
	app->way[0].f = ft_place_piece_left_top;
	app->way[0].token = 0x14;
	app->way[1].f = ft_place_piece_right_top;
	app->way[1].token = 0x24;
	app->way[2].f = ft_place_piece_left_bot;
	app->way[2].token = 0x18;
	app->way[3].f = ft_place_piece_right_bot;
	app->way[3].token = 0x28;
	app->way[4].f = ft_place_piece_top_left;
	app->way[4].token = 0x41;
	app->way[5].f = ft_place_piece_top_right;
	app->way[5].token = 0x42;
	app->way[6].f = ft_place_piece_bot_left;
	app->way[6].token = 0x81;
	app->way[7].f = ft_place_piece_bot_right;
	app->way[7].token = 0x82;
}

void	ft_init_pos(t_app *app)
{
	app->pos[0].left.x = app->board.x;
	app->pos[1].left.x = app->board.x;
	app->pos[0].top.y = app->board.y;
	app->pos[1].top.y = app->board.y;
}
