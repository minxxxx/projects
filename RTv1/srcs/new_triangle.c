/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:03:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/13 16:48:45 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_triangle	new_triangle(t_vector v1, t_vector v2, t_vector v3, int mat)
{
	t_triangle new;

	new.v1 = v1;
	new.v2 = v2;
	new.v3 = v3;
	new.shape.pos.x = (v1.x + v2.x + v3.x) / 3;
	new.shape.pos.y = (v1.y + v2.y + v3.y) / 3;
	new.shape.pos.z = (v1.z + v2.z + v3.z) / 3;
	new.shape.material = mat;
	return (new);
}

void		set_tri_pos(t_triangle *tri)
{
	tri->shape.pos.x = (tri->v1.x + tri->v2.x + tri->v3.x) / 3;
	tri->shape.pos.y = (tri->v1.y + tri->v2.y + tri->v3.y) / 3;
	tri->shape.pos.z = (tri->v1.z + tri->v2.z + tri->v3.z) / 3;
}
