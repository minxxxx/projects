/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:57:06 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/10 16:57:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>

/*
**Take out this function if not needed
*/

void	get_winsize(struct winsize *ws)
{
	ioctl(1, TIOCGWINSZ, ws);
	return ;
}
