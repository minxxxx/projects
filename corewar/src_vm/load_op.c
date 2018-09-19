/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:37:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 13:11:06 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Clears temp op structs to be reused.
*/

void		clear_op(t_op_run *op, t_env *env)
{
	int	i;

	i = 0;
	ft_memdel((void**)&op->arg_types);
	ft_memdel((void**)&op->arg_sizes);
	if (op->to_exec == 1)
	{
		while (i < OP(op->op).nbr_args)
		{
			if (op->arg[i])
				free(op->arg[i]);
			i++;
		}
		ft_memdel((void**)&op->arg);
	}
	op->reset = TRUE;
	op->op = 0;
	op->to_exec = env->cycle_to_die + 1;
}

/*
** Gets arguments  assumes encoding byte has been skipped
*/

void		get_args(t_op_run *new, t_env *env, char *pc)
{
	int		i;

	i = 0;
	new->arg = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
	{
		if (i < OP(new->op).nbr_args)
		{
			new->arg[i] = cload_bytes(env->memory, pc - env->memory,
					MEM_SIZE, new->arg_sizes[i]);
			pc += new->arg_sizes[i];
		}
		else
			new->arg[i] = NULL;
		i++;
	}
}

int			check_valid(t_op_run *op, t_env *env)
{
	int	i;

	i = 0;
	while (i < OP(op->op).nbr_args)
	{
		if (!valid_type(op->arg_types[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Sets values for struct t_op_run.
*/

t_op_run	load_op(t_cor *player, t_env *env, int p)
{
	t_op_run	new;
	int			op;

	op = (int)*player->cpu.pc;
	new.to_exec = OP(op).nbr_cycles;
	new.op = (int)*player->cpu.pc;
	move_pc(&player->cpu, 1, env);
	if (OP(op).n_byte == FALSE)
		new.arg_types = no_n_byte();
	else
		new.arg_types = get_arg_types(player->cpu.pc);
	new.reset = FALSE;
	new.player = player->p_num;
	new.p_in = p;
	new.arg_sizes = get_arg_sizes(&new, env);
	player->cpu.pc -= 1;
	new.valid = check_valid(&new, env);
	return (new);
}
