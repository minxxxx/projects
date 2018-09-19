/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:06:29 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:31:48 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Counts the bytes if the parameters
*/

int		count_param_bytes(char **params, int num, BOOL dir_as_index)
{
	int	i;
	int	count;
	int	param_type;

	i = 0;
	count = 0;
	while (i < num)
	{
		param_type = check_param(params[i]);
		if (param_type == REG_CODE)
			count += 1;
		else if (param_type == IND_CODE)
		{
			count += IND_SIZE;
		}
		else
		{
			if (dir_as_index == TRUE)
				count += IND_SIZE;
			else
				count += DIR_SIZE;
		}
		i++;
	}
	return (count);
}

/*
** Counts the size of the parameters for the program size and makes sure that
** the parameters are the right type
*/

int		get_param_bytes(char **params, int num, t_command *nc, t_info *info)
{
	int		i;
	int		k;

	i = 0;
	nc->command_bytes = count_param_bytes(params, num, nc->dir_as_index);
	while (i < nc->num_params)
	{
		k = 0;
		while (k < info->op_tab[nc->op_tab_index].nbr_args)
		{
			if (!(return_param_type(nc->params[i]) &
						info->op_tab[nc->op_tab_index].type[i]))
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}
