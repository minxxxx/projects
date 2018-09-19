/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:33:44 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/18 13:22:16 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_top(int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		i++;
		if (i == 1)
		{
			ft_putchar('/');
		}
		else if (i == x)
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
	}
}

void	print_middle(int x, int y)
{
	int j;
	int k;

	j = 0;
	while (j < y)
	{
		k = 0;
		ft_putchar('\n');
		while (k < x)
		{
			k++;
			if (k == 1)
				ft_putchar('*');
			else if (k == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		j++;
	}
}

void	print_bottom(int x)
{
	int i;

	i = 0;
	ft_putchar('\n');
	while (i < x)
	{
		i++;
		if (i == 1)
		{
			ft_putchar('\\');
		}
		else if (i == x)
		{
			ft_putchar('/');
		}
		else
		{
			ft_putchar('*');
		}
	}
}

void	rush(int x, int y)
{
	if (y == 1)
		print_top(x);
	else if (x == 2)
	{
		print_top(x);
		print_bottom(x);
	}
	else
	{
		print_top(x);
		print_middle(x, y - 2);
		print_bottom(x);
	}
	ft_putchar('\n');
}
