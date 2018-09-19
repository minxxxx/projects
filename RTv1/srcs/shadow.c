/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:19:55 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/22 15:34:26 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		sh_spheres(t_env *env, t_ray *light_ray, double t)
{
	int	k;

	k = 0;
	while (k < env->obj.num_spheres)
	{
		if (intersect_ray_sphere(light_ray, &OBJ.spheres[k], &t))
			return (1);
		k++;
	}
	return (0);
}

int		sh_tri(t_env *env, t_ray *light_ray, double t)
{
	int			k;

	k = 0;
	while (k < env->obj.num_tri)
	{
		if (intersect_ray_tri(light_ray, &TRI[k], &t))
			return (1);
		k++;
	}
	return (0);
}

int		sh_cylinder(t_env *env, t_ray *light_ray, double t)
{
	int			k;

	k = 0;
	while (k < env->obj.num_cyl)
	{
		if (intersect_ray_cylinder(light_ray, &CYLINDERS[k], &t))
			return (1);
		k++;
	}
	return (0);
}

int		sh_cone(t_env *env, t_ray *light_ray, double t)
{
	int			k;

	k = 0;
	while (k < env->obj.num_cone)
	{
		if (intersect_ray_cone(light_ray, &CONES[k], &t))
			return (1);
		k++;
	}
	return (0);
}

int		sh_obj(t_env *env, t_ray *light_ray, double t)
{
	int			k;
	int			j;

	k = 0;
	while (k < OBJ.num_objects)
	{
		j = -1;
		while (++j < OBJ.objects[k].num_faces)
			if (intersect_ray_tri(light_ray, &OBJ.objects[k].faces[j], &t))
				return (1);
		k++;
	}
	return (0);
}
