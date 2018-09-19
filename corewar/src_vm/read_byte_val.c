/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_byte_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 07:20:33 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/27 10:27:12 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int	read_int(char *ptr)
{
	char	temp[4];

	ft_memcpy(temp, ptr, 4);
	reverse_bytes(temp, 4);
	return (*(int *)temp);
}

int	read_short(char *ptr)
{
	char	temp[2];

	ft_memcpy(temp, ptr, 2);
	reverse_bytes(temp, 2);
	return ((int)*(short *)temp);
}
