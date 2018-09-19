/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:19:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:19:22 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_termsize(int y)
{
	int				ret;
	struct ttysize	twin;
	struct winsize	win;

	ret = 0;
	if (!ioctl(0, TIOCGSIZE, &twin))
		ret = (y) ? twin.ts_lines : twin.ts_cols;
	else if (!ioctl(0, TIOCGWINSZ, &win))
		ret = (y) ? win.ws_row : win.ws_col;
	else
	{
		ft_putstr("ioctl Error: Failed to determine window size.\n.");
		exit(0);
	}
	return (ret);
}
