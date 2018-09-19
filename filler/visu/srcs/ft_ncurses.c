/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:40:35 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:40:37 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_set_id(int *id, char c)
{
	if (c == 'O')
		(*id) = 2;
	else if (c == 'X')
		(*id) = 3;
	else if (c == 'o')
		(*id) = 4;
	else if (c == 'x')
		(*id) = 5;
	else
		(*id) = 1;
}

static void	ft_nc_print_arena(t_app *app)
{
	int		max_x;
	int		max_y;
	int		x;
	int		y;
	int		id;

	max_x = app->board.x;
	max_y = app->board.y;
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			ft_set_id(&id, app->board.tab[y][x]);
			wattron(app->render.w_left, COLOR_PAIR(id));
			mvwprintw(app->render.w_left, y + 1, x + 2, "%c",
				app->board.tab[y][x]);
			wattroff(app->render.w_left, COLOR_PAIR(id));
			x++;
		}
		y++;
	}
}

static void	ft_menu(t_app *app)
{
	wclear(app->render.w_right);
	if (app->render.run)
		mvwprintw(app->render.w_right, 1, 3, "** RUNNING **");
	else
		mvwprintw(app->render.w_right, 1, 3, "** PAUSED ** ");
	mvwprintw(app->render.w_right, 3, 3, "Vitesse : %d ", app->speed);
	mvwprintw(app->render.w_right, 5, 3, "Tour du joueur : %d",
		app->current_player.id);
	wattron(app->render.w_right, COLOR_PAIR(app->current_player.id + 1));
	mvwprintw(app->render.w_right, 6, 3, "%s             ",
		app->current_player.name);
	wattroff(app->render.w_right, COLOR_PAIR(app->current_player.id + 1));
	mvwprintw(app->render.w_right, 8, 3, "Piece :");
	if (app->piece.tab)
		ft_print_piece(app);
}

void		ft_nc_key_hook(t_app *app)
{
	int		key;

	key = 0;
	if ((key = getch()) > 0)
	{
		if (key == 32 && !app->render.run)
			app->render.run = 1;
		else if (key == 32 && app->render.run)
			app->render.run = 0;
		else if (key == 65 && app->speed < 200)
			app->speed += 1;
		else if (key == 66 && app->speed > 1)
			app->speed -= 1;
	}
	if (app->render.run)
		mvwprintw(app->render.w_right, 1, 3, "** RUNNING **");
	else
		mvwprintw(app->render.w_right, 1, 3, "** PAUSED ** ");
	mvwprintw(app->render.w_right, 3, 3, "Vitesse : %d ", app->speed);
	if (app->is_finish)
		ft_is_finish(app);
	wrefresh(app->render.w_right);
}

int			ft_nc_update(t_app *app)
{
	if (app->mode == 2 || !app->start)
		ft_nc_print_arena(app);
	if (app->mode == 1 || !app->start)
		ft_menu(app);
	wrefresh(app->render.w_left);
	wrefresh(app->render.w_right);
	usleep(1000000 / app->speed);
	return (1);
}
