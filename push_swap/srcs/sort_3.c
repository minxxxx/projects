/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:40:41 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/02 15:40:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_env *env)
{
	int		*sta;

	sta = env->stack_a;
	if (is_sorted(env))
		return ;
	if (sta[0] < sta[1] && sta[1] > sta[2] && sta[2] < sta[0])
	{
		rra(env);
		sa(env);
	}
	else if (sta[0] > sta[1] && sta[1] < sta[2] && sta[2] < sta[0])
		sa(env);
	else if (sta[0] < sta[1] && sta[1] > sta[2] && sta[2] > sta[0])
		rra(env);
	else if (sta[0] > sta[1] && sta[1] < sta[2] && sta[2] > sta[0])
		ra(env);
	else
	{
		sa(env);
		rra(env);
	}
}
