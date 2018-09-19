/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 07:46:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/16 16:26:11 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	ft_hex(int num, int count)
{
	if (count > 1)
		ft_hex(num >> 4, count - 1);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

void	ft_mem(int i, size_t size, unsigned char *ptr)
{
	size_t	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
			write(1, &ptr[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*mem;

	mem = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 32)
		{
			if (j < 32 && i + j < size)
				ft_hex((int)mem[i + j], 2);
			write(1, " ", 1);
			if (i + j >= size)
				write(1, "  ", 2);
			j++;
		}
		write(1, "\n", 1);
		i += 32;
	}
}
