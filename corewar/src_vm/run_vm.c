/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 10:53:20 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/31 10:33:16 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		done(t_env *env, int *cycles)
{
	static int	checkups = 0;

	check_live_calls(env);
	if (*cycles >= env->cycle_to_die)
	{
		if (env->live_calls >= NBR_LIVE)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			checkups = 0;
		}
		if (checkups >= MAX_CHECKS)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			checkups = 0;
		}
		checkups++;
		env->live_calls = 0;
		*cycles = 0;
	}
	if (count_alive(env) == 0)
		return (1);
	else
		return (0);
}

void	fetch_ops(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).alive == TRUE)
		{
			if (CUR_OP(p).reset == TRUE && *P_CPU(p).pc >= 1 &&
					*P_CPU(p).pc <= 16)
				PLAYER(p).cur_op = load_op(&PLAYER(p), env, p);
		}
		p++;
	}
}

void	exec_ops(t_env *env)
{
	int	p;

	p = -1;
	while (++p < env->p_count)
	{
		if (PLAYER(p).alive == TRUE)
		{
			if (CUR_OP(p).to_exec == 1 && CUR_OP(p).op >= 1 &&
					CUR_OP(p).op <= 16)
			{
				get_args(&CUR_OP(p), env, &P_CPU(p).pc[1] +
						OP(CUR_OP(p).op).n_byte);
				run_instr(&CUR_OP(p), env);
				if (CUR_OP(p).op != ZJMP || P_CPU(p).carry == 0)
					move_pc(&P_CPU(p), total_arg_n(CUR_OP(p).arg_sizes)
							+ OP(CUR_OP(p).op).n_byte + 1, env);
				clear_op(&CUR_OP(p), env);
			}
			else
				CUR_OP(p).to_exec--;
		}
	}
}

/*
**Runs loop to fetch and exectute instructions.
*/

void	run_vm(t_env *env)
{
	unsigned long long int	cycle;
	int						count;
	int						p_active;

	p_active = env->p_count;
	cycle = 1;
	count = 1;
	env->alive_at_check = (int*)malloc(sizeof(int) * env->p_count);
	set_alive_at_check(env);
	while (!(done(env, &count)))
	{
		fetch_ops(env);
		exec_ops(env);
		inc_last_live(env);
		if (cycle == (unsigned long long int)env->dump_cycles)
		{
			ft_printf("DUMP at cycle %ld\n", cycle);
			print_memory(env->memory, MEM_SIZE);
			break ;
		}
		cycle++;
		count++;
	}
	ft_memdel((void**)&env->alive_at_check);
}
