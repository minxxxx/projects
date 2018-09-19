/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 14:04:23 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 11:57:56 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		real_sort(t_env *env)
{
	env->pre_sort = env->sorted_size / 50;
	if (env->pre_sort < 1)
		env->pre_sort = 1;
	if (env->pre_sort > 50)
		env->pre_sort = 50;
	pre_sort(env);
	sort(env);
}

static void		choose_sort(t_env *env)
{
	if (!is_sorted(env))
	{
		if (env->stack_a_size == 3)
			sort_3(env);
		else if (env->stack_a_size == 2)
			sa(env);
		else
		{
			check_dur(env);
			if (!is_sorted(env))
			{
				if (env->stack_a_size <= 5)
					sort_5(env);
				else
					real_sort(env);
			}
		}
	}
	ft_putchar('\n');
}

int				main(int ac, char **av)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		return (-1);
	env->count = 0;
	parse_args(env, ac, av);
	calc_sorted(env);
	if (!is_sorted(env))
		choose_sort(env);
	ft_putendl("\n\033[1;37mStack A:\033[0;37m");
	print_a(env);
	ft_putendl("\033[1;37mStack B:\033[0;37m");
	print_b(env);
	ft_putstr("\033[1;32mCount number: \033[1;37m");
	ft_putnbr(env->count);
	ft_putchar('\n');
	return (0);
}
