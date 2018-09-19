/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:22:30 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:22:32 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		error_options(char c)
{
	ft_putstr_fd("/bin/ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] ", 2);
	ft_putstr_fd("[file ...]\n", 2);
	exit(-1);
}

static void		check5(t_env *env, char c)
{
	if (c == 'c')
	{
		env->u = 0;
		env->u_caps = 0;
		env->c = 1;
	}
	else if (c == 'F')
	{
		env->p = 0;
		env->f_caps = 1;
	}
	else
		error_options(c);
}

void			check4(t_env *env, char c)
{
	if (c == 'A')
		env->a_caps = 1;
	else if (c == 'f')
	{
		env->a = 1;
		env->f = 1;
	}
	else if (c == 'p')
	{
		env->p = 1;
		env->f_caps = 0;
	}
	else if (c == 'P')
		env->p_caps = 1;
	else if (c == '1')
		env->l = 0;
	else if (c == 'T')
		env->t_caps = 1;
	else
		check5(env, c);
}
