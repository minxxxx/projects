/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 13:45:26 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/07 17:52:58 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int g;

	i = 0;
	while (g < argc)
	{
		while (argv[g][i])
		{
			ft_putchar(argv[g][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		g++;
	}
}
