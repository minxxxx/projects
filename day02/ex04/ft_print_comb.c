/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 11:56:55 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/01 12:49:33 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int combo[3] = {48, 48, 48};

	while (combo[0] <= 57)
	{
		if ((combo[0] < combo[1]) && (combo[1] < combo[2]))
		{
			ft_putchar(combo[0]);
			ft_putchar(combo[1]);
			ft_putchar(combo[2]);
			ft_putchar(',');
			if (combo[0] != 55)
			{
				ft_putchar(' ');
			}
		}
		if (combo[2]++ >= 57)
		{
			combo[2] = 48;
			combo[1]++;
		}
		if (combo[1] == 58)
		{
			combo[1] = 48;
			combo[0]++;
		}
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_print_comb();
}
