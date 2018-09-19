/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece_top_bot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:44:58 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:45:01 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_piece_left_bot(t_app *app)
{
	int		x;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	while (y_max--)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_is_valid_pos(app, y_max, x))
			{
				ft_print(y_max, x);
				return ;
			}
			x++;
		}
	}
	app->play = 0;
}

void	ft_place_piece_left_top(t_app *app)
{
	int		x;
	int		y;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_is_valid_pos(app, y, x))
			{
				ft_print(y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	app->play = 0;
}

void	ft_place_piece_right_bot(t_app *app)
{
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	while (y_max--)
	{
		x_max = app->board.x;
		while (x_max--)
		{
			if (ft_is_valid_pos(app, y_max, x_max))
			{
				ft_print(y_max, x_max);
				return ;
			}
		}
	}
	app->play = 0;
}

void	ft_place_piece_right_top(t_app *app)
{
	int		x_max;
	int		y_max;
	int		y;

	y = 0;
	y_max = app->board.y;
	while (y < app->board.y)
	{
		x_max = app->board.x;
		while (x_max--)
		{
			if (ft_is_valid_pos(app, y, x_max))
			{
				ft_print(y, x_max);
				return ;
			}
		}
		y++;
	}
	app->play = 0;
}
