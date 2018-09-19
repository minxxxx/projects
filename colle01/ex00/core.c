/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 11:25:44 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/10 16:45:33 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print(char c);

int		sudo_grid(int grid[9][9], char **argv)
{
	int col;
	int row;

	col = 0;
	while (col < 9)
	{
		row = 0;
		while (row < 9)
		{
			if (argv[col][row] >= '0' && argv[col][row] <= '9')
				//get the value represented by the current char (argv)
				grid[col][row] = argv[col][row] - '0';
			else if (argv[col][row] == '.')
				//return null (0 == null on ascii)
				grid[col][row] = 0;
			else
				//otherwise return nothing and move to next row
				return (0);
			row++;
		}
		if (argv[col][row])
			return (0);
		// move to next column
		col++;
	}
	return (1);
}

void	print_sudo(int grid[9][9])
{
	int i;
	int	n;

	i = 0;
	while (i < 9)
	{
		n = 0;
		while (n < 9)
		{
			ft_print(grid[i][n] + 48);
			if (n != 8)
				ft_print(' ');
			n++;
		}
		ft_print('\n');
		i++;
	}
}

void	position(int *p, int *orig, int i, int check)
{
	*p = i;
	if (check == 0)
		*orig = i;
}
