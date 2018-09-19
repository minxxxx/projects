/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 10:45:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 12:10:44 by daviwel          ###   ########.fr       */
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
	if (run->arg_types[1] == REG_CODE)
	{
		if ((int)*run->arg[1] > REG_NUMBER
			|| (int)*run->arg[1] <= 0)
			return (0);
	}
	return (-1);
}

static int	ret_val(t_op_run *run, t_env *env, int player, int ind)
{
	int		temp_val;
	char	*mem;

	temp_val = 0;
	if (run->arg_types[ind] == IND_CODE)
	{
		temp_val = (int)read_short(run->arg[ind]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, IND_SIZE);
		temp_val = (int)read_short(mem);
		free(mem);
	}
	else if (run->arg_types[ind] == DIR_CODE)
	{
		temp_val = (int)read_short(run->arg[ind]);
	}
	else
	{
		temp_val = read_int(P_REG(player, (int)*run->arg[ind]));
	}
	return (temp_val);
}

/*
** Stores REG_SIZE bytes from the first argument into the address specified by
** the second and third argument
*/

void		sti(t_op_run *run, t_env *env)
{
	int		player;
	int		temp_val;

	player = run->p_in;
	if (check_reg(run) == 0)
		return ;
	temp_val = ret_val(run, env, player, 1);
	temp_val += ret_val(run, env, player, 2);
	cwrite_bytes(env, (P_CPU(player).pc - env->memory) + (temp_val % IDX_MOD),
			P_REG(player, (int)*run->arg[0]), REG_SIZE);
}
