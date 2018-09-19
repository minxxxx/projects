/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 10:13:59 by khansman          #+#    #+#             */
/*   Updated: 2016/06/23 13:56:06 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_map(t_env *env)
{
	int		k;

	k = 0;
	while (k < env->map->height)
	{
		free(env->map->data[k]);
		k++;
	}
	free(env->map->data);
	free(env->map);
}

void	free_win(t_env *env)
{
	free(env->window->mlx_window);
	free(env->window->mlx);
	free(env->window->img);
	free(env->window->data);
	free(env->window);
}

void	free_data(t_env *env)
{
	free_map(env);
	free_win(env);
	free(env->position);
	free(env->direction);
	exit(1);
}

int		free_all(void *data)
{
	t_env	*env;

	env = (t_env *)data;
	free_data(env);
	return (1);
}
