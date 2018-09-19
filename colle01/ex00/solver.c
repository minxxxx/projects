/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 13:22:50 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 16:48:41 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pos_checker(int grid[9][9], int row, int col, int numb);

void	position(int *p, int *orig, int i, int check);

void	last_number(int grid[9][9], int num, int *check)
{
	if (pos_checker(grid, 8, 8, num))
	{
		if (grid[8][8] == 0)
			grid[8][8] = num;
		*check = *check + 1;
	}
}

void	solver(int grid[9][9], int x, int orig[9][9], int *check)
{
	int i;
	int col;
	int row;

	col = x % 9;
	row = x / 9;
	if (grid[col][row] != 0 && (row != 8 || col != 8) && *check < 2)
		solver(grid, x + 1, orig, check);
	i = 1;
	while (i < 10 && *check < 2)
	{
		if (row != 8 || col != 8)
		{
			if (pos_checker(grid, row, col, i) && grid[col][row] == 0)
			{
				position(&grid[col][row], &orig[col][row], i, *check);
				solver(grid, x + 1, orig, check);
				grid[col][row] = 0;
			}
		}
		else
			last_number(orig, i, check);
		i++;
	}
}
