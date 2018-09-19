/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:22:36 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/15 18:40:48 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 47;
	while (i < 57)
	{
		j = ++i;
		while (j < 57)
		{
			k = ++j + 1;
			while (k < 58)
			{
				ft_putchar(i);
				ft_putchar(j);
				ft_putchar(k++);
				if (i < 55)
				{
					write(1, ", ", 2);
				}
			}
		}
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
