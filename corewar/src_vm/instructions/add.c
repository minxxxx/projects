/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 09:36:43 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/27 11:45:59 by ddu-toit         ###   ########.fr       */
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
	else
		return (0);
	if (run->arg_types[1] == REG_CODE)
	{
		if ((int)*run->arg[1] > REG_NUMBER
			|| (int)*run->arg[1] <= 0)
			return (0);
	}
	else
		return (0);
	if (run->arg_types[2] == REG_CODE)
	{
		if ((int)*run->arg[2] > REG_NUMBER
			|| (int)*run->arg[2] <= 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

/*
** Adds the values of the first 2 registers and stores it in the 3rd
*/

void		add(t_op_run *run, t_env *env)
{
	int	player;
	int	temp;

	player = run->p_in;
	if (check_reg(run) == 1)
	{
		temp = 0;
		temp += read_int(P_REG(player, (int)*run->arg[0]));
		temp += read_int(P_REG(player, (int)*run->arg[1]));
		P_CPU(player).carry = !temp;
		reverse_bytes(&temp, REG_SIZE);
		ft_memcpy(P_CPU(player).registers[(int)*run->arg[2] - 1],
			&temp, REG_SIZE);
	}
}
