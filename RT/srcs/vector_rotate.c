/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 07:50:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/25 08:26:11 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	rotate_vec_x(double angle, t_vector *v)
{
	double	y1;
	double	z1;

	angle = angle * 0.01745329252F;
	if (in_epsilon(angle))
		return ;
	z1 = v->z * cos(angle) - v->y * sin(angle);
	y1 = v->y * cos(angle) + v->z * sin(angle);
	v->y = y1;
	v->z = z1;
}

void	rotate_vec_y(double angle, t_vector *v)
{
	double	x1;
	double	z1;

	angle = angle * 0.01745329252F;
	if (in_epsilon(angle))
		return ;
	z1 = v->z * cos(angle) + v->x * sin(angle);
	x1 = v->x * cos(angle) - v->z * sin(angle);
	v->x = x1;
	v->z = z1;
}

void	rotate_vec_z(double angle, t_vector *v)
{
	double	x1;
	double	y1;

	angle = angle * 0.01745329252F;
	if (in_epsilon(angle))
		return ;
	y1 = v->y * cos(angle) - v->x * sin(angle);
	x1 = v->y * sin(angle) + v->x * cos(angle);
	v->x = x1;
	v->y = y1;
}
