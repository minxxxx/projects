/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browse_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:43:55 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 13:25:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_set_point_left_right(t_app *app, int y, int x)
{
	char	c;

	c = ft_tolower(app->board.tab[y][x]);
	if (c == 'o' && x > app->pos[0].right.x)
		ft_set_point_right(0, app, y, x);
	if (c == 'x' && x > app->pos[0].right.x)
		ft_set_point_right(1, app, y, x);
	if (c == 'o' && x < app->pos[0].left.x)
		ft_set_point_left(0, app, y, x);
	if (c == 'x' && x < app->pos[1].left.x)
		ft_set_point_left(1, app, y, x);
}

static void		ft_calc_left_and_right(t_app *app)
{
	int	x_max;
	int	y_max;
	int	x;
	int	y;

	y = 0;
	x_max = app->board.x;
	y_max = app->board.y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			ft_set_point_left_right(app, y, x);
			x++;
		}
		y++;
	}
}

static void		ft_set_point_top_bot(t_app *app, int y, int x)
{
	char	c;

	c = ft_tolower(app->board.tab[y][x]);
	if (c == 'o' && y > app->pos[0].bot.y)
		ft_set_point_bot(0, app, y, x);
	if (c == 'x' && y > app->pos[1].bot.y)
		ft_set_point_bot(1, app, y, x);
	if (c == 'o' && y < app->pos[0].top.y)
		ft_set_point_top(0, app, y, x);
	if (c == 'x' && y < app->pos[1].top.y)
		ft_set_point_top(1, app, y, x);
}

static void		ft_calc_top_and_bot(t_app *app)
{
	int	x_max;
	int	y_max;
	int	x;
	int	y;

	y = 0;
	x_max = app->board.x;
	y_max = app->board.y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			ft_set_point_top_bot(app, y, x);
			x++;
		}
		y++;
	}
}

void			ft_calculate_edge(t_app *app)
{
	ft_init_pos(app);
	ft_calc_left_and_right(app);
	ft_calc_top_and_bot(app);
}
