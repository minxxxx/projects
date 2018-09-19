/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:39:15 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:50:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_env *env)
{
	int		i;
	int		tmp;

	if (env->stack_a_size > 1)
	{
		env->count++;
		tmp = env->stack_a[0];
		i = 0;
		while (i < env->stack_a_size - 1)
		{
			env->stack_a[i] = env->stack_a[i + 1];
			i++;
		}
		env->stack_a[env->stack_a_size - 1] = tmp;
		ft_putstr("\033[35;1mRRA");
		ft_putchar('\n');
	}
}
