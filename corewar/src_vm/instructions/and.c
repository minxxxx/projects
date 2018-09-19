/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:46:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/27 12:26:22 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

static int	ret_val(t_op_run *run, t_env *env, int player, int param)
{
	char	*mem;
	int		temp_val;

	mem = NULL;
	if (run->arg_types[param] == REG_CODE)
	{
		return (read_int(P_CPU(player).registers[(int)*run->arg[param] - 1]));
	}
	else if (run->arg_types[param] == DIR_CODE)
	{
		return (read_int(run->arg[param]));
	}
	else if (run->arg_types[param] == IND_CODE)
	{
		temp_val = (int)read_short(run->arg[param]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory)
					+ (temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
		temp_val = read_int(mem);
		free(mem);
		return (temp_val);
	}
	return (0);
}

static int	check_arg(t_op_run *run)
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
	if (run->arg_types[2] == REG_CODE)
	{
		if ((int)*run->arg[2] > REG_NUMBER
			|| (int)*run->arg[2] <= 0)
			return (0);
	}
	return (1);
}

/*
** Performs an & operation on the first 2 parameters and stores the value in the
** third
*/

void		and(t_op_run *run, t_env *env)
{
	int	player;
	int	temp1;
	int	temp2;
	int	temp;

	player = run->p_in;
	if (check_arg(run) == 0)
		return ;
	temp1 = ret_val(run, env, player, 0);
	temp2 = ret_val(run, env, player, 1);
	temp = temp1 & temp2;
	P_CPU(player).carry = !temp;
	reverse_bytes(&temp, REG_SIZE);
	ft_memcpy(P_CPU(player).registers[(int)*run->arg[2] - 1], &temp, REG_SIZE);
}
