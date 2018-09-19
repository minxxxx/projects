/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:45:44 by hrossouw          #+#    #+#             */
/*   Updated: 2018/03/04 12:17:33 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void	disp_file(int fd)
{
	char	buf;

	while (read(fd, &buf, 1) > 0)
	{
		write(1, &buf, 1);
	}
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDWR);
	if (argc == 2)
	{
		disp_file(fd);
		close(fd);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
	}
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
	}
	return (0);
}
