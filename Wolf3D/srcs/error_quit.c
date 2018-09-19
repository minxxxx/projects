/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 09:12:54 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/21 09:12:57 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd("\033[1;31mError happened: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}
