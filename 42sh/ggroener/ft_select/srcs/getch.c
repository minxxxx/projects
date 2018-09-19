/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:16:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:16:35 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*ft_getch(void)
{
	char	*buff;

	buff = ft_strnew(sizeof(char) * 5);
	if (read(0, buff, 4) == EOF)
		ft_signal(1);
	return (buff);
}

/*
**renamed STDIN_FILENO to 0.
*/
