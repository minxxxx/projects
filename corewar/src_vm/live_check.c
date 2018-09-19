/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 06:30:08 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 13:50:21 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
** Inc last_live for each living player.
*/

void	inc_last_live(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).alive == TRUE)
		{
			PLAYER(p).last_live++;
		}
		p++;
	}
}

/*
** Check that every process calls the "live" instruction every CYCLE_TO_DIE.
*/

void	check_live_calls(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).last_live > env->cycle_to_die)
			PLAYER(p).alive = FALSE;
		p++;
	}
}

/*
** Saves which players are alive at function call.
*/

void	set_alive_at_check(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		env->alive_at_check[p] = PLAYER(p).alive;
		p++;
	}
}

/*
** Function returns a boolean value indicating whether all programs that were
** alive at last check are still alive
*/

BOOL	still_alive(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (env->alive_at_check[p] != PLAYER(p).alive)
			return (FALSE);
		p++;
	}
	return (TRUE);
}

/*
** Returns how many players are alive.
*/

int		count_alive(t_env *env)
{
	int	ret;
	int	p;

	p = 0;
	ret = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).alive == TRUE)
			ret++;
		p++;
	}
	return (ret);
}
