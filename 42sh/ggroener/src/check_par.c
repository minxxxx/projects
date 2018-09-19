/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:55:39 by khansman          #+#    #+#             */
/*   Updated: 2016/09/07 12:58:23 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	init_par(t_par *par, t_env *env)
{
	P_SI = 0;
	P_DB = 0;
	P_B = 0;
	P_AB = 0;
	P_SB = 0;
	P_B_SL = 0;
	P_STR = NULL;
	if (I_L1 != NULL && I_L2 != NULL)
		P_STR = ft_strjoin(I_L1, I_L2);
	else
		P_STR = (I_L1 != NULL) ? ft_strdup(I_L1) : ft_strdup(I_L2);
	P_K = -1;
}

static void	par_condition(t_par *par)
{
	if (P_SK == '(')
		P_B++;
	else if (P_SK == ')')
		P_B--;
	else if (P_SK == '{')
		P_AB++;
	else if (P_SK == '}')
		P_AB--;
	else if (P_SK == '[')
		P_SB++;
	else if (P_SK == ']')
		P_SB--;
	else if (P_SK == '\'')
		P_SI++;
	else if (P_SK == '"')
		P_DB++;
}

static int	par_valid(t_par *par)
{
	if (P_B != 0)
		return (0);
	if (P_AB != 0)
		return (0);
	if (P_SB != 0)
		return (0);
	if (P_SI != 0 && P_SI % 2 != 0)
		return (0);
	if (P_DB != 0 && P_DB % 2 != 0)
		return (0);
	if (P_B_SL)
		return (0);
	if (P_B_SL)
		return (0);
	return (1);
}

void		check_b_slash(t_par *par)
{
	P_K = 0;
	while (P_STR[P_K])
	{
		if (P_SK == '\\')
		{
			while (P_SK && !ft_isalnum(P_SK))
				P_K++;
			if (!ft_isalnum(P_SK))
			{
				P_B_SL = 1;
			}
		}
		P_K++;
	}
}

int			check_par(t_env *env)
{
	t_par	par;
	char	result;

	if (I_L1 == NULL && I_L2 == NULL)
		return (-1);
	init_par(&par, env);
	while (par.str[++(par.k)])
		par_condition(&par);
	check_b_slash(&par);
	result = (par_valid(&par));
	I_TMP2 = (result) ? 0 : 1;
	if (par.str)
		free(par.str);
	return (result);
}
