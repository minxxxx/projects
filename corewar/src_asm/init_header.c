/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 08:57:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/08 14:17:43 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	init_header(t_header *header, t_info *info)
{
	int	i;

	i = 0;
	while (i < COMMENT_LENGTH + 1)
	{
		if (i < PROG_NAME_LENGTH + 1)
			info->header.prog_name[i] = 0;
		info->header.comment[i] = 0;
		i++;
	}
	header->magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(info->header.prog_name, info->name);
	ft_strcpy(info->header.comment, info->comment);
}
