/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ray_trace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:02:18 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/22 15:30:36 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** Determine whether ray intersects with cone by substiting ray equation
** in cone equation
*/

int			intersect_ray_cone(t_ray *ray, t_cone *cone, double *t)
{
	t_ray_sphere	rs;
	t_vector		a;
	t_vector		b;
	t_vector		del_p;

	a = vector_sub(V, vector_scale(vector_dot(V, cone->v), cone->v));
	rs.a = SQR(cos(cone->alpha)) * VEC_SQR(a) - SQR(sin(cone->alpha)) *
		SQR(vector_dot(cone->v, V));
	del_p = vector_sub(P, cone->p);
	b = vector_sub(del_p, vector_scale(vector_dot(del_p, cone->v), cone->v));
	rs.b = 2.0F * SQR(cos(cone->alpha)) * vector_dot(a, b) - 2.0F
		* SQR(sin(cone->alpha))
		* vector_dot(V, cone->v) * vector_dot(del_p, cone->v);
	rs.c = SQR(cos(cone->alpha)) * VEC_SQR(b) - SQR(sin(cone->alpha)) *
		SQR(vector_dot(del_p, cone->v));
	rs.discr = SQR(rs.b) - (4.0F * rs.a * rs.c);
	if (rs.discr < 0.0F)
		return (0);
	else
	{
		if (cone->inf)
			return (solve_quadratic(&rs, t));
		else
			return (solve_quadratic_cone(ray, cone, &rs, t));
	}
}

/*
** Determine whether ray intersects with cylinder by substiting ray equation
** in cylinder equation
*/

int			intersect_ray_cylinder(t_ray *ray, t_cylinder *cyl, double *t)
{
	t_ray_sphere	rs;
	t_vector		a;
	t_vector		b;
	t_vector		del_p;

	a = vector_sub(V, vector_scale(vector_dot(V, VA), VA));
	rs.a = VEC_SQR(a);
	del_p = vector_sub(P, PA);
	b = vector_sub(del_p, vector_scale(vector_dot(del_p, VA), VA));
	rs.b = 2.0F * vector_dot(a, b);
	rs.c = VEC_SQR(b) - SQR(cyl->radius);
	rs.discr = SQR(rs.b) - (4 * rs.a * rs.c);
	if (rs.discr < 0.0F)
		return (0);
	else
	{
		if (cyl->inf)
			return (solve_quadratic(&rs, t));
		else
			return (solve_quadratic_cylinder(ray, cyl, &rs, t));
	}
}

/*
** Determine whether ray intersects with sphere by substiting ray equation
** in sphere equation
*/

int			intersect_ray_sphere(t_ray *ray, t_sphere *sphere, double *t)
{
	t_ray_sphere	rs;

	rs.a = vector_dot(ray->dir, ray->dir);
	rs.dist = vector_sub(ray->start, sphere->shape.pos);
	rs.b = 2 * vector_dot(ray->dir, rs.dist);
	rs.c = vector_dot(rs.dist, rs.dist) - (sphere->radius * sphere->radius);
	rs.discr = rs.b * rs.b - (4 * rs.a * rs.c);
	if (rs.discr < 0.0F)
		return (0);
	else
		return (solve_quadratic(&rs, t));
}
