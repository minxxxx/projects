/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 13:04:34 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 16:46:18 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	square_checker(int grid[9][9], int row, int col, int numb);

int	pos_checker(int grid[9][9], int row, int col, int numb)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if ((i != row && grid[col][row] == numb) 
			|| (i != col && grid[i][row] == numb))
			return (0);
		i++;
	}
	i = square_checker(grid, row, col, numb);
	return (i);
}
