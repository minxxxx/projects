/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:14:00 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 17:01:54 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		sudo_grid(int grid[9][9], char **argv);

void	print_sudo(int grid[9][9]);

void	solver(int grid[9][9], int x, int orig[9][9], int *check);

void	ft_print(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int grid[9][9];
	int orig[9][9];
	int check;
	int *check2;

	check = 0;
	check2 = &check;
	if (argc == 10)
	{
		sudo_grid(orig, &argv[1]);
		if (sudo_grid(grid, &argv[1]))
		{
			solver(grid, 0, orig, check2);
			if (check == 1)
				print_sudo(orig);
			else
				write(1, "Error\n", 7);
		}
		else
			write(1, "Error\n", 7);
	}
	else if (argc < 10)
	{
		write(1, "Error\n", 7);
	}
	else
	{
		write(1, "Error\n", 7);
	}
	return (0);
}
