/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:08:37 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/27 09:55:23 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static int	ret_val(t_op_run *run, t_env *env, int player, int param)
{
	char	*mem;
	int		temp_val;

	if (run->arg_types[param] == REG_CODE)
		return (read_int(P_CPU(player).registers[(int)(*run->arg[param]) - 1]));
	else if (run->arg_types[param] == DIR_CODE)
	{
		temp_val = read_int(run->arg[param]);
		return (read_int(cload_bytes(env->memory, (P_CPU(player).pc -
			env->memory) + (temp_val % IDX_MOD), MEM_SIZE, REG_SIZE)));
	}
	else if (run->arg_types[param] == IND_CODE)
	{
		temp_val = read_int(run->arg[param]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory)
					+ (temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
		reverse_bytes(mem, REG_SIZE);
		temp_val = read_int(mem);
		free(mem);
		return (read_int(cload_bytes(env->memory, (P_CPU(player).pc -
			env->memory) + (temp_val % IDX_MOD), MEM_SIZE, REG_SIZE)));
	}
	return (0);
}

static int	check_reg(t_op_run *run)
{
	int		temp;

	if (run->arg_types[0] == REG_CODE)
	{
		temp = (int)*run->arg[0];
		if (temp - 1 > REG_NUMBER || (int)*run->arg[0] <= 0)
			return (0);
	}
	if (run->arg_types[1] == REG_CODE)
	{
		temp = (int)*run->arg[1];
		if (temp - 1 > REG_NUMBER || (int)*run->arg[1] <= 0)
			return (0);
	}
	if (run->arg_types[2] == REG_CODE)
	{
		temp = (int)*run->arg[2];
		if (temp - 1 > REG_NUMBER || (int)*run->arg[2] <= 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

/*
** Performs an xor operation on the first 2 parameters and stores the value in
** the third
*/

void		xor(t_op_run *run, t_env *env)
{
	int	player;
	int	temp1;
	int	temp2;
	int	temp;

	if (check_reg(run) == 0)
		return ;
	player = run->p_in;
	temp1 = ret_val(run, env, player, 0);
	temp2 = ret_val(run, env, player, 1);
	temp = temp1 ^ temp2;
	P_CPU(player).carry = !temp;
	reverse_bytes(&temp, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[(int)*(run->arg[2]) - 1], &temp,
		REG_SIZE);
}
