/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:17:00 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/30 07:18:54 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	vm_lfork(t_op_run *run, t_env *env)
{
	int		temp;
	int		p;

	if (run->arg_types[0] == DIR_CODE)
	{
		p = is_player(run->player, env);
		ft_memcpy(&temp, run->arg[0], IND_SIZE);
		reverse_bytes(&temp, IND_SIZE);
		inherit_parent(env, p);
		move_pc(&P_CPU(env->p_count), temp, env);
		P_CPU(env->p_count).registers = copy_registers(&P_CPU(p));
		PLAYER(env->p_count).cur_op = load_op(&PLAYER(env->p_count),
			env, env->p_count);
		CUR_OP(env->p_count).to_exec++;
		PLAYER(env->p_count).sub = TRUE;
		env->p_count++;
	}
}
