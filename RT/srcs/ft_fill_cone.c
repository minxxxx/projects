/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:14:57 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:55:43 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_new_cone(t_cone *c)
{
	c->rot = (t_vector){0.0F, 0.0F, 0.0F};
	c->p = (t_vector){0.0F, 0.0F, 0.0F};
	c->v = (t_vector){0.0F, 0.0F, 0.0F};
	c->scale = 42.0F;
	c->alpha = 0;
	c->shape.material = 0;
	c->inf = 1;
	c->type = 1;
}

void	ft_rot_cone(t_env *env, int i)
{
	rotate_vec_x(CONES[i].rot.x, &CONES[i].v);
	rotate_vec_y(CONES[i].rot.y, &CONES[i].v);
	rotate_vec_z(CONES[i].rot.z, &CONES[i].v);
	CONES[i].shape.pos = CONES[i].p;
}

int		ft_input_cone(int c, t_env *env, char *line)
{
	if (*line == '#')
		return (1);
	else if (ft_strchr(line, 'R'))
		CONES[c].rot = ft_get_vector(line);
	else if (ft_strchr(line, 'P'))
		CONES[c].p = ft_get_vector(line);
	else if (ft_strchr(line, 'V'))
		CONES[c].v = ft_get_vector(line);
	else if (ft_strchr(line, 'A'))
		CONES[c].alpha =
			((double)ft_atoi(&ft_strchr(line, ':')[1]) * M_PI) / 180;
	else if (ft_strchr(line, 'S'))
	{
		CONES[c].scale = (double)ft_atoi(&ft_strchr(line, ':')[1]);
		CONES[c].inf = 0;
	}
	else if (ft_strchr(line, 'T'))
		CONES[c].type = (ft_atoi(&ft_strchr(line, ':')[1]) == 1);
	else if (ft_strchr(line, 'M'))
		CONES[c].shape.material = ft_atoi(&ft_strchr(line, ':')[1]);
	else
		return (0);
	return (1);
}

void	ft_fill_cone(int fd, t_env *env)
{
	int		i;
	int		r;
	char	*line;

	r = 1;
	i = (++env->count.cones);
	ft_new_cone(&CONES[i]);
	while (r && get_next_line(fd, &line))
	{
		r = ft_input_cone(i, env, line);
		free(line);
	}
	vector_norm(&CONES[i].v);
	ft_rot_cone(env, i);
	if (ft_val_mat(env, CONES[i].shape.material, "Cone") == -1)
		exit(0);
}
