/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:19:23 by jlangman          #+#    #+#             */
/*   Updated: 2016/09/11 11:45:03 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		clear_history(t_env *env)
{
	int		i;

	i = -1;
	while (I_HIS[++i])
	{
		if (I_HIS[i] != NULL)
		{
			free(I_HIS[i]);
			I_HIS[i] = NULL;
		}
	}
}

static void		print_history(t_env *env, int i)
{
	int		j;

	j = i + 15;
	while (I_HPR[i] && i < j)
	{
		ft_putendl(I_HPR[i]);
		i++;
	}
}

static int		manage_extras(t_env *env, char *com, int i, int j)
{
	int		k;

	k = 0;
	if (com != NULL)
	{
		if (ft_strcmp(com, "-c") == 0)
		{
			clear_history(env);
			return (0);
		}
		else
		{
			k = search_history(env, com, i - 1);
			print_history(env, j - k - 1);
			return (0);
		}
	}
	return (-1);
}

void			list_history(t_env *env, char **sa)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putstr("\n");
	while (I_HIS[i])
		i++;
	j = store_history(env, i);
	if (manage_extras(env, sa[1], i, j) == 0)
		return ;
	if (j > 14)
		j = j - 15;
	else
		j = 0;
	print_history(env, j);
	free_history(env);
}
