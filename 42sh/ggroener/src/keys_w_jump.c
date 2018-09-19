/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_w_jump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:59:00 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 08:59:02 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ke_jump_left(t_env *env)
{
	int		k;
	char	*temp;
	char	*temp2;

	k = ft_strlen(I_L1) - 1;
	if (k < 0 || I_L1 == NULL)
		return ;
	while (k > 0 && (I_L1[k] == ' ' || I_L1[k] == '\t'))
		k--;
	while (k > 0 && (I_L1[k] != ' ' && I_L1[k] != '\t'))
		k--;
	temp = ft_strdup(&I_L1[k]);
	ft_strclr(&I_L1[k]);
	temp2 = (I_L2 != NULL) ? ft_strjoin(temp, I_L2) : ft_strdup(temp);
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = temp2;
	if (temp != NULL)
		free(temp);
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(I_L2) - 1;
}

/*
**	Needed code: (line 61)
**		I_L1 = re_malloc(I_L1, I_C1 + k);
*/

void	ke_jump_right(t_env *env)
{
	int		k;
	char	*temp;

	k = 0;
	if (I_L2 == NULL || I_L2[k] == '\0')
		return ;
	while (I_L2[k] == ' ' || I_L2[k] == '\t')
		k++;
	while (I_L2[k] != ' ' && I_L2[k] != '\t'
		&& I_L2[k] != '\0')
		k++;
	if (k == 0)
		return ;
	temp = ft_strdup(&I_L2[k]);
	ft_memcpy(&I_L1[I_C1 + 1], I_L2, k);
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(temp) - 1;
	free(I_L2);
	I_L2 = temp;
}
