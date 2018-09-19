/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 08:57:43 by ggroener          #+#    #+#             */
/*   Updated: 2016/08/28 08:58:57 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_vector	ft_obj_vector(char *line)
{
	t_vector	vec;
	char		*tmp;

	vec = (t_vector){0, 0, 0};
	tmp = ft_strchr(line, ' ');
	vec.x = ft_atod(tmp);
	tmp = ft_strchr(&tmp[1], ' ');
	vec.y = ft_atod(tmp);
	tmp = ft_strchr(&tmp[1], ' ');
	vec.z = ft_atod(tmp);
	return (vec);
}

void		create_obj_arrays(t_object *obj)
{
	obj->vectors = (t_vector *)malloc(sizeof(t_vector) * obj->num_vecs);
	obj->normals = (t_vector *)malloc(sizeof(t_vector) * obj->num_norms);
	obj->faces = (t_triangle *)malloc(sizeof(t_triangle) * obj->num_faces);
	obj->count.vecs = -1;
	obj->count.norms = -1;
	obj->count.faces = -1;
}

t_triangle	ft_face(char *line, t_object *obj)
{
	t_triangle	triangle;
	char		*tmp;

	tmp = ft_strchr(line, ' ');
	triangle.v1 = obj->vectors[ft_atoi(tmp) - 1];
	tmp = ft_strchr(&tmp[1], '/');
	while (*tmp == '/')
		tmp++;
	triangle.normal = obj->normals[ft_atoi(tmp) - 1];
	tmp = ft_strchr(tmp, ' ');
	triangle.v2 = obj->vectors[ft_atoi(tmp) - 1];
	tmp = ft_strchr(&tmp[1], '/');
	while (*tmp == '/')
		tmp++;
	tmp = ft_strchr(tmp, ' ');
	triangle.v3 = obj->vectors[ft_atoi(tmp) - 1];
	tmp = ft_strchr(&tmp[1], '/');
	while (*tmp == '/')
		tmp++;
	return (triangle);
}

void		read_obj(t_object *obj)
{
	int		fd;
	char	*line;

	if (obj->path == NULL)
		exit(-1);
	ft_obj_vec_count(obj);
	create_obj_arrays(obj);
	if ((fd = open(ft_trim(obj->path), O_RDONLY)) == -1)
		exit(-1);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'v' && line[1] == ' ')
			obj->vectors[(++obj->count.vecs)] = ft_obj_vector(line);
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
			obj->normals[(++obj->count.norms)] = ft_obj_vector(line);
		else if (line[0] == 'f' && line[1] == ' ')
			obj->faces[(++obj->count.faces)] = ft_face(line, obj);
		free(line);
	}
	close(fd);
	manipulate_object(obj);
}
