/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:37:50 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:49:40 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_env *env)
{
	if (env->stack_a_size > 0)
	{
		env->count++;
		env->stack_b[env->stack_b_size] = env->stack_a[env->stack_a_size - 1];
		env->stack_b_size++;
		env->stack_a_size--;
		ft_putstr("\033[34;1mPB");
		ft_putchar('\n');
	}
}
