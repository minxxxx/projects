/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:47:32 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/19 14:15:32 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_int(char *line)
{
	while (*line == '0')
		line++;
	if (!ft_strisdigit(line))
		return (0);
	if (line[0] == '-')
		return (0);
	else if (ft_strlen(line) > 10)
		return (0);
	if (ft_atol(line) > INT_MAX)
		return (0);
	return (1);
}
