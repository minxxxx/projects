/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:38:23 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:53:28 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_b(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->stack_b_size)
	{
		ft_putnbr(env->stack_b[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
