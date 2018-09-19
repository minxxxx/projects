/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:26:53 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/22 13:22:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(*room))))
		error_quit("Failed to malloc room");
	room->name = NULL;
	room->links = NULL;
	room->point = INT_MAX;
	return (room);
}
