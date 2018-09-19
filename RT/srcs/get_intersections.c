/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 07:24:50 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/26 13:47:40 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** Calculate ray - primitive intesection.
*/

static void		gi_sphere(t_env *env, t_ray *ray, double *t)
{
	int			i;
	double		t1;

	t1 = *t;
	i = 0;
	OBJ.cur_sphere = -1;
	while (i < OBJ.num_spheres)
	{
		if (intersect_ray_sphere(ray, &OBJ.spheres[i], &t1))
		{
			if (t1 < *t)
			{
				*t = t1;
				OBJ.cur_sphere = i;
			}
		}
		i++;
	}
}

static void		gi_tri(t_env *env, t_ray *ray, double *t)
{
	int			i;
	double		t2;

	t2 = *t;
	i = -1;
	OBJ.cur_tri = -1;
	while (++i < OBJ.num_tri)
		if (intersect_ray_tri(ray, &OBJ.triangles[i], &t2))
		{
			if (t2 < *t)
			{
				*t = t2;
				OBJ.cur_tri = i;
				OBJ.cur_sphere = -1;
			}
		}
}

static void		gi_cyl(t_env *env, t_ray *ray, double *t)
{
	int			i;
	double		t3;

	i = -1;
	t3 = *t;
	OBJ.cur_cyl = -1;
	while (++i < OBJ.num_cyl)
		if (intersect_ray_cylinder(ray, &CYLINDERS[i], &t3))
		{
			if (t3 < *t)
			{
				*t = t3;
				OBJ.cur_cyl = i;
				OBJ.cur_sphere = -1;
				OBJ.cur_tri = -1;
			}
		}
}

static void		gi_cone(t_env *env, t_ray *ray, double *t)
{
	int			i;
	double		t4;

	i = -1;
	t4 = *t;
	OBJ.cur_cone = -1;
	while (++i < OBJ.num_cone)
		if (intersect_ray_cone(ray, &CONES[i], &t4))
		{
			if (t4 < *t)
			{
				*t = t4;
				OBJ.cur_cone = i;
				OBJ.cur_sphere = -1;
				OBJ.cur_tri = -1;
				OBJ.cur_cyl = -1;
			}
		}
}

/*
** Get shape intersections with ray - sets values for closest one.
*/

int				get_intersections(t_env *env, t_ray *ray, double *t)
{
	gi_sphere(env, ray, t);
	gi_tri(env, ray, t);
	gi_cyl(env, ray, t);
	gi_cone(env, ray, t);
	gi_plane(env, ray, t);
	gi_object(env, ray, t);
	if (OBJ.cur_sphere != -1)
		set_val_sphere(env, *t, ray);
	else if (OBJ.cur_tri != -1)
		set_val_tri(env, *t, ray);
	else if (OBJ.cur_cyl != -1)
		set_val_cyl(env, *t, ray);
	else if (OBJ.cur_cone != -1)
		set_val_cone(env, *t, ray);
	else if (OBJ.cur_plane != -1)
		set_val_plane(env, *t, ray);
	else if (OBJ.cur_object[0] != -1)
		set_val_object(env, *t, ray);
	else
		return (0);
	return (1);
}
