/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:40:51 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/02 15:40:52 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		move(t_env *env, int searched)
{
	int		i;

	i = 0;
	while (i < env->stack_a_size)
	{
		if (env->stack_a[i] == searched)
		{
			if (i < env->stack_a_size / 2)
				rra(env);
			else
				ra(env);
			return ;
		}
		i++;
	}
}

void			sort_5(t_env *env)
{
	int		searched;
	int		step;

	step = 0;
	while (env->stack_a_size > 3)
	{
		searched = env->sorted[step ? 1 : 0];
		if (env->stack_a[env->stack_a_size - 1] == searched)
		{
			pb(env);
			step = !step;
		}
		else
			move(env, searched);
	}
	sort_3(env);
	pa(env);
	pa(env);
}
