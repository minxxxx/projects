/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sources_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:24:08 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:24:10 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_sources_empty(char **av, int c)
{
	int		i;

	i = c;
	while (av[i])
	{
		if (!av[i][0])
		{
			ft_putendl_fd("ls: fts_open: No such file or directory", 2);
			exit(-1);
		}
		i++;
	}
}
