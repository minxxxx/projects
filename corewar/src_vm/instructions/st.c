/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 08:48:47 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 10:41:55 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static int	check_reg(t_op_run *run)
{
	if (run->arg_types[0] == REG_CODE)
	{
		if ((int)*run->arg[0] > REG_NUMBER
			|| (int)*run->arg[0] <= 0)
			return (0);
	}
	if (run->arg_types[1] == REG_CODE)
	{
		if ((int)*run->arg[1] > REG_NUMBER
			|| (int)*run->arg[1] <= 0)
			return (0);
	}
	else if (run->arg_types[1] != IND_CODE)
		return (0);
	return (1);
}

/*
** Stores REG_SIZE bytes from the first argument into the second
*/

void		st(t_op_run *run, t_env *env)
{
	int		player;
	short	temp_val;

	player = run->p_in;
	if (check_reg(run) == 0)
		return ;
	temp_val = 0;
	if (run->arg_types[1] == IND_CODE)
	{
		temp_val = read_short(run->arg[1]);
		cwrite_bytes(env, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), P_REG(player, (int)*run->arg[0]),
				REG_SIZE);
	}
	else
	{
		ft_memcpy(P_CPU(player).registers[(int)*(run->arg[1]) - 1],
				P_CPU(player).registers[(int)*(run->arg[0]) - 1], REG_SIZE);
	}
}
