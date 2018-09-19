/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:22:07 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:22:09 by ggroener         ###   ########.fr       */
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

static void		check3(t_env *env, char c)
{
	if (c == 'S')
	{
		env->t = 0;
		env->s_caps = 1;
	}
	else if (c == 'i')
		env->i = 1;
	else if (c == 'n')
	{
		env->l = 1;
		env->n = 1;
	}
	else
		check4(env, c);
}

static void		check2(t_env *env, char c)
{
	if (c == 'U')
	{
		env->u = 0;
		env->c = 0;
		env->u_caps = 1;
	}
	else if (c == 'g')
	{
		env->l = 1;
		env->g = 1;
	}
	else if (c == 'o')
	{
		env->l = 1;
		env->o = 1;
	}
	else if (c == 'f')
	{
		env->a = 1;
		env->f = 1;
	}
	else
		check3(env, c);
}

static void		check1(t_env *env, char c)
{
	if (c == 'l')
		env->l = 1;
	else if (c == 'R')
		env->r_caps = 1;
	else if (c == 'a')
		env->a = 1;
	else if (c == 'r')
		env->r = 1;
	else if (c == 't')
	{
		env->t = 1;
	}
	else if (c == 'u')
	{
		env->u_caps = 0;
		env->c = 0;
		env->u = 1;
	}
	else
		check2(env, c);
}

int				parse_params(t_env *env, int agrumes, char **les_agruments)
{
	int		plus_plus;
	int		sous_lbus;

	sous_lbus = 1;
	while (sous_lbus < agrumes && les_agruments[sous_lbus][0] == '-'
			&& les_agruments[sous_lbus][1] != '\0')
	{
		if (les_agruments[sous_lbus][1] == '-')
		{
			if (les_agruments[sous_lbus][2] != '\0')
				error_options('-');
			else
				return (sous_lbus + 1);
		}
		plus_plus = 0;
		while (les_agruments[sous_lbus][++plus_plus])
			check1(env, les_agruments[sous_lbus][plus_plus]);
		++sous_lbus;
	}
	return (sous_lbus);
}
