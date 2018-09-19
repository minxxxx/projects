/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:38:47 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:50:30 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_env *env)
{
	int		i;
	int		tmp;

	if (env->stack_b_size > 1)
	{
		env->count++;
		tmp = env->stack_b[env->stack_b_size - 1];
		i = env->stack_b_size - 1;
		while (i > 0)
		{
			env->stack_b[i] = env->stack_b[i - 1];
			i--;
		}
		env->stack_b[0] = tmp;
		ft_putstr("\033[33;1mRB");
		ft_putchar('\n');
	}
}
