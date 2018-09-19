/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:14:54 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 09:14:57 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	get_map_width(char *file)
{
	int		max_width;
	int		width;
	int		i;

	i = 0;
	width = 0;
	max_width = -1;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (max_width == -1)
				max_width = width;
			else if (width != max_width)
				return (-1);
			width = 0;
		}
		else
			width++;
		i++;
	}
	return (max_width);
}

static int	get_map_height(char *file)
{
	int		height;
	int		i;

	height = 0;
	i = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			height++;
		i++;
	}
	if (i > 0 && file[i - 1] != '\n')
		return (-1);
	return (height);
}

static void	map_parse(t_map *map, char *file)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	x = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
		{
			if (file[i] != '#' && file[i] != ' ' && file[i] != '1')
				error_quit("Invalid file");
			map->data[y][x] = file[i];
			x++;
		}
		i++;
	}
}

void		map_load(t_map *map, char *file)
{
	char	*file_content;
	int		y;

	if (!(file_content = get_file_content(file)))
		error_quit("Failed to load map file");
	if ((map->width = get_map_width(file_content)) <= 1)
		error_quit("Invalid map (bad width)");
	if ((map->height = get_map_height(file_content)) <= 1)
		error_quit("Invalid map (bad height)");
	if (!(map->data = malloc(sizeof(*map->data) * map->height)))
		error_quit("Failed to malloc map");
	y = 0;
	while (y < map->height)
	{
		if (!(map->data[y] = malloc(sizeof(**map->data) * map->width)))
			error_quit("Failed to malloc map");
		y++;
	}
	map_parse(map, file_content);
	free(file_content);
}
