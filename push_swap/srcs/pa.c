/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:34:23 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:49:25 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env *env)
{
	if (env->stack_b_size > 0)
	{
		env->count++;
		env->stack_a[env->stack_a_size] = env->stack_b[env->stack_b_size - 1];
		env->stack_a_size++;
		env->stack_b_size--;
		ft_putstr("\033[31;1mPA");
		ft_putchar('\n');
	}
}
