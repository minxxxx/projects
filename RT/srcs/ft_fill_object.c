/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 06:59:08 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:57:40 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_init_object(t_object *obj)
{
	obj->path = NULL;
	obj->pos = (t_vector){0, 0, 0};
	obj->rot = (t_vector){0, 0, 0};
	obj->scale = 1;
	obj->material = 0;
	obj->num_vecs = 0;
	obj->vectors = NULL;
	obj->num_norms = 0;
	obj->normals = NULL;
	obj->num_faces = 0;
	obj->faces = NULL;
}

int			ft_get_obj(char *line, t_env *env, int i)
{
	if (*line == '#')
		return (1);
	else if (ft_strchr(line, 'F'))
		OBJ.objects[i].path = ft_strdup(&ft_strchr(line, ':')[1]);
	else if (ft_strchr(line, 'P'))
		OBJ.objects[i].pos = ft_get_vector(line);
	else if (ft_strchr(line, 'R'))
		OBJ.objects[i].rot = vector_unit(ft_get_vector(line));
	else if (ft_strchr(line, 'M'))
		OBJ.objects[i].material = ft_atoi(&ft_strchr(line, ':')[1]);
	else if (ft_strchr(line, 'S') && ft_strchr(line, ':'))
		OBJ.objects[i].scale = ft_atod(&ft_strchr(line, ':')[1]);
	else
		return (0);
	return (1);
}

void		ft_fill_object(int fd, t_env *env)
{
	int		r;
	int		i;
	char	*line;

	i = (++env->count.objects);
	ft_init_object(&OBJ.objects[i]);
	r = 1;
	while (r && get_next_line(fd, &line))
	{
		r = ft_get_obj(line, env, i);
		free(line);
	}
	if (ft_val_mat(env, OBJ.objects[i].material, "OBJECT") == -1)
		exit(-1);
	read_obj(&OBJ.objects[i]);
}
