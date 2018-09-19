/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:54:45 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:56:24 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_new_cylinder(t_cylinder *cyl)
{
	cyl->rot = (t_vector){0, 0, 0};
	cyl->p = (t_vector){0, 0, 0};
	cyl->v = (t_vector){0, 0, 0};
	cyl->lim = (t_vector){0, 0, 0};
	cyl->radius = 0;
	cyl->shape.material = 0;
	cyl->inf = 1;
	cyl->scale = 42;
}

void	ft_rot_cyl(t_env *env, int i)
{
	rotate_vec_x(CYLINDERS[i].rot.x, &CYLINDERS[i].v);
	rotate_vec_x(CYLINDERS[i].rot.x, &CYLINDERS[i].p);
	rotate_vec_y(CYLINDERS[i].rot.y, &CYLINDERS[i].v);
	rotate_vec_y(CYLINDERS[i].rot.y, &CYLINDERS[i].p);
	rotate_vec_z(CYLINDERS[i].rot.z, &CYLINDERS[i].v);
	rotate_vec_z(CYLINDERS[i].rot.x, &CYLINDERS[i].p);
	vector_norm(&CYLINDERS[i].v);
	CYLINDERS[i].shape.pos = CYLINDERS[i].p;
}

int		ft_input_cyl(int i, t_env *env, char *line)
{
	if (*line == '#')
		return (1);
	else if (ft_strchr(line, 'R'))
		CYLINDERS[i].rot = ft_get_vector(line);
	else if (ft_strchr(line, 'P'))
		CYLINDERS[i].p = ft_get_vector(line);
	else if (ft_strchr(line, 'V'))
		CYLINDERS[i].v = ft_get_vector(line);
	else if (ft_strchr(line, 'S'))
	{
		CYLINDERS[i].scale = (double)ft_atoi(&ft_strchr(line, ':')[1]);
		CYLINDERS[i].inf = 0;
	}
	else if (ft_strchr(line, 'r'))
		CYLINDERS[i].radius = ft_atoi(&ft_strchr(line, ':')[1]);
	else if (ft_strchr(line, 'M'))
		CYLINDERS[i].shape.material = ft_atoi(&ft_strchr(line, ':')[1]);
	else
		return (0);
	return (1);
}

void	ft_fill_cylinder(int fd, t_env *env)
{
	int		r;
	int		i;
	char	*line;

	r = 1;
	i = (++env->count.cylinders);
	ft_new_cylinder(&CYLINDERS[i]);
	while (r && get_next_line(fd, &line))
	{
		r = ft_input_cyl(i, env, line);
		free(line);
	}
	if (ft_val_mat(env, CYLINDERS[i].shape.material, "Cylinder") == -1)
		exit(0);
	ft_rot_cyl(env, i);
}
