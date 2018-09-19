/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:40:32 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/02 15:40:33 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		set_direction(t_env *env, t_sort *s)
{
	int		i;

	i = 0;
	while (i < env->stack_b_size)
	{
		if (env->stack_b[i] == env->sorted[env->sorted_size - 2 - s->k])
		{
			if (i < env->stack_b_size / 2)
				s->dir = 0;
			else
				s->dir = 1;
		}
		i++;
	}
}

static void		move(t_env *env, t_sort *s)
{
	if (s->dir)
		rb(env);
	else
		rrb(env);
}

static void		place(t_env *env, t_sort *s)
{
	pa(env);
	s->j++;
	s->k++;
	set_direction(env, s);
}

void			sort(t_env *env)
{
	t_sort	s;

	s.k = 0;
	set_direction(env, &s);
	while (env->stack_b_size > 0)
	{
		if (env->stack_b[env->stack_b_size - 1]
				== env->sorted[env->sorted_size - 2 - s.k])
			place(env, &s);
		else
			move(env, &s);
	}
	pa(env);
}
