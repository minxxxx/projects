/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:50:58 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:54:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_new_light(t_light *light)
{
	light->pos = (t_vector){0, 0, 0};
	light->intensity = (t_col){0, 0, 0};
}

void	ft_fill_light(int fd, t_env *env)
{
	int		r;
	int		i;
	char	*line;

	i = (++env->count.lights);
	ft_new_light(&OBJ.lights[i]);
	r = 1;
	while (r && get_next_line(fd, &line) && i < OBJ.num_lights)
	{
		if (*line == '#')
			r = 1;
		else if (ft_strchr(line, 'P'))
			OBJ.lights[i].pos = ft_get_vector(line);
		else if (ft_strchr(line, 'R'))
			LIGHTS[i].intensity.r = ft_atoi(&ft_strchr(line, ':')[1]) / 255.0f;
		else if (ft_strchr(line, 'G'))
			LIGHTS[i].intensity.g = ft_atoi(&ft_strchr(line, ':')[1]) / 255.0f;
		else if (ft_strchr(line, 'B'))
			LIGHTS[i].intensity.b = ft_atoi(&ft_strchr(line, ':')[1]) / 255.0f;
		else
			r = 0;
		free(line);
	}
}
