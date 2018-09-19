/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:47:47 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/22 13:25:36 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	place_points(t_env *env, t_room *room, int point)
{
	t_room_list	*lst;

	if (point < room->point)
	{
		room->point = point;
		lst = room->links;
		while (lst)
		{
			place_points(env, lst->room, point + 1);
			lst = lst->next;
		}
	}
}
