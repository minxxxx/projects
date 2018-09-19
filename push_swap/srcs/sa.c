/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:40:09 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:51:24 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_env *env)
{
	int		val1;
	int		val2;

	if (env->stack_a_size >= 2)
	{
		env->count++;
		val1 = env->stack_a[env->stack_a_size - 2];
		val2 = env->stack_a[env->stack_a_size - 1];
		env->stack_a[env->stack_a_size - 2] = val2;
		env->stack_a[env->stack_a_size - 1] = val1;
		ft_putstr("\033[31;1mSA");
		ft_putchar('\n');
	}
}
