/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:34:38 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 11:59:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		valid_args(int ac, char **av)
{
	size_t	j;
	int		i;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != '-' && (av[i][j] < '0'
					|| av[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		has_doubles(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->stack_a_size)
	{
		j = 0;
		while (j < env->stack_a_size)
		{
			if (i != j && env->stack_a[i] == env->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void		fill_stack(int *stack, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		stack[ac - i - 1] = ft_atoi(av[i]);
		i++;
	}
}

static void		parse_min_max(t_env *env)
{
	int		i;

	env->min = INT_MAX;
	env->max = INT_MIN;
	i = 0;
	while (i < env->stack_a_size)
	{
		if (env->stack_a[i] < env->min)
			env->min = env->stack_a[i];
		if (env->stack_a[i] > env->max)
			env->max = env->stack_a[i];
		i++;
	}
}

void			parse_args(t_env *env, int ac, char **av)
{
	if (ac == 1)
		exit(1);
	if (!idiot_proof(ac, av))
		error_quit("Invalid parameters, needs at least two numbers\n");
	if (!valid_args(ac, av))
		error_quit("Invalid parameters, only numbers allowed\n");
	if (!valid_int(ac, av))
		error_quit("Invalid parameters, only int are allowed\n");
	if (!(env->stack_a = malloc(sizeof(*env->stack_a) * (ac - 1))))
		error_quit("Failed to malloc stack a\n");
	if (!(env->stack_b = malloc(sizeof(*env->stack_b) * (ac - 1))))
		error_quit("Failed to malloc stack b\n");
	env->stack_a_size = ac - 1;
	env->stack_b_size = 0;
	fill_stack(env->stack_a, ac, av);
	if (has_doubles(env))
		error_quit("Invalid parameters, doubles aren't allowed\n");
	parse_min_max(env);
}
