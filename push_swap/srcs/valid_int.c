/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:31:04 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 11:48:24 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_int(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (ft_strlen(av[i]) > 11)
				return (0);
		}
		else if (ft_strlen(av[i]) > 10)
			return (0);
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int		idiot_proof(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
			i++;
		if (i <= 1)
			return (0);
	}
	return (1);
}
