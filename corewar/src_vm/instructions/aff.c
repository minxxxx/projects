/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 07:14:15 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/30 07:14:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	aff(t_op_run *run, t_env *env)
{
	int		player;
	int		temp;
	char	c;

	player = run->p_in;
	if ((int)*run->arg[0] - 1 < REG_NUMBER)
	{
		temp = read_int(P_REG(player, *(int *)run->arg[0]));
		c = (temp % 256);
		ft_putchar(c);
	}
}
