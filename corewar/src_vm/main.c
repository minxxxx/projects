/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:29:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 13:12:13 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	display_players(t_env *env)
{
	int i;

	i = 0;
	while (i < env->p_count)
	{
		printf("player %s , number %d\n", env->players[i].file,
				env->players[i].p_num);
		i++;
	}
}

void	check_oph(void)
{
	if (REG_SIZE != 4)
	{
		ft_putstr_fd("This vm only supports REG_SIZE of 4 bytes\n", 2);
		exit(-1);
	}
	if (DIR_SIZE != 4)
	{
		ft_putstr_fd("This vm only supports DIR_SIZE of 4 bytes\n", 2);
		exit(-1);
	}
	if (IND_SIZE != 2)
	{
		ft_putstr_fd("This vm only supports IND_SIZE of 4 bytes\n", 2);
		exit(-1);
	}
}

void	winner_output(t_env *env)
{
	int	p;

	p = 0;
	while (p < env->p_count)
	{
		if (PLAYER(p).p_num == env->last_live)
		{
			ft_printf("Player %d, %s has won!\n", PLAYER(p).p_num,
					PLAYER(p).name);
			return ;
		}
		p++;
	}
	ft_printf("Nobody won, no live instructions were executed properly... \
			dissapointing.\n");
}

int		main(int argc, char **argv)
{
	t_env	env;

	check_oph();
	init_env(&env);
	check_args(argc, argv, &env);
	if (env.p_count > MAX_PLAYERS)
	{
		ft_putstr_fd("This vm only supports 4 players\n", 2);
		exit(-1);
	}
	get_input(argc, argv, &env);
	sort_players(&env);
	load_programs(&env);
	load_into_vm(&env);
	run_vm(&env);
	if (env.dump == FALSE)
		winner_output(&env);
	cleanup_env(&env);
	return (0);
}
