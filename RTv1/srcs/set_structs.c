/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 12:24:33 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/28 09:37:38 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	print_vector(char *des, t_vector v)
{
	printf("%s (%F ; %F ; %F)\n", des, v.x, v.y, v.z);
}

void	print_col(t_col col)
{
	printf("r%f g%f b%f\n", col.r * 255.0f, col.g * 255.0f, col.b * 255.0f);
}

void	set_col(t_col *col, float r, float g, float b)
{
	col->r = r;
	col->g = g;
	col->b = b;
}
