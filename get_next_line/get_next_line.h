/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:41:40 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/22 15:27:12 by goisetsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);
int		ft_bufferreader(const int fd, char **line);

#endif
