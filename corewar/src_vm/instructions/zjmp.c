/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 10:24:03 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/30 09:07:52 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		make_int(char *arg, int bytes)
{
	char		buf[4];
	size_t		i;
	int			ret;

	ft_memcpy(buf, arg, bytes);
	i = bytes;
	while (i < sizeof(int))
	{
		buf[i] = 0xff;
		i++;
	}
	ret = *(int*)buf;
	return (ret);
}

void	zjmp(t_op_run *run, t_env *env)
{
	int		index;

	index = (int)read_short(run->arg[0]);
	if (run->p_in != -1)
		if (P_CPU(run->p_in).carry == 1)
			move_pc(&P_CPU(run->p_in), index % IDX_MOD, env);
}
