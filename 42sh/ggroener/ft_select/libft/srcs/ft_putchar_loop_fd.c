/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_loop_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:49:04 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/15 16:53:03 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character to the console, looping several times
*/

void		ft_putchar_loop_fd(char c, int fd, int size)
{
	int		count;

	count = -1;
	while (++count < size)
		ft_putchar_fd(c, fd);
}
