/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:45:13 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:45:14 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_set_player(t_app *app, char *str)
{
	int		i;

	i = 0;
	if (str[0] && str[0] == '$' && ft_strstr(str, "/filler]"))
	{
		if (ft_strlen(str) >= 12)
			str += 10;
		app->id_player = str[0];
		if (app->id_player == '1')
		{
			app->me = 'o';
			app->enemy = 'x';
			app->id_enemy = 1;
		}
		else
		{
			app->me = 'x';
			app->enemy = 'o';
			app->id_me = 1;
		}
	}
}

void	ft_set_current_player(t_app *app, char *str)
{
	if (ft_strlen(str) > 10)
	{
		str += 6;
		if (str[0] == 'O')
			app->id_current_player = 0;
		else
			app->id_current_player = 1;
	}
}

void	ft_set_board(t_app *app, char *str)
{
	if (ft_strlen(str) >= (size_t)app->board.x)
	{
		str += 4;
		if (app->board.current_line >= 1)
			ft_lstpush_back(&app->list_tmp, str, ft_strlen(str) + 1);
		app->board.current_line++;
		if (app->board.current_line == app->board.y + 1)
		{
			app->board.tab = (char**)ft_lsttotab(app->list_tmp);
			app->board.tmp_tab = (char**)ft_lsttotab(app->list_tmp);
			ft_clear_list(app);
			app->mode = 0;
			app->board.current_line = 0;
		}
	}
}

void	ft_set_piece(t_app *app, char *str)
{
	if (*str)
	{
		ft_lstpush_back(&app->list_tmp, str, ft_strlen(str) + 1);
		app->piece.current_line++;
		if (app->piece.current_line == app->piece.y)
		{
			app->piece.tab = (char**)ft_lsttotab(app->list_tmp);
			ft_clear_list(app);
			ft_generate_pos(app);
			app->mode = 0;
			app->piece.current_line = 0;
		}
	}
}
