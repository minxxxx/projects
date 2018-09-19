/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:42:47 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/25 15:59:37 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	color_div(t_col *col, double div)
{
	col->r /= div;
	col->g /= div;
	col->b /= div;
}

void	color_add(t_col *col, t_col add)
{
	col->r += add.r;
	col->g += add.g;
	col->b += add.b;
}
