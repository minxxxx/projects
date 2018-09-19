/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 06:49:19 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:55:03 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_new_triangle(t_triangle *tri)
{
	tri->v1 = (t_vector){0, 0, 0};
	tri->v2 = (t_vector){0, 0, 0};
	tri->v3 = (t_vector){0, 0, 0};
	tri->rot = (t_vector){0, 0, 0};
	tri->shape.material = 0;
}

int		ft_input(t_env *env, int i, char *line)
{
	if (*line == '#')
		return (1);
	else if (ft_strstr(line, "v1") != NULL)
		TRI[i].v1 = ft_get_vector(line);
	else if (ft_strstr(line, "v2") != NULL)
		TRI[i].v2 = ft_get_vector(line);
	else if (ft_strstr(line, "v3") != NULL)
		TRI[i].v3 = ft_get_vector(line);
	else if (ft_strchr(line, 'R') != NULL)
		TRI[i].rot = ft_get_vector(line);
	else if (ft_strchr(line, 'M') != NULL)
		TRI[i].shape.material = ft_atoi(&ft_strchr(line, ':')[1]);
	else
		return (0);
	return (1);
}

void	ft_fill_triangle(int fd, t_env *env)
{
	int		i;
	int		r;
	char	*line;

	r = 1;
	i = (++env->count.triangles);
	ft_new_triangle(&TRI[i]);
	while (r && get_next_line(fd, &line))
	{
		r = ft_input(env, i, line);
		free(line);
	}
	rotate_tri(&TRI[i]);
	TRI[i].normal = get_tri_normal(&TRI[i]);
	if (ft_val_mat(env, TRI[i].shape.material, "Triangle") == -1)
		exit(-1);
}
