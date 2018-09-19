/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:17:00 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 14:11:13 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	inherit_parent(t_env *env, int p)
{
	env->players = realloc(env->players, sizeof(t_cor) * (env->p_count + 1));
	if (p != -1)
	{
		env->players[env->p_count] = PLAYER(p);
		env->players[env->p_count].alive = TRUE;
		PLAYER(env->p_count).sub = TRUE;
		CUR_OP(env->p_count).arg_types = (int*)malloc(sizeof(int) * 4);
		CUR_OP(env->p_count).arg_sizes = (int*)malloc(sizeof(int) * 4);
		CUR_OP(env->p_count).arg = NULL;
		CUR_OP(env->p_count).reset = FALSE;
	}
	else
		return ;
}

void	**copy_registers(t_cpu *cpu)
{
	void	**ret;
	int		r;

	r = 0;
	ret = (void**)malloc(sizeof(void*) * REG_NUMBER);
	while (r < REG_NUMBER)
	{
		ret[r] = malloc(REG_SIZE);
		ft_memcpy(ret[r], cpu->registers[r], REG_SIZE);
		r++;
	}
	return (ret);
}

void	vm_fork(t_op_run *run, t_env *env)
{
	int		temp;
	int		p;

	p = run->p_in;
	if (run->arg_types[0] == DIR_CODE)
	{
		ft_memcpy(&temp, run->arg[0], IND_SIZE);
		reverse_bytes(&temp, IND_SIZE);
		inherit_parent(env, p);
		move_pc(&P_CPU(env->p_count), temp % IDX_MOD, env);
		P_CPU(env->p_count).registers = copy_registers(&P_CPU(p));
		PLAYER(env->p_count).cur_op = load_op(&PLAYER(env->p_count),
			env, env->p_count);
		CUR_OP(env->p_count).to_exec++;
		PLAYER(env->p_count).sub = TRUE;
		env->p_count++;
	}
}
