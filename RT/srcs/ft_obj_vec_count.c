/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_vec_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 09:44:57 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 09:13:33 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char		*ft_trim(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
		str++;
	end = str + ft_strlen(str) - 1;
	while (*end == ' ' || *end == '\t')
		end--;
	*(end + 1) = '\0';
	return (str);
}

static void	ft_count_vec(char *line, t_object *obj)
{
	if (line[0] == 'v' && line[1] == ' ')
		obj->num_vecs += 1;
	else if (line[0] == 'v' && line[1] == 'n')
		obj->num_norms += 1;
	else if (line[0] == 'f' && line[1] == ' ')
		obj->num_faces += 1;
}

void		ft_obj_vec_count(t_object *obj)
{
	int		fd;
	char	*line;

	if ((fd = open(ft_trim(obj->path), O_RDONLY)) == -1)
		exit(-1);
	while (get_next_line(fd, &line))
	{
		ft_count_vec(line, obj);
		free(line);
	}
	close(fd);
}
