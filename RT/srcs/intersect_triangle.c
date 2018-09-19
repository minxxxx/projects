/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 15:19:43 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/22 15:33:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** Uses triangle - plane intersection algorith to determine if a ray hits
** the plane.
*/

int			intersect_ray_tri(t_ray *ray, t_triangle *tri, double *t)
{
	t_ray_tri	r;

	r.e1 = vector_sub(tri->v2, tri->v1);
	r.e2 = vector_sub(tri->v3, tri->v1);
	r.s1 = vector_cross(ray->dir, r.e2);
	r.d = vector_dot(r.e1, r.s1);
	if (r.d > -EPSILON && r.d < EPSILON)
		return (0);
	r.inv_d = 1 / r.d;
	r.s2 = vector_sub(ray->start, tri->v1);
	r.u = vector_dot(r.s2, r.s1) * r.inv_d;
	if (r.u < 0 || r.u > 1)
		return (0);
	r.s3 = vector_cross(r.s2, r.e1);
	r.v = vector_dot(ray->dir, r.s3) * r.inv_d;
	if (r.v < 0 || (r.u + r.v) > 1)
		return (0);
	r.tmp = vector_dot(r.e2, r.s3) * r.inv_d;
	if (r.tmp < EPSILON)
		return (0);
	*t = r.tmp - 0.005F;
	return (1);
}
