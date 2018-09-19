/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:59:40 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/16 16:32:18 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Sorts players in array by their player numbers (special case)
*/

void	swap_cor(t_cor *p1, t_cor *p2)
{
	t_cor	*temp;

	temp = (t_cor*)malloc(sizeof(t_cor));
	ft_memcpy(temp, p1, sizeof(t_cor));
	ft_memcpy(p1, p2, sizeof(t_cor));
	ft_memcpy(p2, temp, sizeof(t_cor));
	free(temp);
}

void	sort_players(t_env *env)
{
	int		swapped;
	int		i;

	swapped = TRUE;
	while (swapped == TRUE)
	{
		swapped = FALSE;
		i = 0;
		while (i < env->p_count)
		{
			if (i + 1 < env->p_count)
				if (PLAYER(i).p_num < PLAYER(i + 1).p_num)
				{
					swap_cor(&PLAYER(i), &PLAYER(i + 1));
					swapped = TRUE;
				}
			i++;
		}
	}
}
