/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 09:21:04 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/31 10:57:38 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	cont_run(t_op_run *run, t_env *env, int code)
{
	if (code == ZJMP)
		zjmp(run, env);
	else if (code == LDI)
		ldi(run, env);
	else if (code == STI)
		sti(run, env);
	else if (code == FORK)
		vm_fork(run, env);
	else if (code == LLD)
		lld(run, env);
	else if (code == LLDI)
		lldi(run, env);
	else if (code == LFORK)
		vm_lfork(run, env);
	else if (code == AFF)
		aff(run, env);
}

/*
** Runs the correct function depending on given t_op_run struct.(opcode)
*/

void	run_instr(t_op_run *run, t_env *env)
{
	int	code;

	code = run->op;
	if (run->valid == 1)
	{
		if (code == LIVE)
			live(run, env);
		else if (code == LD)
			ld(run, env);
		else if (code == ST)
			st(run, env);
		else if (code == ADD)
			add(run, env);
		else if (code == SUB)
			sub(run, env);
		else if (code == AND)
			and(run, env);
		else if (code == OR)
			or(run, env);
		else if (code == XOR)
			xor(run, env);
		else
			cont_run(run, env, code);
	}
}
