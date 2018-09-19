/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:50:01 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 10:06:34 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void		rev_write(int fd, int *temp, int size)
{
	reverse_bytes(temp, size);
	write(fd, temp, size);
}

void		handle_dir_params(t_info *info, t_command com, int fd, t_params *p)
{
	if (com.params[p->i][1] != LABEL_CHAR)
	{
		p->temp_int = ft_atoi(com.params[p->i] + 1);
		if (com.dir_as_index == TRUE)
			rev_write(fd, &p->temp_int, IND_SIZE);
		else
			rev_write(fd, &p->temp_int, DIR_SIZE);
	}
	else
	{
		if ((p->k = find_label_line(info, ft_strchr(com.params[p->i],
							LABEL_CHAR))) != -1)
		{
			p->offset = count_bytes_between(info, com.line_nbr, p->k);
			rev_write(fd, &p->offset, 2);
		}
		else
		{
			ft_putstr_fd("Error : Label not found\n", 2);
			exit(-1);
		}
	}
}

void		handle_params(t_info *info, t_command com, int fd)
{
	t_params	p;
	short		temp_short;

	p.i = 0;
	while (p.i < com.num_params)
	{
		if (com.params[p.i][0] == 'r')
		{
			p.temp_char = (char)ft_atoi(&com.params[p.i][1]);
			write(fd, &p.temp_char, sizeof(char));
		}
		else if (com.params[p.i][0] == DIRECT_CHAR)
			handle_dir_params(info, com, fd, &p);
		else
		{
			p.temp_int = ft_atoi(com.params[p.i]);
			temp_short = (short)p.temp_int;
			reverse_bytes(&temp_short, IND_SIZE);
			write(fd, &temp_short, IND_SIZE);
		}
		p.i++;
	}
}

/*
** Writes all the commands to the .cor file
*/

void		write_commands(t_info *info, int fd)
{
	t_list		*crawl;
	t_list		*temp;
	t_command	com;

	crawl = info->commands;
	while (crawl != NULL)
	{
		com = *((t_command *)crawl->data);
		write(fd, &com.opcode, sizeof(com.opcode));
		if (com.encoding_byte != '\0')
			write(fd, &com.encoding_byte, sizeof(com.encoding_byte));
		handle_params(info, com, fd);
		temp = crawl;
		crawl = crawl->next;
	}
	while (crawl != NULL)
	{
		free_commands((t_command *)crawl->data);
		free(temp);
	}
}
