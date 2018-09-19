/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:38:15 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 09:52:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->stack_a_size)
	{
		ft_putnbr(env->stack_a[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
