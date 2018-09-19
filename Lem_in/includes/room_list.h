/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:46:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/19 14:21:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_LIST_H
# define ROOM_LIST_H

struct s_room;

typedef struct			s_room_list
{
	struct s_room		*room;
	struct s_room_list	*next;
}						t_room_list;

#endif
