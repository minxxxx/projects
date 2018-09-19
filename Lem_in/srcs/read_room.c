/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:20:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 14:37:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_nbr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_start_end(t_env *env, t_room *room, t_reader *p)
{
	if (p->is_start)
	{
		if (env->start)
			return (0);
		env->start = room;
		p->is_start = 0;
	}
	else if (p->is_end)
	{
		if (env->end)
			return (0);
		env->end = room;
		p->is_end = 0;
	}
	return (1);
}

int			read_room(t_env *env, t_reader *p, char **split)
{
	t_room_list	*lst;
	t_room		*room;

	if (!is_nbr(split[1]) || !is_nbr(split[2]) || p->link_part)
		return (0);
	lst = env->rooms;
	while (lst)
	{
		if (!ft_strcmp(lst->room->name, split[0]))
			return (0);
		lst = lst->next;
	}
	if (!(lst = malloc(sizeof(*lst))))
		error_quit("Failed to malloc room for list");
	room = create_room();
	room->name = split[0];
	lst->room = room;
	lst->next = env->rooms;
	env->rooms = lst;
	if (!check_start_end(env, room, p))
		return (0);
	return (1);
}
