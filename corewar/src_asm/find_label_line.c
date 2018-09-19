/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_label_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 07:08:42 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/30 09:43:42 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Returns the line that a given label is on
*/

int	find_label_line(t_info *info, char *name)
{
	t_list	*crawl;
	t_label	*temp;

	crawl = info->labels;
	name++;
	while (crawl != NULL)
	{
		temp = (t_label *)crawl->data;
		if (ft_strlen(name) > ft_strlen(temp->name))
		{
			if (ft_strncmp(name, temp->name, ft_strlen(name)) == 0 &&
					ft_strlen(name) == ft_strlen(temp->name))
				return (temp->line + 1);
		}
		else if (ft_strncmp(name, temp->name, ft_strlen(temp->name)) == 0 &&
				ft_strlen(name) == ft_strlen(temp->name))
			return (temp->line + 1);
		crawl = crawl->next;
	}
	return (-1);
}
