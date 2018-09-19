/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 18:08:34 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/07 18:28:01 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	char	t;
	int		i;
	int		to_find;

	to_find = 1;
	while (to_find)
	{
		to_find = 0;
		i = 0;
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				t = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = t;
				to_find = 1;
			}
		}
	}
	while (i++ < argc)
	{
		ft_putchar(argv[i]);
		t_putchar('\n');
	}
	return (0);
}
