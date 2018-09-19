/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:44:06 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:44:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_best_way(t_app *app, unsigned char way)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	while (i < 8)
	{
		if (way == app->way[i].token && (find = 1))
			break ;
		i++;
	}
	if (!find)
	{
		i = 0;
		while (i < 8)
		{
			if ((way & app->way[i].token) & 0x0f ||
				(way & app->way[i].token) & 0xf0)
				break ;
			i++;
		}
	}
	if (i >= 8)
		i = 0;
	app->way[i].f(app);
}

void		ft_sort_way(t_app *app)
{
	int				i;
	t_dist			tmp;
	unsigned char	way;

	i = 0;
	ft_bzero(&tmp, sizeof(t_dist));
	way = 0;
	while (i < 3)
	{
		if (app->dist[i + 1].value < app->dist[i].value)
		{
			tmp = app->dist[i];
			app->dist[i] = app->dist[i + 1];
			app->dist[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	way |= app->dist[0].id;
	way <<= 4;
	way |= app->dist[1].id;
	ft_best_way(app, way);
}

void		ft_calculate_dist(t_app *app)
{
	int		me;
	int		en;

	ft_calculate_edge(app);
	me = app->id_me;
	en = app->id_enemy;
	app->dist[0].value = app->pos[en].left.x - app->pos[me].left.x;
	app->dist[0].id = 1;
	app->dist[1].value = app->pos[me].right.x - app->pos[en].right.x;
	app->dist[1].id = 2;
	app->dist[2].value = app->pos[en].top.y - app->pos[me].top.y;
	app->dist[2].id = 4;
	app->dist[3].value = app->pos[me].bot.y - app->pos[en].bot.y;
	app->dist[3].id = 8;
}

void		ft_generate_pos(t_app *app)
{
	ft_calculate_dist(app);
	ft_sort_way(app);
}
