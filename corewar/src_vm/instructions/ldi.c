/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 07:30:31 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 12:15:32 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int			handle_args(t_op_run *run, t_env *env, int player, int param)
{
	int	ret;

	if (run->arg_types[param] == DIR_CODE)
		ret = (int)read_short(run->arg[param]);
	else
		ret = read_int(P_REG(player, (int)*run->arg[param]));
	return (ret);
}

static int	check_reg(t_op_run *run)
{
	if (run->arg_types[2] != REG_CODE)
		return (0);
	if ((int)*run->arg[0] == REG_CODE
		&& ((int)*run->arg[0] > REG_NUMBER || (int)*run->arg[0] <= 0))
		return (0);
	if ((int)*run->arg[1] == REG_CODE
		&& ((int)*run->arg[1] > REG_NUMBER || (int)*run->arg[1] <= 0))
		return (0);
	if ((int)*run->arg[2] == REG_CODE
		&& ((int)*run->arg[2] > REG_NUMBER || (int)*run->arg[2] <= 0))
		return (0);
	return (1);
}

static int	return_temp(t_op_run *run, t_env *env, int player,
	int ind)
{
	int		temp_val;
	char	*mem;

	temp_val = 0;
	if (run->arg_types[ind] == DIR_CODE)
	{
		temp_val = read_short(run->arg[ind]);
	}
	else if (run->arg_types[ind] == IND_CODE)
	{
		temp_val = (int)read_short(run->arg[ind]);
		mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
				(temp_val % IDX_MOD), MEM_SIZE, IND_SIZE);
		temp_val = (int)read_short(mem);
		free(mem);
	}
	else if (run->arg_types[ind] == REG_CODE)
	{
		temp_val = read_int(P_REG(player, (int)*run->arg[ind]));
	}
	return (temp_val);
}

/*
** Loads REG_SIZE bytes from the address given by the first two parameters into
** the last parameter
*/

void		ldi(t_op_run *run, t_env *env)
{
	int		player;
	char	*mem;
	int		temp_val;

	player = run->p_in;
	temp_val = 0;
	if (check_reg(run) == 0)
		return ;
	if (run->arg_types[0] == REG_CODE || run->arg_types[0] == IND_CODE ||
			run->arg_types[0] == DIR_CODE)
	{
		temp_val = return_temp(run, env, player, 0);
		temp_val += return_temp(run, env, player, 1);
	}
	else
		return ;
	mem = cload_bytes(env->memory, (P_CPU(player).pc - env->memory) +
			(temp_val % IDX_MOD), MEM_SIZE, REG_SIZE);
	ft_memcpy(P_REG(player, (int)*run->arg[2]), mem, REG_SIZE);
	P_CPU(player).carry = !read_int(P_REG(player, (int)*run->arg[2]));
}
