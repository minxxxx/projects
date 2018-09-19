/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:45:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:45:22 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_set_point_right(int player, t_app *app, int y, int x)
{
	t_point	p;

	ft_bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].right = p;
}

void	ft_set_point_left(int player, t_app *app, int y, int x)
{
	t_point	p;

	ft_bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].left = p;
}

void	ft_set_point_top(int player, t_app *app, int y, int x)
{
	t_point	p;

	ft_bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].top = p;
}

void	ft_set_point_bot(int player, t_app *app, int y, int x)
{
	t_point	p;

	ft_bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].bot = p;
}
