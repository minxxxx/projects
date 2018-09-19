/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:40:19 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:51:37 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_env *env)
{
	int		val1;
	int		val2;

	if (env->stack_b_size >= 2)
	{
		env->count++;
		val1 = env->stack_b[env->stack_b_size - 2];
		val2 = env->stack_b[env->stack_b_size - 1];
		env->stack_b[env->stack_b_size - 2] = val2;
		env->stack_b[env->stack_b_size - 1] = val1;
		ft_putstr("\033[34;1msb");
		ft_putchar('\n');
	}
}
