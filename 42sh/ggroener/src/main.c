/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:25:14 by khansman          #+#    #+#             */
/*   Updated: 2016/09/06 12:49:57 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**This function is not currently needed.
*/

void	*back_up_env(void *env)
{
	static void *e;

	if (!e && env)
		e = env;
	return ((void *)e);
}

void	init_hist(t_env *env, char action)
{
	I_TMP = 0;
	I_TMP2 = 0;
	I_C1 = 0;
	I_C2 = 0;
	if (action == 0)
	{
		I_HIS = (char **)ft_strnew((sizeof(char *) * (MAX_HIST + 1)));
		I_CB = NULL;
	}
	else
	{
		FREE_L1;
		FREE_L2;
	}
	FREE_(I_CUR);
	I_H_POS = -1;
	I_L1 = NULL;
	I_L2 = NULL;
}

void	init_state(t_env *env, char **line, char ***environ)
{
	ft_bzero(env, sizeof(t_env));
	sigs();
	env->environ = get_env(*environ);
	env->env_size = get_envsize(env->environ);
	*line = NULL;
	init_hist(env, 0);
}

/*
**	Debug lines (put inside main if statement)
**		printf("Line = '%s'\n", line);//debug
**		put_bin((unsigned char *)line);//debug
**
**	Removed Code
**		if (env.l != NULL) free(env.l);
*/

int		main(void)
{
	MAIN_VAR;
	init_state(&env, &env.l, &environ);
	back_up_env((void *)&env);
	while (1)
	{
		ft_putstr(SH_L);
		signal_gest();
		get_input(&env, 0, &env.l);
		if (check_line(env.l) && env.l)
		{
			if (ft_memcmp(env.l, CM_EXIT, CM_EXIT_S) == 0)
				break ;
			scan_for_var(&env, &env.l);
			if (ft_strchr_f(env.l, '=') != 0)
				set_env(&env, env.l);
			else
				com_sep(&env, env.l);
		}
		else
			FREE_(env.l);
		com_history(&env, HIST_STORE);
		init_hist(&env, 1);
		ft_signal_set();
	}
	exit_prog(&env);
}
