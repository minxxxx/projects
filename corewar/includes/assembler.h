/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 08:13:56 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/27 11:38:18 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Corewar project by team Codamancers:
** daviwel, ddu-toit, ggroener, vivan-de
*/

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include <libft.h>
# include <corewar_vm.h>

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPERATOR_CHAR ','
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

# define INPUT info->input
# define LINE info->line_nbr

typedef struct	s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}				t_header;

typedef struct	s_command
{
	char		opcode;
	int			op_tab_index;
	char		**params;
	int			num_params;
	BOOL		dir_as_index;
	BOOL		has_encoding;
	char		encoding_byte;
	int			command_bytes;
	int			line_nbr;
}				t_command;

typedef struct	s_label
{
	char		*name;
	int			line;
}				t_label;

typedef struct	s_info
{
	char		**input;
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	char		*file_name;
	t_header	header;
	t_op		op_tab[OP_COUNT + 1];
	t_list		*commands;
	t_list		*labels;
	int			num_labels;
	int			line_nbr;
}				t_info;

typedef struct	s_file
{
	int		fd;
	int		i;
	int		padding;
}				t_file;

typedef struct	s_params
{
	int		i;
	int		k;
	int		temp_int;
	int		offset;
	char	temp_char;
}				t_params;

void			free_commands(t_command *com);

void			free_input(t_info *info);

int				count_bytes_between(t_info *info, int com_line, int label_line);

int				find_label_line(t_info *info, char *name);

void			write_commands(t_info *info, int fd);

t_arg_type		return_param_type(char *param);

int				get_param_bytes(char **params, int num, t_command *nc,
		t_info *info);

int				check_param(char *param);

char			get_encoding_byte(char **params, int num, int op_index,
		t_info *info);

int				count_arr(char **arr);

t_list			*create_command(char *params, int *index, t_info *info);

char			*str_trim(char *str);

char			*store_params(char *str, int *i);

int				check_command(char *com, t_info *info);

int				check_n_c(char *str);

int				get_command(t_info *info, char *str, int *i,
		int *found_command);

int				interpret_line(char *str, t_info *info, int i);

void			a_fill_op_tab(t_info *env);

void			a_fill_1(t_info *env);

void			a_fill_2(t_info *env);

void			a_fill_3(t_info *env);

void			a_fill_4(t_info *env);

void			a_fill_5(t_info *env);

void			a_fill_5_1(t_info *env);

t_label			*check_label(char *line, int i, int *valid_label, int line_nbr);

int				read_line(t_info *info, char *line, int line_nbr);

void			start_compile(t_info *info);

void			print_memory(const void *addr, size_t size);

void			write_file(t_info *info);

void			init_header(t_header *header, t_info *info);

void			start_compile(t_info *info);

int				error_check(int argc, char **argv);

void			store_input(t_info *info, char *name);

void			validate_input(t_info *info);

void			free_info_label(t_info *info);

void			check_nc(t_info *info);

#endif
