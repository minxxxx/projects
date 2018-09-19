/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:48:22 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 18:40:19 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		sudo_grid(int grid[9][9], char **argv);

int		write_sudo(int grid[9][9]);

void	location(int *grid, int *orig, int i, int check);

void	solver(int grid[9][9], int val, int orig[9][9], int *check);

int		check_square(int grid[9][9], int row, int col, int number);

int		ft_check_grid(int grid[9][9], int row, int col, int number);

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	add_last_peace(int grid[9][9], int nr, int *check)
{
	if (ft_check_grid(grid, 8, 8, nr))
	{
		if (grid[8][8] == 0)
			grid[8][8] = nr;
		*check = *check + 1;
	}
}

int		main(int argc, char **argv)
{
	int check;
	int *check2;
	int grid[9][9];
	int orig[9][9];

	check = 0;
	check2 = &check;
	if (argc == 10)
	{
		sudo_grid(orig, &argv[1]);
		if (sudo_grid(grid, &argv[1]))
		{
			solver(grid, 0, orig, check2);
			if (check == 1)
				write_sudo(orig);
			else
				write(1, "Error\n", 7);
		}
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
