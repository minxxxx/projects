/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:25:14 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 11:08:22 by jlangman         ###   ########.fr       */
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
		if (I_L1 != NULL)
			free(I_L1);
		if (I_L2 != NULL)
			free(I_L2);
	}
	I_H_POS = -1;
	I_L1 = NULL;
	I_L2 = NULL;
}

void	init_state(t_env *env, char **line, char ***environ)
{
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
*/

int		main(void)
{
	MAIN_VAR;
	init_state(&env, &line, &environ);
	back_up_env((void *)&env);
	while (1)
	{
		ft_putstr(SH_L);
		get_input(&env, 0, &line);
		if (check_line(line))
		{
			if (ft_memcmp(line, CM_EXIT, CM_EXIT_S) == 0)
				break ;
			if (ft_strchr_f(line, '=') != 0)
				set_env(&env, line);
			else
				com_sep(&env, line);
			if (line != NULL)
				free(line);
			line = NULL;
			com_history(&env, HIST_STORE);
			init_hist(&env, 1);
		}
	}
	exit(1);
}
