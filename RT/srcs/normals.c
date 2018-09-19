/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 08:53:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/22 15:16:15 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	get_tri_normal(t_triangle *tri)
{
	return (vector_unit(vector_cross(vector_sub(tri->v2, tri->v1),
		vector_sub(tri->v3, tri->v1))));
}

/*
** Will get normal vector for cylinder where p is the point of
** intersection.
*/

t_vector	get_cyl_normal(t_cylinder cyl, t_vector p)
{
	return (vector_unit(vector_sub(vector_sub(p, cyl.shape.pos),
		vector_project(vector_sub(p, cyl.shape.pos), cyl.v))));
}

/*
** Will get normal vector for cone where p is the point of
** intersection.
*/

t_vector	get_cone_normal(t_cone cone, t_vector p)
{
	t_vector	v;
	t_vector	n;
	t_vector	p_par;
	t_vector	p_orth;

	n = vector_unit(vector_sub(vector_sub(p, cone.p),
				vector_project(vector_sub(p, cone.p), cone.v)));
	v = (vector_comp(vector_dir(
		vector_add(vector_project(p, cone.v), cone.p), cone.p), cone.v)) ?
		vector_unit(vector_cross(n, cone.v)) :
		vector_unit(vector_cross(cone.v, n));
	p_par = vector_project(n, v);
	p_orth = vector_sub(n, p_par);
	p_orth = vector_add(vector_scale(cos(cone.alpha), p_orth),
		vector_scale(sin(cone.alpha), vector_cross(v, p_orth)));
	return (vector_unit(vector_add(p_orth, p_par)));
}
