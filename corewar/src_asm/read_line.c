/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:11:53 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/30 09:24:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** This function reads a line and adds a label if there is a label
*/

int	read_line(t_info *info, char *line, int line_nbr)
{
	int		i;
	int		valid_label;
	t_label	*temp;

	i = 0;
	valid_label = 0;
	while (line[i] != '\0' && line[i] != COMMENT_CHAR)
	{
		if (line[i] == LABEL_CHAR)
		{
			temp = check_label(line, i, &valid_label, line_nbr);
			if (valid_label == -1)
				return (-1);
			if (valid_label == 1)
			{
				info->num_labels++;
				ft_lstappend(&info->labels, ft_lstnew((void *)temp));
			}
		}
		i++;
	}
	return (0);
}
