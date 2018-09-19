/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bytes_between.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 07:32:29 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 08:27:14 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

int	count_down(t_info *info, int com_line, int label_line)
{
	t_list		*crawl;
	t_command	*com;
	int			ret;

	ret = 0;
	crawl = info->commands;
	com = (t_command *)crawl->data;
	while (com->line_nbr != com_line && crawl != NULL)
	{
		crawl = crawl->next;
		com = (t_command *)crawl->data;
	}
	while (com->line_nbr < label_line && crawl != NULL)
	{
		ret += com->command_bytes;
		crawl = crawl->next;
		if (crawl != NULL)
			com = (t_command *)crawl->data;
	}
	return (ret);
}

int	count_up(t_info *info, int com_line, int label_line)
{
	t_list		*crawl;
	t_command	*com;
	int			ret;

	ret = 0;
	crawl = info->commands;
	com = (t_command *)crawl->data;
	while (com->line_nbr < label_line && crawl != NULL && crawl->next != NULL)
	{
		crawl = crawl->next;
		com = (t_command *)crawl->data;
	}
	while (com->line_nbr < com_line && crawl != NULL && crawl->next != NULL)
	{
		ret -= com->command_bytes;
		crawl = crawl->next;
		com = (t_command *)crawl->data;
	}
	return (ret);
}

/*
** Counts the bytes between a direct calling a label and the label itself,
** either going up or down depending on the relative positions of the label and
** the command
*/

int	count_bytes_between(t_info *info, int com_line, int label_line)
{
	if (com_line < label_line)
		return (count_down(info, com_line, label_line));
	else
		return (count_up(info, com_line, label_line));
}
