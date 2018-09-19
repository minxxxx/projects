/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:45:55 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:45:57 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print(int y, int x)
{
	char	*str_y;
	char	*str_x;

	str_y = ft_itoa(y);
	str_x = ft_itoa(x);
	write(1, str_y, ft_strlen(str_y));
	write(1, " ", 1);
	write(1, str_x, ft_strlen(str_x));
	write(1, "\n", 1);
}

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

void	ft_clear_tab(char **tab)
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

int		ft_check_pos(t_app *app, t_point pb, t_point pp, int *star)
{
	char	c;

	c = 0;
	if ((pb.y + pp.y) < app->board.y && (pb.x + pp.x) < app->board.x)
	{
		c = ft_tolower(app->board.tab[pb.y + pp.y][pb.x + pp.x]);
		if (c == app->me && app->piece.tab[pp.y][pp.x] == '*')
			(*star)++;
		if (app->piece.tab[pp.y][pp.x] == '*' && c == app->enemy)
			return (0);
	}
	else if (app->piece.tab[pp.y][pp.x] == '*')
		return (0);
	return (1);
}

int		ft_is_valid_pos(t_app *app, int y, int x)
{
	t_point	pp;
	t_point	pb;
	int		star;

	pp.y = 0;
	star = 0;
	pb.y = y;
	pb.x = x;
	while (pp.y < app->piece.y)
	{
		pp.x = 0;
		while (pp.x < app->piece.x)
		{
			if (!ft_check_pos(app, pb, pp, &star))
				return (0);
			pp.x++;
		}
		pp.y++;
	}
	if (star != 1)
		return (0);
	return (1);
}
