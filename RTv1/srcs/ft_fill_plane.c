/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:54:52 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:56:52 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_new_plane(t_plane *plane)
{
	plane->shape.pos = (t_vector){0, 0, 0};
	plane->rot = (t_vector){0, 0, 0};
	plane->shape.material = 0;
}

int		ft_get_plane(t_env *env, char *line, int i)
{
	if (*line == '#')
		return (1);
	else if (ft_strchr(line, 'P'))
		OBJ.planes[i].shape.pos = ft_get_vector(line);
	else if (ft_strchr(line, 'R'))
		OBJ.planes[i].rot = vector_unit(ft_get_vector(line));
	else if (ft_strchr(line, 'M'))
		OBJ.planes[i].shape.material = ft_atoi(&ft_strchr(line, ':')[1]);
	else
		return (0);
	return (1);
}

void	ft_fill_plane(int fd, t_env *env)
{
	int		r;
	int		i;
	char	*line;

	r = 1;
	i = (++env->count.planes);
	ft_new_plane(&OBJ.planes[i]);
	while (r && get_next_line(fd, &line))
	{
		r = ft_get_plane(env, line, i);
		free(line);
	}
	if (ft_val_mat(env, OBJ.planes[i].shape.material, "PLANE") == -1)
		exit(-1);
}
