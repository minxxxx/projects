/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:51:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/30 07:49:47 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void			ld_ind(t_op_run *run, t_env *env, int player)
{
	char	*mem;
	int		temp_val;

	temp_val = (int)read_short(run->arg[0]);
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory)
			+ (temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[(int)*run->arg[1] - 1],
			(void *)mem, REG_SIZE);
	free(mem);
}

static int		check_reg(t_op_run *run)
{
	if ((int)*run->arg[1] > REG_NUMBER || run->arg_types[1] != REG_CODE
		|| (int)*run->arg[1] <= 0)
		return (0);
	else
		return (1);
}

/*
** Loads REG_SIZE bytes from the first parameter into the second parameter
*/

void			ld(t_op_run *run, t_env *env)
{
	int		player;

	player = run->p_in;
	if (check_reg(run) == 0)
		return ;
	if (run->arg_types[0] == DIR_CODE)
		ft_memcpy(P_REG(player, (int)*run->arg[1]), run->arg[0], REG_SIZE);
	else if (run->arg_types[0] == IND_CODE)
		ld_ind(run, env, player);
	P_CPU(player).carry = !read_int(P_REG(player, (int)*run->arg[1]));
}
