/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 06:56:36 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 08:50:37 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_init_arrays(t_env *env)
{
	OBJ.mats = (t_material *)malloc(sizeof(t_material) * OBJ.num_mats);
	OBJ.lights = (t_light *)malloc(sizeof(t_light) * OBJ.num_lights);
	OBJ.spheres = (t_sphere *)malloc(sizeof(t_sphere) * OBJ.num_spheres);
	OBJ.triangles = (t_triangle *)malloc(sizeof(t_triangle) * OBJ.num_tri);
	OBJ.cylinders = (t_cylinder *)malloc(sizeof(t_cylinder) * OBJ.num_cyl);
	OBJ.cones = (t_cone *)malloc(sizeof(t_cone) * OBJ.num_cone);
	OBJ.planes = (t_plane *)malloc(sizeof(t_plane) * OBJ.num_planes);
	OBJ.objects = (t_object *)malloc(sizeof(t_object) * OBJ.num_objects);
}

void	ft_init_env(t_env *env)
{
	env->ambient_level = 0;
	env->ref_level = 0;
	env->fov = 59.324377 * M_PI / 180;
	env->sampling_level = 1;
	OBJ.num_mats = 0;
	OBJ.num_lights = 0;
	OBJ.num_spheres = 0;
	OBJ.num_tri = 0;
	OBJ.num_cyl = 0;
	OBJ.num_cone = 0;
	OBJ.num_planes = 0;
	OBJ.num_objects = 0;
	env->count.mats = -1;
	env->count.lights = -1;
	env->count.spheres = -1;
	env->count.triangles = -1;
	env->count.cylinders = -1;
	env->count.cones = -1;
	env->count.planes = -1;
	env->count.objects = -1;
}

void	ft_check_objects(int fd, t_env *env, char *line)
{
	if (ft_strncmp(line, "MATERIAL", 8) == 0)
		ft_fill_material(fd, env);
	else if (ft_strncmp(line, "LIGHT", 5) == 0)
		ft_fill_light(fd, env);
	else if (ft_strncmp(line, "SPHERE", 6) == 0)
		ft_fill_sphere(fd, env);
	else if (ft_strncmp(line, "TRIANGLE", 8) == 0)
		ft_fill_triangle(fd, env);
	else if (ft_strncmp(line, "CONE", 4) == 0)
		ft_fill_cone(fd, env);
	else if (ft_strncmp(line, "CYLINDER", 8) == 0)
		ft_fill_cylinder(fd, env);
	else if (ft_strncmp(line, "PLANE", 5) == 0)
		ft_fill_plane(fd, env);
	else if (ft_strncmp(line, "OBJECT", 6) == 0)
		ft_fill_object(fd, env);
}

void	ft_check_setup(int fd, t_env *env, char *line)
{
	if (ft_strncmp(line, "CAMERA", 6) == 0)
		ft_fill_camera(fd, env);
	else if (ft_strncmp(line, "REFLECTION", 10) == 0 && ft_strchr(line, ':'))
		env->ref_level = ft_atoi(&ft_strchr(line, ':')[1]);
	else if (ft_strncmp(line, "AMBIENT", 7) == 0 && ft_strchr(line, ':'))
		env->ambient_level = (ft_atoi(&ft_strchr(line, ':')[1]) * 1.0f) / 100;
	else if (ft_strncmp(line, "FOV", 3) == 0 && ft_strchr(line, ':'))
	{
		env->fov = ft_atod(&ft_strchr(line, ':')[1]);
		env->fov *= M_PI / 180;
	}
	else if (ft_strncmp(line, "SAMPLING", 8) == 0 && ft_strchr(line, ':'))
		env->sampling_level = ft_atoi(&ft_strchr(line, ':')[1]);
	else
		ft_check_objects(fd, env, line);
}

void	ft_get_input(t_env *env, char *file)
{
	int		fd;
	char	*line;

	ft_init_env(env);
	ft_count_objs(env, file);
	ft_init_arrays(env);
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(-1);
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			ft_input_error("Reading", "Invalid File");
		if (line && *line != '#' && ft_strlen(line) > 0)
			ft_check_setup(fd, env, line);
		free(line);
	}
	close(fd);
	if (env->sampling_level <= 0)
		ft_input_error("Reading", "Sampling level must be >= 1");
	if (env->fov > 90 | env->fov < 0)
		ft_input_error("Reading", "FOV must be between 1 and 90");
	ft_init_cam(env, CAM.rot, 1);
}
