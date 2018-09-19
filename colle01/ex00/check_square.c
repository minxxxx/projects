/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 12:37:15 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 16:40:23 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	square_checker(int grid[9][9], int row, int col, int numb)
{
	int i;
	int col_min;
	int col_max;
	int row_min;
	int row_max;

	col_min = (col / 3) * 3;
	col_max = col_min + 3;
	row_min = (row / 3) * 3;
	row_max = row_min + 3;
	while (row_min < row_max)
	{
		i = col_min;
		while (i < col_max)
		{
			if (i != col && col_min != row && grid[i][row_min] == numb)
				return (0);
			i++;
		}
		row_min++;
	}
	return (1);
}
