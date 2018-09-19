/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 08:48:36 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/16 15:58:59 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int		get_next_num(t_env *env, int p)
{
	int	ret;
	int	dup;
	int	i;

	ret = 1;
	dup = 1;
	while (dup)
	{
		dup = 0;
		i = 0;
		while (i < p)
		{
			if (env->players[i].p_num == ret)
				dup = 1;
			i++;
		}
		if (dup)
			ret++;
	}
	return (ret);
}

/*
** Stores input from arguments, does not do error checks.
*/

void	get_input(int argc, char **argv, t_env *env)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	env->players = (t_cor*)malloc(sizeof(t_cor) * env->p_count + 1);
	while (++i < argc)
	{
		if (ft_strcmp("-dump", argv[i]) == 0 && i + 1 < argc)
		{
			env->dump_cycles = ft_atoi(argv[i + 1]);
			env->dump = TRUE;
			i++;
		}
		else if (ft_strcmp("-n", argv[i]) == 0 && i + 2 < argc)
		{
			init_cor(argv[i + 2], ft_atoi(argv[i + 1]), &env->players[p++]);
			i += 2;
		}
		else
		{
			init_cor(argv[i], get_next_num(env, p), &env->players[p]);
			p++;
		}
	}
}
