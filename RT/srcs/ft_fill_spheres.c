/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_spheres.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:41:54 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:54:35 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_new_sphere(t_sphere *sphere)
{
	sphere->shape.pos = (t_vector){0, 0, 0};
	sphere->shape.dist = 0;
	sphere->shape.material = 0;
	sphere->radius = 0;
}

void	ft_fill_sphere(int fd, t_env *env)
{
	int		r;
	int		i;
	char	*line;

	r = 1;
	i = (++env->count.spheres);
	ft_new_sphere(&OBJ.spheres[i]);
	while (r && i < OBJ.num_spheres && get_next_line(fd, &line))
	{
		if (*line == '#')
			r = 1;
		else if (ft_strchr(line, 'P'))
			SPHERES[i].shape.pos = ft_get_vector(line);
		else if (ft_strchr(line, 'R'))
			SPHERES[i].radius = ft_atoi(&ft_strchr(line, ':')[1]);
		else if (ft_strchr(line, 'M'))
			SPHERES[i].shape.material = ft_atoi(&ft_strchr(line, ':')[1]);
		else
			r = 0;
		free(line);
	}
	if (ft_val_mat(env, SPHERES[i].shape.material, "Light") == -1)
		exit(-1);
}
