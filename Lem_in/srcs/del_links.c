/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:58:31 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 14:39:49 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	del_room_list(t_room *room)
{
	if (room == NULL)
		return (0);
	if (room->name != NULL)
		free(room->name);
	del_link_list(room->links);
	free(room);
	return (1);
}

int	del_link_list(t_room_list *link)
{
	t_room_list *temp;

	if (link == NULL)
		return (0);
	while (link == NULL)
	{
		temp = link->next;
		del_room_list(link->room);
		free(link);
		link = temp;
	}
	return (1);
}
