/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 00:06:48 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/03 02:21:17 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	comb(void)
{
	int set[3] = {48, 48, 48};

	while (set[0] <= 57)
	{
		if ((set[0] < set[1]) && (set[1] < set[2]))
		{
			ft_putchar(set[0]);
			ft_putchar(set[1]);
			ft_putchar(set[2]);
			ft_putchar(',');
			if (set[2]++ >= 57)
			{
				ft_putchar(' ');
			}
		}
		if (set[2]++ >= 57)
		{
			set[2] = 48;
			set[1]++;
		}
		if (set[1] == 58)
		{
			set[1] = 48;
			set[0]++;
		}
	}
}

int	main()
{
	comb();
	return (0);
}
