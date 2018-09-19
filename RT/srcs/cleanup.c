/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 10:13:49 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/29 10:14:02 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	cleanup3(t_env *env)
{
	int	i;

	i = 0;
	if (OBJ.planes && OBJ.num_planes >= 1)
	{
		free(OBJ.planes);
		OBJ.num_planes = 0;
	}
	if (OBJ.objects && OBJ.num_objects >= 1)
	{
		while (i < OBJ.num_objects)
		{
			free(OBJ.objects[i].vectors);
			free(OBJ.objects[i].normals);
			free(OBJ.objects[i].faces);
			free(OBJ.objects[i].path);
			i++;
		}
		free(OBJ.objects);
		OBJ.num_objects = 0;
	}
}

void	cleanup2(t_env *env)
{
	if (OBJ.triangles && OBJ.num_tri >= 1)
	{
		free(OBJ.triangles);
		OBJ.num_tri = 0;
	}
	if (OBJ.cylinders && OBJ.num_cyl >= 1)
	{
		free(OBJ.cylinders);
		OBJ.num_cyl = 0;
	}
	if (OBJ.cones && OBJ.num_cone >= 1)
	{
		free(OBJ.cones);
		OBJ.num_cone = 0;
	}
}

void	cleanup(t_env *env)
{
	if (OBJ.mats && OBJ.num_mats >= 1)
	{
		free(OBJ.mats);
		OBJ.num_mats = 0;
	}
	if (OBJ.lights && OBJ.num_lights >= 1)
	{
		free(OBJ.lights);
		OBJ.num_lights = 0;
	}
	if (OBJ.spheres && OBJ.num_spheres >= 1)
	{
		free(OBJ.spheres);
		OBJ.num_spheres = 0;
	}
	cleanup2(env);
	cleanup3(env);
}
