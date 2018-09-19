/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:43:07 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:53:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	ft_get_vector(char *line)
{
	t_vector	tmp;

	if (ft_strchr(line, 'x'))
		tmp.x = ft_atoi(&ft_strchr(line, 'x')[1]) * 1.0f;
	if (ft_strchr(line, 'y'))
		tmp.y = ft_atoi(&ft_strchr(line, 'y')[1]) * 1.0f;
	if (ft_strchr(line, 'z'))
		tmp.z = ft_atoi(&ft_strchr(line, 'z')[1]) * 1.0f;
	return (tmp);
}

void		ft_new_cam(t_env *env)
{
	CAM.rot = (t_vector){0.0F, 0.0F, 0.0F};
	CAM.pos = (t_vector){0.0F, 0.0F, 0.0F};
	CAM.dir = (t_vector){0.0F, 0.0F, 0.0F};
	CAM.v_up = (t_vector){0.0F, 0.0F, 0.0F};
}

void		ft_init_cam(t_env *env, t_vector rot, int r)
{
	t_vector	drot;

	CAM.d = 1.0F;
	CAM.h = tan(env->fov / 2) / CAM.d;
	CAM.w = CAM.h * ((double)WIN_X / (double)WIN_Y);
	if (r)
	{
		drot = vector_sub(CAM.dir, CAM.pos);
		rotate_vec_x(rot.x, &drot);
		rotate_vec_y(rot.y, &drot);
		rotate_vec_z(rot.z, &drot);
		CAM.dir = vector_unit(drot);
	}
	CAM.n = vector_unit(vector_sub((t_vector){0.0F, 0.0F, 0.0F}, CAM.dir));
	CAM.u = vector_unit(vector_cross(CAM.v_up, CAM.n));
	CAM.v = vector_cross(CAM.n, CAM.u);
	CAM.c = vector_sub(CAM.pos, vector_scale(CAM.d, CAM.n));
	CAM.l = vector_sub(CAM.c, vector_scale(CAM.w / 2.0, CAM.u));
	CAM.l = vector_add(CAM.l, vector_scale(CAM.h / 2.0, CAM.v));
}

void		ft_fill_camera(int fd, t_env *env)
{
	int		r;
	char	*line;

	r = 1;
	ft_new_cam(env);
	while (r && get_next_line(fd, &line))
	{
		if (*line == '#')
			r = 1;
		else if (ft_strchr(line, 'R') != NULL)
			CAM.rot = ft_get_vector(line);
		else if (ft_strchr(line, 'D') != NULL)
			CAM.dir = ft_get_vector(line);
		else if (ft_strchr(line, 'P') != NULL)
			CAM.pos = ft_get_vector(line);
		else if (ft_strchr(line, 'U') != NULL)
			CAM.v_up = ft_get_vector(line);
		else
			r = 0;
		free(line);
	}
	OBJ.cam_rot = (t_vector){0.0F, 0.0F, 0.0F};
}
