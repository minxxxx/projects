/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:32:51 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/02 15:32:54 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->sorted_size)
	{
		if (env->sorted[env->sorted_size - 1 - i] != env->stack_a[i])
			return (0);
		i++;
	}
	return (1);
}
