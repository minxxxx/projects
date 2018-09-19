/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 16:23:30 by oexall            #+#    #+#             */
/*   Updated: 2016/08/26 16:54:51 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	rotate(t_vector rot, t_triangle *tri)
{
	rotate_vec_x(rot.x, &tri->v1);
	rotate_vec_y(rot.y, &tri->v1);
	rotate_vec_z(rot.z, &tri->v1);
	rotate_vec_x(rot.x, &tri->v2);
	rotate_vec_y(rot.y, &tri->v2);
	rotate_vec_z(rot.z, &tri->v2);
	rotate_vec_x(rot.x, &tri->v3);
	rotate_vec_y(rot.y, &tri->v3);
	rotate_vec_z(rot.z, &tri->v3);
}

static void	scale(double scale, t_triangle *tri)
{
	tri->v1 = vector_scale(scale, tri->v1);
	tri->v2 = vector_scale(scale, tri->v2);
	tri->v3 = vector_scale(scale, tri->v3);
}

static void	add(t_vector pos, t_triangle *tri)
{
	tri->v1 = vector_add(pos, tri->v1);
	tri->v2 = vector_add(pos, tri->v2);
	tri->v3 = vector_add(pos, tri->v3);
}

void		manipulate_object(t_object *obj)
{
	int	i;

	printf("MANIPULATION\n");
	i = -1;
	while (++i < obj->num_faces)
	{
		rotate(obj->rot, &obj->faces[i]);
		if (obj->scale > 0.0F)
			scale(obj->scale, &obj->faces[i]);
		add(obj->pos, &obj->faces[i]);
	}
}
