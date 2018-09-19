/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:33:23 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:17:24 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***map_arr(char *map)
{
	char	***map_arr;
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	map_arr = memalloc_arr(map);
	while (get_next_line(fd, &buffer))
	{
		map_arr[i] = ft_strsplit(buffer, ' ');
		i++;
	}
	map_arr[i] = NULL;
	close(fd);
	return (map_arr);
}
