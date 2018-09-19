/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:15:35 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:15:36 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_decal(int argc, int line)
{
	int		k;

	if (argc < line)
		k = (line - argc) / 2;
	else
		k = 0;
	if (!(k && argc < line - 3 && ft_termsize(0) > 55))
		return (1);
	return (0);
}
