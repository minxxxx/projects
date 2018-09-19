/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 14:31:02 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/04 14:46:24 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			colourpicker(t_point p1, t_point p2, float k)
{
	int			col;

	if (p1.col == 1 && p2.col == 1)
		col = GREEN; //YELLOW;
	else if (p1.col == 1 || p2.col == 1)
	{
		if (p2.z < p1.z)
			col = (RED + GRAY) - (k * 100);
		else
			col = (RED + GRAY) - ((1 - k) * 100);
	}
	else
		col = GRAY;
	return (col);
}

static void	draw_point(t_point p1, t_point p2, t_mapinfo *m, t_line_var lvar)
{
	float		k;
	int			colour;
	float		step;

	k = 0;
	step = (float)pow((fmax(CON_TWO, CON_THREE)), -1);
	while (!(p1.x == p2.x && p1.z == p2.z))
	{
		lvar.e2 = lvar.err;
		if (lvar.e2 > -lvar.dx)
		{
			lvar.err -= lvar.dy;
			p1.x += lvar.sx;
		}
		if (lvar.e2 < lvar.dy)
		{
			lvar.err += lvar.dx;
			p1.z += lvar.sy;
		}
		k += step;
		colour = colourpicker(p1, p2, k);
		mlx_pixel_put(m->mlx, m->win, p1.x, p1.z, colour);
	}
}

void		draw_line(t_point p1, t_point p2, t_mapinfo *m)
{
	t_line_var	lvar;

	lvar.dx = abs(p2.x - p1.x);
	lvar.sx = p1.x < p2.x ? 1 : -1;
	lvar.dy = abs(p2.z - p1.z);
	lvar.sy = p1.z < p2.z ? 1 : -1;
	lvar.err = (lvar.dx > lvar.dy ? lvar.dx : -lvar.dy) / 2;
	mlx_pixel_put(m->mlx, m->win, p1.x, p1.z, 0x00808080);
	draw_point(p1, p2, m, lvar);
}
