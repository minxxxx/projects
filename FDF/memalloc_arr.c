/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:39:49 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 07:02:29 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***memalloc_arr(char *file)
{
	int		i;
	int		fd;
	char	*buffer;
	char	***arr;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &buffer))
		i++;
	arr = (char ***)malloc(sizeof(char *) * i + 1);
	return (arr);
}
