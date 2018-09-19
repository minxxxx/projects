
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_cdown(void)
{
	int i;
	int n;

	i = 57;
	n = 48;
	while (n <= i)
	{
		ft_putchar(i);
		i--;
	}
	ft_putchar('\n');
}
int		main(void)
{
	ft_cdown();
}
