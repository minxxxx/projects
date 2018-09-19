
#include<unistd.h>

int	ft_putchar(char c)
{
    write(1, &c, 1);
    return(0);
}

void	rush(int	x,int	y)
{
    int	row;
    int	col;
    
    row	= 1;
    
    while(row <= y)
    {
        col = 1;
        
        while (col <= x)
        {
            if((row == 1 && covil == 1) || (row == y && col == x && y > 1))
                ft_putchar('/');
            else if((row == y && col == 1) || (row == 1 && col == x))
                ft_putchar('\\');
            else if(col == 1 || col == x || row == 1 || row == y)
                ft_putchar('*');
            else
                ft_putchar(' ');
            col++;
        }
        ft_putchar('\n');
        row++;
    }
}


int	main()
{
    rush(1, 5);
    return (0);
}
