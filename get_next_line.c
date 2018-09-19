/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 10:55:52 by angonyam          #+#    #+#             */
/*   Updated: 2017/06/22 08:27:12 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "get_next_line.h"

static t_reading	*new_nd(int fd)
{
	t_reading *new;

	new = (t_reading*)ft_memalloc(sizeof(t_reading));
	new->fd = fd;
	return (new);
}

static t_reading	*ft_fd_finding(t_list **second, int fd)
{
	t_list		*storage;
	t_reading	*new;
	
	new = 0;
	storage = *second;
	while (storage)
	{
		new = (t_reading*)(storage->content);
		if (new->fd == fd)
			return (new);
		storage = storage->next;
	}
	ft_lstadd(second, ft_lstnew(new_nd(fd), sizeof(t_reading)));
	return ((t_reading*)((*second)->content));
}


static int				resetting(int fd, t_reading *kr, char **line)
{
	if (kr->p >= kr->size || kr->p == 0)
	{
		kr->p = 0;
		kr->size = read(fd, kr->buffer, BUFF_SIZE);
		if ((int)kr->size == -1)
			return (-1);
		if (kr->size == 0)
			return (**line ? 1 : 0);
	}
	return (2);
}

static int				looping(t_reading *kr, int fd, char **line)
{
	size_t	length;
	char	*n_line;
	int		r_line;
	char	*new;

	while (1)
	{
		if ((r_line = resetting(fd, kr, line)) != 2) 
			return (r_line);
		n_line = memchr(kr->buffer + kr->p, '\n', kr->size - kr->p);
		n_line = n_line ? n_line : kr->buffer + kr->size;
		length = (n_line - kr->buffer) - kr->p;
		new = ft_strnew(strlen(*line) + length);
		if (!new)
			return (-1);
		strcpy(new, *line);
		strlcat(new, kr->buffer + kr->p, strlen(*line) + length + 1);
		free(*line);
		*line = new;
		kr->p += length + 1;
		if (n_line != kr->buffer + kr->size || kr->size != BUFF_SIZE)
			return (1);
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*second = 0;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (!*line)
		return (-1);
	return (looping(ft_fd_finding(&second, fd), fd, line));
}

int				main(int argc, char **argv)
{
	int fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &str);
	ft_putstr(str);
	return(0);
}
