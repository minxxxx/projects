/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:19:47 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/16 15:55:40 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

static long int	ft_atoi_long(const char *str)
{
	int			i;
	int			min;
	long int	total;

	i = 0;
	min = 1;
	total = 0;
	if (str[0] == '-')
	{
		min = -1;
		str++;
	}
	while (ft_isdigit(str[i]))
		total = total * 10 + (str[i++] - '0');
	return (min * total);
}

int				check_int(char *arg)
{
	long int	ret;

	ret = ft_atoi_long(arg);
	if (ret <= 2147483647 && ret >= -2147483648)
		return (1);
	else
		return (0);
}

int				is_numeric(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (0);
	if (arg[i] && arg[i] == '-')
		i++;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
