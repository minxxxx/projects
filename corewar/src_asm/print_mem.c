/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 07:29:57 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/08 12:42:08 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	ft_hex(int num, int count)
{
	if (count > 1)
		ft_hex(num >> 4, count - 1);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

void	ft_print(unsigned char *str, size_t i, size_t size)
{
	size_t	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (str[i + j] >= 32 && str[i + j] <= 126)
			write(1, &str[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)addr;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			if (j < 16 && i + j < size)
				ft_hex((int)str[i + j], 2);
			if (j % 2)
				write(1, " ", 1);
			if (i + j >= size)
				write(1, "  ", 2);
			j++;
		}
		ft_print(str, i, size);
		write(1, "\n", 1);
		i += 16;
	}
}
