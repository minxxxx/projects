/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 07:09:37 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 10:58:50 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	ft_count_1(t_env *env, char *line)
{
	if (ft_strncmp(line, "MATERIAL", 8) == 0)
		OBJ.num_mats += 1;
	else if (ft_strncmp(line, "LIGHT", 5) == 0)
		OBJ.num_lights += 1;
	else if (ft_strncmp(line, "SPHERE", 6) == 0)
		OBJ.num_spheres += 1;
	else if (ft_strncmp(line, "TRIANGLE", 8) == 0)
		OBJ.num_tri += 1;
	else if (ft_strncmp(line, "CYLINDER", 8) == 0)
		OBJ.num_cyl += 1;
	else if (ft_strncmp(line, "CONE", 4) == 0)
		OBJ.num_cone += 1;
	else if (ft_strncmp(line, "PLANE", 5) == 0)
		OBJ.num_planes += 1;
	else if (ft_strncmp(line, "OBJECT", 6) == 0)
		OBJ.num_objects += 1;
}

void		ft_count_objs(t_env *env, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_input_error("Reading", "Invalid File");
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			ft_input_error("Reading", "Invalid File");
		if (*line != '#' && ft_strlen(line) > 0)
			ft_count_1(env, line);
		free(line);
	}
	close(fd);
}
