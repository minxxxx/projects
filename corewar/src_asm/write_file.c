/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:21:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/27 11:00:59 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	add_null(int fd, int padding)
{
	while (padding % 4 != 0)
	{
		write(fd, "\0", 1);
		padding++;
	}
}

/*
** Writes the header to the .cor file and creates a new file
*/

void	add_cor(char *file_name, int *i)
{
	*i -= 1;
	file_name[*i += 1] = '.';
	file_name[*i += 1] = 'c';
	file_name[*i += 1] = 'o';
	file_name[*i += 1] = 'r';
	file_name[*i += 1] = '\0';
}

void	write_file(t_info *info)
{
	t_file	f;
	char	file_name[PROG_NAME_LENGTH + 5];

	f.i = -1;
	while (info->file_name[++f.i] != '.')
		file_name[f.i] = info->file_name[f.i];
	add_cor(&(*file_name), &f.i);
	reverse_bytes((void *)&info->header.magic, sizeof(info->header.magic));
	f.fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0666);
	f.padding = sizeof(info->header.magic);
	write(f.fd, &info->header.magic, sizeof(info->header.magic));
	add_null(f.fd, f.padding);
	f.padding = sizeof(info->header.prog_name);
	write(f.fd, &info->header.prog_name, sizeof(info->header.prog_name));
	add_null(f.fd, f.padding);
	f.padding = sizeof(info->header.prog_size);
	reverse_bytes((void *)&info->header.prog_size, sizeof(int));
	write(f.fd, &info->header.prog_size, sizeof(info->header.prog_size));
	add_null(f.fd, f.padding);
	f.padding = sizeof(info->header.comment);
	write(f.fd, &info->header.comment, sizeof(info->header.comment));
	add_null(f.fd, f.padding);
	write_commands(info, f.fd);
	close(f.fd);
}
