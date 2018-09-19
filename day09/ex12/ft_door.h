/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 09:27:55 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 09:44:26 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef int		ft_bool;
#define TRUE 1
#define OPEN 1
#define CLOSE 0
#define EXIT_SUCCESS 0

typedef struct	s_door
{
		int		state;
}
				t_door;
ft_bool	open_door(t_door *door);
ft_bool	close_door(t_door *door);
ft_bool	is_door_open(t_door *door);
ft_bool	is_door_close(t_door *door);
