/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:58:35 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 10:33:02 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ke_del(t_env *env)
{
	char	*k;

	if (I_L2 == NULL || ft_strlen(I_L2) == 0)
		return ;
	k = ft_str_inc_dup((I_L2));
	I_C2 = ft_strlen(I_L2) - 1;
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = k;
}
