/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 06:55:54 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/16 16:31:36 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	size_err(t_cor player)
{
	if (player.size > CHAMP_MAX_SIZE)
	{
		ft_putstr_fd(player.name, 2);
		ft_putstr_fd(" is too large\n", 2);
		exit(-1);
	}
}

void	read_target(int fd, t_cor player, char *buf, size_t n_byte)
{
	size_t	r_bytes;

	r_bytes = read(fd, buf, n_byte);
	if (r_bytes != n_byte)
	{
		ft_printf("target = %d read = %d\n", n_byte, r_bytes);
		ft_putstr_fd(player.file, 2);
		ft_putstr_fd(" is not a valid corewar executable\n", 2);
		exit(-1);
	}
}

void	do_magic(int fd, t_cor player)
{
	void			*buf;
	unsigned int	num;

	buf = malloc(4);
	read(fd, buf, 4);
	reverse_bytes(buf, 4);
	num = *(int*)buf;
	if (num != COREWAR_EXEC_MAGIC)
	{
		ft_putstr_fd(player.file, 2);
		ft_putstr_fd("is not a valid corewar executable\n", 2);
		exit(-1);
	}
	ft_memdel((void**)&buf);
}

int		file_size(char *file_name)
{
	int		i;
	int		fd;
	int		bytes_read;
	char	buf[COUNT_BUF];

	i = 0;
	bytes_read = 1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File read error occured.\n", 2);
		exit(-1);
	}
	while (bytes_read)
	{
		bytes_read = read(fd, buf, COUNT_BUF);
		i += bytes_read;
	}
	close(fd);
	return (i);
}

void	load_programs(t_env *env)
{
	int		i;
	int		fd;
	char	temp_int[4];

	i = -1;
	while (++i < env->p_count)
	{
		PLAYER(i).file_size = file_size(PLAYER(i).file);
		fd = open(PLAYER(i).file, O_RDONLY);
		do_magic(fd, PLAYER(i));
		PLAYER(i).name = (char*)malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
		PLAYER(i).comment = (char*)malloc(sizeof(char) * COMMENT_LENGTH + 1);
		read_target(fd, PLAYER(i), PLAYER(i).name, PROG_NAME_LENGTH + 1);
		lseek(fd, 4 - ((PROG_NAME_LENGTH + 1) % 4), SEEK_CUR);
		read_target(fd, PLAYER(i), temp_int, sizeof(int));
		PLAYER(i).size = read_int(temp_int);
		read_target(fd, PLAYER(i), PLAYER(i).comment, COMMENT_LENGTH + 1);
		lseek(fd, 4 - ((COMMENT_LENGTH + 1) % 4), SEEK_CUR);
		PLAYER(i).instructions = (char*)malloc(sizeof(char) * PLAYER(i).size);
		read_target(fd, PLAYER(i), PLAYER(i).instructions, PLAYER(i).size);
		size_err(PLAYER(i));
		PLAYER(i).name[PROG_NAME_LENGTH] = '\0';
		PLAYER(i).comment[COMMENT_LENGTH] = '\0';
	}
}
