/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:16:15 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:16:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_quit(char *error_message)
{
	ft_putstr_fd("An error happened: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}
