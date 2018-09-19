/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_history.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:56:15 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 09:51:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			find_string_pos(char **arr, char *str)
{
	int		k;

	k = -1;
	if (!arr || !arr[k + 1])
		return (-2);
	while (arr[++k])
		if (!ft_strcmp(arr[k], str))
			return (k);
	return (-1);
}

/*
**	Debug Code (End of function)
**		ft_putstr("History:\n");
**		ft_env(I_HIS);
*/

static void	com_hist_add(t_env *env, char *str)
{
	int		k;
	char	*s;

	s = (str == NULL) ? ft_strjoin(I_L1, I_L2) : ft_strdup(str);
	if (ft_strlen(s) == 0 || !ft_strcmp(s, I_HIS[0]))
		return ;
	k = -1;
	while (I_HIS[++k] && k < MAX_HIST)
		if (!ft_strcmp(I_HIS[k], s) && str != NULL)
		{
			free(s);
			return ;
		}
	if (k >= MAX_HIST - 1)
		free(I_HIS[k]);
	while (k > 0)
	{
		I_HIS[k] = I_HIS[k - 1];
		k--;
	}
	I_HIS[0] = s;
	I_H_POS = (str == NULL) ? -1 : I_H_POS;
}

static void	com_hist_next(t_env *env)
{
	if (I_HIS[0] == NULL || I_H_POS < 0)
		return ;
	if (I_H_POS > 0)
		I_H_POS--;
	if (I_H_POS < 0)
		I_H_POS++;
	if (I_L1 != NULL)
		free(I_L1);
	I_L1 = ft_strnew(51);
	ft_memcpy(I_L1, I_HIS[I_H_POS], ft_strlen(I_HIS[I_H_POS]));
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = NULL;
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(I_L2) - 1;
}

static void	com_hist_prev(t_env *env)
{
	if (I_HIS[0] == NULL || I_H_POS >= MAX_HIST)
		return ;
	if (I_HIS[I_H_POS] && !(I_H_POS < 0))
		I_H_POS++;
	else if (I_H_POS < 0)
		I_H_POS = 0;
	if (I_H_POS >= MAX_HIST || !(I_HIS[I_H_POS] && I_H_POS > -1))
		I_H_POS--;
	if (I_L1 != NULL)
		free(I_L1);
	I_L1 = ft_strnew(51);
	ft_memcpy(I_L1, I_HIS[I_H_POS], ft_strlen(I_HIS[I_H_POS]));
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = NULL;
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(I_L2) - 1;
}

int			com_history(t_env *env, int action)
{
	int			k;

	k = -1;
	if (I_H_POS < 0)
		I_CUR = ft_strjoin(I_L1, I_L2);
	if (action == HIST_STORE)
		com_hist_add(env, NULL);
	else if (action == HIST_NEXT && I_H_POS == 0)
	{
		if (I_L1 != NULL)
			free(I_L1);
		if (I_L2 != NULL)
			free(I_L2);
		I_L1 = ft_strnew(51);
		ft_memcpy(I_L1, I_CUR, ft_strlen(I_CUR));
		I_C1 = ft_strlen(I_L1) - 1;
		I_C2 = 0;
	}
	else if (action == HIST_NEXT)
		com_hist_next(env);
	else if (action == HIST_PREV)
		com_hist_prev(env);
	else
		return (0);
	return (1);
}
