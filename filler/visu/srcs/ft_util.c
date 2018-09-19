/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:41:04 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:41:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_clear_list(t_app *app)
{
	t_list	*l;
	t_list	*tmp;

	l = app->list_tmp;
	tmp = NULL;
	while (l)
	{
		free(l->content);
		l->content = NULL;
		l->content_size = 0;
		tmp = l;
		free(l);
		l = tmp->next;
	}
	app->list_tmp = NULL;
}

void	ft_clean_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab && tab[0])
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	ft_print_piece(t_app *app)
{
	int		max_y;
	int		y;

	max_y = app->piece.y;
	y = 0;
	while (y < max_y)
	{
		mvwprintw(app->render.w_right, y + 10, 3, "%s", app->piece.tab[y]);
		y++;
	}
}

void	ft_is_finish(t_app *app)
{
	wclear(app->render.w_right);
	mvwprintw(app->render.w_right, 1, 3, "Score :");
	wattron(app->render.w_right, COLOR_PAIR(2));
	mvwprintw(app->render.w_right, 3, 3, "%s : %d",
		app->p1.name, app->p1_score);
	wattroff(app->render.w_right, COLOR_PAIR(2));
	wattron(app->render.w_right, COLOR_PAIR(3));
	mvwprintw(app->render.w_right, 4, 3, "%s : %d",
		app->p2.name, app->p2_score);
	wattroff(app->render.w_right, COLOR_PAIR(3));
	mvwprintw(app->render.w_right, app->board.y, 3,
		"ESC pour quitter", app->speed);
	wrefresh(app->render.w_right);
	while (getch() != 27)
		;
	wclear(app->render.w_right);
	wclear(app->render.w_left);
}
