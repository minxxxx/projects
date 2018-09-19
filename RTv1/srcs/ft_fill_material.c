/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 08:42:14 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:51:59 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		ft_get_value(char *line)
{
	int	tmp;

	tmp = 0;
	if (ft_strchr(line, ':') != NULL)
		tmp = ft_atoi(&ft_strchr(line, ':')[1]);
	return (tmp);
}

void	ft_init_material(t_material *mat)
{
	set_col(&mat->diffuse, 0, 0, 0);
	mat->reflection = 0;
	mat->specular = 0;
}

void	ft_fill_material(int fd, t_env *env)
{
	int		r;
	int		i;
	char	*line;

	i = (++env->count.mats);
	ft_init_material(&OBJ.mats[i]);
	r = 1;
	while (r && get_next_line(fd, &line))
	{
		if (*line == '#')
			r = 1;
		else if (ft_strchr(line, 'R') != NULL)
			OBJ.mats[i].diffuse.r = (ft_get_value(line) * 1.0f) / 255;
		else if (ft_strchr(line, 'G') != NULL)
			OBJ.mats[i].diffuse.g = (ft_get_value(line) / 1.0f) / 255;
		else if (ft_strchr(line, 'B') != NULL)
			OBJ.mats[i].diffuse.b = (ft_get_value(line) / 1.0f) / 255;
		else if (ft_strchr(line, 'S') != NULL)
			OBJ.mats[i].specular = (ft_get_value(line) * 1.0f) / 10.0f;
		else if (ft_strchr(line, '*') != NULL)
			OBJ.mats[i].reflection = (ft_get_value(line) * 1.0f) / 10.0f;
		else
			r = 0;
		free(line);
	}
}
