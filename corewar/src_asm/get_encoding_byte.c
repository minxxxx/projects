/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_encoding_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 08:42:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:27:36 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Adds 01, 10 or 11 to the current byte based on what is appropriate
*/

void	encode_byte(char *byte, char *param)
{
	int	par_type;

	if ((par_type = check_param(param)) == DIR_CODE)
	{
		*byte = *byte << 1;
		*byte += 1;
		*byte = *byte << 1;
		*byte += 0;
	}
	else if (par_type == REG_CODE)
	{
		*byte = *byte << 1;
		*byte += 0;
		*byte = *byte << 1;
		*byte += 1;
	}
	else if (par_type == IND_CODE)
	{
		*byte = *byte << 1;
		*byte += 1;
		*byte = *byte << 1;
		*byte += 1;
	}
}

/*
** Reads the parameters to form the encoding byte
*/

char	get_encoding_byte(char **params, int num, int op_index, t_info *info)
{
	char	byte;
	int		i;

	byte = 0;
	i = 0;
	if (num != info->op_tab[op_index].nbr_args)
	{
		byte = '\0';
		return (byte);
	}
	while (i < 4)
	{
		if (i < num)
			encode_byte(&byte, params[i]);
		else
			byte = byte << 2;
		i++;
	}
	return (byte);
}
