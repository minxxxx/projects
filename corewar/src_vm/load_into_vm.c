/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_into_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 08:18:49 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/13 08:35:13 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int		total_program_size(t_env *env)
{
	int	ret;
	int	p;

	p = 0;
	ret = 0;
	while (p < env->p_count)
	{
		ret += PLAYER(p).size;
		p++;
	}
	return (ret);
}

void	load_into_vm(t_env *env)
{
	int		spacing;
	int		p;
	char	*ptr;

	spacing = (MEM_SIZE - total_program_size(env)) / env->p_count;
	ptr = (char*)env->memory;
	p = 0;
	while (p < env->p_count)
	{
		ft_memcpy(ptr, PLAYER(p).instructions, PLAYER(p).size);
		P_CPU(p).pc = ptr;
		P_CPU(p).prog_start = ptr;
		ptr += spacing + PLAYER(p).size;
		p++;
	}
}
