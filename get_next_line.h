/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 07:25:49 by angonyam          #+#    #+#             */
/*   Updated: 2017/06/21 14:14:11 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
#include <stdlib.h>
#include "libft/libft.h"
int					get_next_line(int fd, char **line);
typedef	struct		s_reading {
	int				fd;
	char			buffer[BUFF_SIZE];
	size_t			p;
	size_t			size;
}					t_reading;	

#endif
