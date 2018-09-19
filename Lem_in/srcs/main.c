/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:46:52 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 14:21:44 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test_error(int i, char *error)
{
	if (i)
	{
		ft_putstr("Error: ");
		ft_putendl(error);
		exit(1);
	}
}

int		main(void)
{
	static t_env	env;

	if (!(env.file = malloc(sizeof(*env.file))))
		error_quit("Failed to malloc env file cache");
	env.file[0] = NULL;
	env.rooms = NULL;
	env.start = NULL;
	env.end = NULL;
	env.ants = -1;
	reader(&env);
	print_file(&env);
	ft_putchar('\n');
	test_error(!env.start, "\033[1;41mNo start room\033[0;41m");
	test_error(!env.end, "\033[1;41mNo end room\033[0;41m");
	test_error(env.ants <= 0, "\033[1;41mInvalid number of Ants\033[1;41m");
	place_points(&env, env.end, 0);
	test_error(env.start->point == INT_MAX, "No path available");
	env.total_ants = env.ants;
	print_moves(&env);
	free_env(&env);
}

void	free_env(t_env *env)
{
	if (env->rooms)
		del_link_list(env->rooms);
	if (env->start)
		del_room_list(env->start);
	if (env->end)
		del_room_list(env->end);
	if (env->file)
		free2d(env->file);
}
