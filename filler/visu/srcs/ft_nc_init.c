/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:40:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:40:09 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_nc_init_color(void)
{
	init_color(COL_GREY, 300, 300, 300);
	init_color(COL_RED, 600, 0, 0);
	init_color(COL_LIGHT_RED, 1000, 300, 300);
	init_color(COL_GREEN, 0, 600, 0);
	init_color(COL_LIGHT_GREEN, 300, 1000, 300);
	init_color(COL_BLUE, 0, 0, 600);
	init_color(COL_LIGHT_BLUE, 300, 300, 1000);
	init_color(COL_YELLOW, 600, 600, 0);
	init_color(COL_LIGHT_YELLOW, 1000, 1000, 300);
	init_color(COL_WHITE, 1000, 1000, 1000);
	init_pair(1, COL_GREY, COLOR_BLACK);
	init_pair(2, COL_RED, COLOR_BLACK);
	init_pair(3, COL_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COL_LIGHT_RED);
	init_pair(5, COLOR_BLACK, COL_LIGHT_BLUE);
}

void		ft_nc_init(t_app *app)
{
	FILE	*f;

	f = fopen("/dev/tty", "r+");
	newterm(getenv("TERM"), f, f);
	app->render.run = IS_RUN;
	start_color();
	nodelay(stdscr, TRUE);
	curs_set(0);
	noecho();
	ft_nc_init_color();
	app->render.w_left = newwin(app->board.y + 3, app->board.x + 4, 0, 0);
	app->render.w_right = newwin(app->board.y + 30, 40, 0, app->board.x + 5);
	box(app->render.w_left, ACS_VLINE, ACS_HLINE);
	refresh();
}

void		ft_init_board_or_piece(t_app *app, char *str)
{
	if (ft_strstr(str, "Plateau"))
	{
		if (!app->board.x)
		{
			app->board.y = ft_atoi(str += 8);
			app->board.x = ft_atoi(str += 2);
		}
		ft_clean_tab(app->board.tab);
		app->mode = 1;
	}
	else if (ft_strstr(str, "Piece"))
	{
		app->piece.y = ft_atoi(str += 6);
		app->piece.x = ft_atoi(str += 2);
		ft_clean_tab(app->piece.tab);
		app->mode = 2;
	}
}
