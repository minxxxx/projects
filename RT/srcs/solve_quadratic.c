/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 23:27:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/22 15:32:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	solve_quadratic(t_ray_sphere *rs, double *t)
{
	rs->t0 = (-rs->b - sqrt(rs->discr)) / (2 * rs->a);
	rs->t1 = (-rs->b + sqrt(rs->discr)) / (2 * rs->a);
	if (rs->t0 > rs->t1 && rs->t1 > 0.0F)
		rs->t0 = rs->t1;
	if ((rs->t0 > EPSILON) && (rs->t0 < *t))
	{
		*t = rs->t0;
		return (1);
	}
	else
		return (0);
}

int	solve_quadratic_cylinder(t_ray *ray, t_cylinder *cyl,
	t_ray_sphere *rs, double *t)
{
	double		temp;
	t_vector	p;

	temp = *t;
	cyl->bot = vector_scale(cyl->scale,
					vector_sub((t_vector){0, 0, 0}, cyl->v));
	cyl->top = vector_scale(cyl->scale, cyl->v);
	if (solve_quadratic(rs, &temp) == 0)
		return (0);
	p = vector_add(ray->start, vector_scale(temp, ray->dir));
	if (cyl->inf == 0 && vector_dot(cyl->v, vector_sub(p, cyl->bot)) > 0
		&& vector_dot(cyl->v, vector_sub(p, cyl->top)) < 0)
	{
		*t = temp;
		return (1);
	}
	if (cyl->inf == 1)
		*t = temp;
	return (cyl->inf);
}

int	in_limit(double t, t_cone *cone, t_ray *ray)
{
	t_vector	p;

	p = vector_add(ray->start, vector_scale(t, ray->dir));
	return (vector_dot(cone->v, vector_sub(p, cone->bot)) > 0.0F
			&& vector_dot(cone->v, vector_sub(p, cone->top)) < 0.0F);
}

int	solve_quadratic_cone(t_ray *ray, t_cone *cone,
	t_ray_sphere *rs, double *t)
{
	double		temp;

	temp = *t;
	if (cone->type == 0)
	{
		cone->bot = cone->p;
		cone->top = vector_add(vector_scale(cone->scale, cone->v), cone->p);
	}
	else
	{
		cone->bot = vector_add(vector_scale(cone->scale / 2,
			vector_sub((t_vector){0, 0, 0}, cone->v)), cone->p);
		cone->top = vector_add(vector_scale(cone->scale / 2, cone->v), cone->p);
	}
	if (solve_quadratic(rs, &temp) == 0)
		return (0);
	if (cone->inf == 0 && in_limit(temp, cone, ray))
	{
		*t = temp;
		return (1);
	}
	if (cone->inf == 1)
		*t = temp;
	return (cone->inf);
}
