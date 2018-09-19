/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 11:35:08 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/06 12:21:55 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	reverse_bytes(void *mem, size_t size)
{
	int		i;
	int		j;
	char	*temp;
	char	*ptr;

	i = size - 1;
	j = 0;
	ptr = (char*)mem;
	temp = malloc(size);
	ft_memcpy(temp, mem, size);
	while (i >= 0)
	{
		ptr[j] = temp[i];
		j++;
		i--;
	}
	free(temp);
}
