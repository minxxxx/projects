/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 15:39:35 by oexall            #+#    #+#             */
/*   Updated: 2016/08/25 10:32:43 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		intersect_ray_plane(t_ray *ray, t_plane *pla, double *t5)
{
	double	p1;
	double	p2;
	double	t;

	if ((p2 = vector_dot(ray->dir, pla->rot)) == 0)
		return (0);
	p1 = vector_dot(pla->shape.pos, pla->rot) -
		vector_dot(ray->start, pla->rot);
	t = p1 / p2;
	if (t > EPSILON)
	{
		*t5 = t;
		return (1);
	}
	return (0);
}

void	gi_plane(t_env *env, t_ray *ray, double *t)
{
	int			i;
	double		t5;

	i = -1;
	t5 = *t;
	OBJ.cur_plane = -1;
	while (++i < OBJ.num_planes)
		if (intersect_ray_plane(ray, &OBJ.planes[i], &t5))
		{
			if (t5 < *t)
			{
				*t = t5;
				OBJ.cur_plane = i;
				OBJ.cur_cone = -1;
				OBJ.cur_sphere = -1;
				OBJ.cur_tri = -1;
				OBJ.cur_cyl = -1;
			}
		}
}
