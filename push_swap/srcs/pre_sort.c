/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:38:01 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/02 15:38:03 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push(t_env *env, int *j)
{
	pb(env);
	(*j)++;
}

static int		has_elem_higher_than(t_env *env, int to)
{
	int		i;

	i = 0;
	while (i < env->stack_a_size)
	{
		if (env->stack_a[i] < to)
			return (1);
		i++;
	}
	return (0);
}

void			pre_sort(t_env *env)
{
	int		to;
	int		i;
	int		j;

	i = 0;
	while (i < env->pre_sort)
	{
		to = env->sorted[(int)((env->sorted_size - 1)
				/ (double)env->pre_sort * (double)(i + 1))];
		j = 0;
		while (has_elem_higher_than(env, to))
		{
			if (env->stack_a[env->stack_a_size - 1] < to)
				push(env, &j);
			else
				ra(env);
		}
		i++;
	}
}
