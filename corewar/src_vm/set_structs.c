/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 08:56:42 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/26 20:15:02 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	init_op_run(t_op_run *op)
{
	op->op = 0;
	op->to_exec = 0;
	op->player = 0;
	op->reset = TRUE;
}

void	init_cor(char *cor_file, int player_num, t_cor *cor)
{
	int	*pnum;

	if (cor == NULL)
		return ;
	cor->file = cor_file;
	cor->p_num = player_num;
	cor->lsc = 0;
	init_cpu(&cor->cpu);
	pnum = (int*)cor->cpu.registers[0];
	*pnum = player_num;
	reverse_bytes(pnum, 4);
	init_op_run(&cor->cur_op);
	cor->alive = TRUE;
	cor->last_live = -1;
	cor->sub = 0;
}

void	init_env(t_env *env)
{
	int	i;

	i = -1;
	if (env == NULL)
		return ;
	env->p_count = 0;
	env->dump_cycles = 0;
	env->dump = FALSE;
	env->players = NULL;
	env->memory = (char*)malloc(MEM_SIZE);
	while (++i < MEM_SIZE)
		env->memory[i] = 0;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->checkups = 0;
	if (env->memory == NULL)
		arg_err(ER_MALLOC, "init_env");
	fill_op_tab(env);
	env->last_live = -1;
	env->live_calls = 0;
}

void	init_cpu(t_cpu *cpu)
{
	int		r;

	if (cpu == NULL)
		return ;
	r = 0;
	cpu->pc = NULL;
	cpu->carry = 0;
	cpu->registers = (void**)malloc(sizeof(void*) * REG_NUMBER);
	if (cpu->registers == NULL)
		arg_err(ER_MALLOC, "init_cpu");
	while (r < REG_NUMBER)
	{
		cpu->registers[r] = malloc(REG_SIZE);
		bzero(cpu->registers[r], REG_SIZE);
		if (cpu->registers[r] == NULL)
			arg_err(ER_MALLOC, "init_cpu");
		r++;
	}
}
