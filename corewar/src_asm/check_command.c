/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 13:16:17 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:08:45 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Returns the index of a command in the op_tab
*/

int	check_command(char *com, t_info *info)
{
	int	i;

	i = 1;
	while (i < OP_COUNT + 1)
	{
		if (strcmp(com, info->op_tab[i].name) == 0 && ft_strlen(com) ==
				ft_strlen(info->op_tab[i].name))
			return (i);
		i++;
	}
	return (-1);
}
