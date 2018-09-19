/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:54:34 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 18:04:18 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check_square(int grid[9][9], int row, int col, int number)
{
    int		i;
	int		r_min;
    int		r_max;
    int		c_min;
    int		c_max;
    
    r_min = (row / 3) * 3;
    r_max = r_min + 3;
    c_min = (col / 3) * 3;
    c_max = c_min + 3;
    while (r_min < r_max)
    {
        i = c_min;
        while (i < c_max)
        {
            if (i != col && c_min != row && grid[i][r_min] == number)
                return (0);
            i++;
        }
        r_min++;
    }
    return (1);
}

int			ft_check_grid(int grid[9][9], int row, int col, int number)
{
    int		i;
    
    i = 0;
    while (i < 9)
    {
        if (i != row && grid[col][i] == number)
            return (0);
        i++;
    }
    i = 0;
    while (i < 9)
    {
        if (i != col && grid[i][row] == number)
            return (0);
        i++;
    }
    i = check_square(grid, row, col, number);
    return (i);
}
