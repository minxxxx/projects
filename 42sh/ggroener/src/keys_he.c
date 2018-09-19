/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_he.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:58:42 by khansman          #+#    #+#             */
/*   Updated: 2016/09/09 13:10:56 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**		Moves everything to the second string (I_L2)
*/

void	ke_home(t_env *env)
{
	char	*temp;

	if (I_L1 == NULL)
		return ;
	temp = (I_L2 != NULL) ? ft_strjoin(I_L1, I_L2) : ft_strdup(I_L1);
	FREE_L1;
	FREE_L2;
	I_L1 = ft_strnew(LINE_LEN);
	I_L2 = temp;
	I_C1 = -1;
	I_C2 = ft_strlen(I_L2) - 1;
}

/*
**		Moves everything to the first string (I_L1)
*/

void	ke_end(t_env *env)
{
	char	*temp;

	if (I_L2 == NULL)
		return ;
	temp = ft_strjoin(I_L1, I_L2);
	if (I_L1 != NULL)
		free(I_L1);
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = NULL;
	I_L1 = temp;
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = -1;
}
