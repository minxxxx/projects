/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:04:04 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/18 17:03:01 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	bottom(int height, int length)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_sastantua(int size)
{
	int i;
	int height;
	int length;

	i = 0;
	height = 3;
	length = 3;
	while (i < size)
	{
		bottom(height, length);
		write(1,"\n", 1);
		i++;
	}
}
