/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:19:55 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/21 09:30:44 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** Multiply two vectors and return the resulting scalar (dot product)
*/

double	vector_dot(t_vector v1, t_vector v2)
{
	double	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	if (dot <= EPSILON
		&& dot >= -EPSILON)
		return (0.0F);
	return (dot);
}
