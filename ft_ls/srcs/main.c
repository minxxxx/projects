/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:21:41 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:21:43 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		init_env(t_env *env)
{
	env->a = 0;
	env->a_caps = 0;
	env->c = 0;
	env->f = 0;
	env->f_caps = 0;
	env->g = 0;
	env->i = 0;
	env->l = 0;
	env->n = 0;
	env->o = 0;
	env->p = 0;
	env->p_caps = 0;
	env->r = 0;
	env->r_caps = 0;
	env->s_caps = 0;
	env->t = 0;
	env->t_caps = 0;
	env->u = 0;
	env->u_caps = 0;
	env->printed_file = 0;
	env->files = NULL;
	env->sources = NULL;
}

int				main(int ac, char **av)
{
	t_env			env;
	int				mdr;

	init_env(&env);
	mdr = parse_params(&env, ac, av);
	parse_sources(&env, ac, av, mdr);
	return (0);
}
