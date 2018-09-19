
#include	<unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putboarder(int	a)
{
	int		i;
	i = 0;
	if (a > 0)
		ft_putchar('/');
	if (a > 1)
	{
		i = 0;
		while(i < a - 2)
		{
			ft_putchar('*');
			i++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
	}
}

void	ft_putlastboarder(int	a)
{
    int		i;
    i = 0;
    if (a > 0)
        ft_putchar('\\');
    if (a > 1)
    {
        i = 0;
        while(i < a - 2)
        {
            ft_putchar('*');
            i++;
        }
        ft_putchar('/');
        ft_putchar('\n');
    }
}
void	ft_putmiddle(int	a, int	b)
{
	int		i;
	int		j;
	if (a == 1 && b > 1)
	ft_putchar('\n');
	if (b > 1)
		{
			j =0;
			while (j < b - 2)
				{
					i = 0;
					if (a >= 1)
					ft_putchar('*');
					while (i < a -2)
						{
							ft_putchar(' ');
							i++;
						}
					if (a > 1)
					ft_putchar('*');
					ft_putchar('\n');
					j++;
				}
			ft_putlastboarder(a);
		}
}
void	colle(int	a, int	b)
{
	ft_putboarder(a);
	ft_putmiddle(a,b);
	if (a == 1)
		ft_putchar('\n');
}

int		main()
{
    colle(5,1);
    return (0);
}
