/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:41:00 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 17:41:02 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_check_grid(int grid[9][9], int row, int col, int number);

void		location(int *grid, int *orig, int i, int check);

void		add_last_peace(int grid[9][9], int nr, int *check);

void		solver(int grid[9][9], int val, int orig[9][9], int *check)
{
    int		i;
    int		row;
    int		col;
    
    row = val % 9;
    col = val / 9;
    if (grid[col][row] != 0 && (row != 8 || col != 8) && *check < 2)
        solver(grid, val + 1, orig, check);
    i = 1;
    while (i < 10 && *check < 2)
    {
        if (row != 8 || col != 8)
        {
            if (ft_check_grid(grid, row, col, i) && grid[col][row] == 0)
            {
                location(&grid[col][row], &orig[col][row], i, *check);
                solver(grid, val + 1, orig, check);
                grid[col][row] = 0;
            }
        }
        else
            add_last_peace(orig, i, check);
        i++;
    }
}
