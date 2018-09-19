/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:10:45 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/09/11 15:10:47 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				store_history(t_env *env, int i)
{
	int			j;
	int			k;

	j = 0;
	I_HPR = (char **)malloc(sizeof(char *) * (i + 1));
	k = i - 1;
	while (k >= 0 && j < i)
	{
		I_HPR[j] = ft_strjoin_free1(ft_strjoin_free1(\
				ft_itoa(j + 1), "	"), I_HIS[k]);
		k--;
		j++;
	}
	I_HPR[j] = NULL;
	return (j);
}

int				search_history(t_env *env, char *str, int i)
{
	while (i >= 0)
	{
		if (ft_strcmp(I_HIS[i], str) == 0)
			return (i);
		i--;
	}
	return (i);
}

void			free_history(t_env *env)
{
	int			j;

	j = 0;
	if (I_HPR != NULL)
	{
		while (I_HPR[j])
		{
			if (I_HPR[j] != NULL)
			{
				free(I_HPR[j]);
				I_HPR[j] = NULL;
			}
			j++;
		}
		free(I_HPR);
		I_HPR = NULL;
	}
}
