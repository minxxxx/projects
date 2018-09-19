
void		ft_write(char c);

int	sudo_grid(int grid[9][9], char **argv)
{
    int		i_row;
    int		i_col;
    
    i_col = 0;
    while (i_col < 9)
    {
        i_row = 0;
        while (i_row < 9)
        {
            if (argv[i_col][i_row] >= '0' && argv[i_col][i_row] <= '9')
                grid[i_col][i_row] = argv[i_col][i_row] - '0';
            else if (argv[i_col][i_row] == '.')
                grid[i_col][i_row] = 0;
            else
                return (0);
            i_row++;
        }
        if (argv[i_col][i_row])
            return (0);
        i_col++;
    }
    return (1);
}

void write_sudo(int grid[9][9])
{
    int		i;
    int		m;
    
    i = 0;
    while (i < 9)
    {
        m = 0;
        while (m < 9)
        {
            ft_write(grid[i][m] + 48);
            if (m != 8)
                ft_write(' ');
            m++;
        }
        ft_write('\n');
        i++;
    }
}

void location(int *grid, int *orig, int i, int check)
{
    *grid = i;
    if (check == 0)
        *orig = i;
}
