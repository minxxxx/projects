/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:56:03 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/27 13:25:08 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	clean_active_ops(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (CUR_OP(p).to_exec > 1)
			clear_op(&CUR_OP(p), env);
		p++;
	}
}

void	cleanup_env(t_env *env)
{
	int	r;
	int	p;

	p = 0;
	ft_memdel((void**)&env->memory);
	while (p < env->p_count)
	{
		r = -1;
		while (++r < REG_NUMBER)
			ft_memdel(&P_REG(p, r + 1));
		ft_memdel((void**)&P_CPU(p).registers);
		if (PLAYER(p).sub != TRUE)
		{
			ft_memdel((void**)&PLAYER(p).name);
			ft_memdel((void**)&PLAYER(p).comment);
			ft_memdel((void**)&PLAYER(p).instructions);
		}
		ft_memdel((void**)&PLAYER(p).cur_op.arg_sizes);
		ft_memdel((void**)&PLAYER(p).cur_op.arg_types);
		p++;
	}
	clean_active_ops(env);
	ft_memdel((void*)&env->players);
}
