/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:35:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/31 10:55:59 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

# include "../libft/includes/libft.h"
# include <op.h>

# define ARG_DUMP(X) ft_strcmp("-dump", argv[X]) == 0
# define BOOL char
# define PLAYER(X) env->players[X]
# define P_CPU(X) env->players[X].cpu
# define P_REG(X, Y) env->players[X].cpu.registers[Y - 1]
# define OP_COUNT 16
# define OP(X) env->op_tab[X]
# define CUR_OP(X) env->players[X].cur_op
# define COUNT_BUF 64
# define HEAD_LEN PROG_NAME_LENGTH + COMMENT_LENGTH
# define INST_SIZE(X) PLAYER(X).file_size - (4 + HEAD_LEN)
# define NO_TYPE 0;
# define ALIVE(X) PLAYER(X).alive == 1
# define SHORT_MAX 32767
# define SHORT_MIN -32768

/*
** Opcodes in hex
*/

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR	0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x10

enum
{
	FALSE,
	TRUE
};

enum
{
	ER_ARGF = 1,
	ER_FILE,
	ER_NOTNUM,
	ER_DUPNUM,
	ER_MALLOC
};

/*
** Data structure for op_tab. n_byte and dir_as index indicates whether enoding
** byte is present and if T_DIR should be treated as an index (IND_SIZE)
*/

typedef struct		s_op_run
{
	int		op;
	int		to_exec;
	int		player;
	int		p_in;
	BOOL	reset;
	int		*arg_types;
	int		*arg_sizes;
	char	**arg;
	int		valid;
}					t_op_run;

typedef struct		s_op
{
	char			*name;
	char			nbr_args;
	char			type[MAX_ARGS_NUMBER];
	char			code;
	int				nbr_cycles;
	BOOL			n_byte;
	BOOL			dir_as_index;
}					t_op;

typedef struct		s_cpu
{
	char	*prog_start;
	char	*pc;
	void	**registers;
	int		carry;
}					t_cpu;

/*
** t_cor stores information of a player (.cor)
** lsc - amout of 'live' executions since last check
** last_live indicates how many cycles passed since last live
*/

typedef struct		s_cor
{
	char		*file;
	int			file_size;
	char		*name;
	char		*comment;
	char		*instructions;
	int			p_num;
	int			size;
	int			lsc;
	t_cpu		cpu;
	t_op_run	cur_op;
	BOOL		alive;
	int			last_live;
	BOOL		sub;
}					t_cor;

/*
** Environment
*/

typedef struct		s_env
{
	int		p_count;
	BOOL	dump;
	int		dump_cycles;
	t_cor	*players;
	char	*memory;
	int		cycle_to_die;
	int		checkups;
	t_op	op_tab[OP_COUNT + 1];
	int		last_live;
	int		live_calls;
	int		*alive_at_check;
}					t_env;

/*
** Input && error checks
*/

void				check_args(int argc, char **argv, t_env *env);

void				arg_err(int err, char *arg);

void				check_player_numbers(int argc, char **argv);

int					check_int(char *arg);

int					is_numeric(char *arg);

void				get_input(int argc, char **argv, t_env *env);

void				sort_players(t_env *env);

void				fill_op_tab(t_env *env);

void				fill_1(t_env *env);

void				fill_2(t_env *env);

void				fill_3(t_env *env);

void				fill_4(t_env *env);

void				fill_5(t_env *env);

void				load_programs(t_env *env);

void				reverse_bytes(void *mem, size_t size);

int					valid_type(int type);

/*
** Output functions
*/

void				print_all_ops(t_op op[OP_COUNT + 1]);

void				print_op(t_op op);

/*
**	initialize structs
*/

void				init_env(t_env *env);

void				init_cpu(t_cpu *cpu);

void				init_cor(char *cor_file, int player_num, t_cor *cor);

/*
** DOWN TO BUSINESS
*/

void				load_into_vm(t_env *env);

void				run_vm(t_env *env);

t_op_run			load_op(t_cor *player, t_env *env, int p);

int					*get_arg_types(char *e_byte);

int					*get_arg_sizes(t_op_run *new, t_env *env);

int					total_arg_n(int *arg_sizes);

int					arg_size(int arg_type);

void				print_oprun(t_op_run op, t_env *env);

void				get_args(t_op_run *new, t_env *env, char *pc);

int					*no_n_byte(void);

void				clear_op(t_op_run *op, t_env *env);

char				*cload_bytes(char *ptr, int start, size_t block_size,
		size_t bytes);

void				move_pc(t_cpu *p, int offset, t_env *env);

void				print_memory(const void *addr, size_t size);

int					read_int(char *ptr);

int					read_short(char *ptr);

void				run_instr(t_op_run *run, t_env *env);

void				inc_last_live(t_env *env);

void				check_live_calls(t_env *env);

void				set_alive_at_check(t_env *env);

BOOL				still_alive(t_env *env);

int					count_alive(t_env *env);

int					make_int(char *arg, int bytes);

int					get_num(char *arg, int size);

void				cwrite_bytes(t_env *env, int start, char *to_write,
		size_t write_size);

void				**copy_registers(t_cpu *cpu);

void				inherit_parent(t_env *env, int p);

int					handle_args(t_op_run *run, t_env *env, int player,
		int param);

/*
** Instructions
*/

int					is_player(int player, t_env *env);

void				live(t_op_run *run, t_env *env);

void				ld(t_op_run *run, t_env *env);

void				st(t_op_run *run, t_env *env);

void				add(t_op_run *run, t_env *env);

void				sub(t_op_run *run, t_env *env);

void				and(t_op_run *run, t_env *env);

void				or(t_op_run *run, t_env *env);

void				xor(t_op_run *run, t_env *env);

void				zjmp(t_op_run *run, t_env *env);

void				ldi(t_op_run *run, t_env *env);

void				sti(t_op_run *run, t_env *env);

void				vm_fork(t_op_run *run, t_env *env);

void				lld(t_op_run *run, t_env *env);

void				lldi(t_op_run *run, t_env *env);

void				vm_lfork(t_op_run *run, t_env *env);

void				aff(t_op_run *run, t_env *env);

/*
** Memory cleanup
*/

void				cleanup_env(t_env *env);

#endif
