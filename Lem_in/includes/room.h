/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:45:57 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 13:23:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

typedef struct			s_room
{
	char				*name;
	struct s_room_list	*links;
	int					point;
}						t_room;

#endif
