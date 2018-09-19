/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:33:44 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/17 15:46:26 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	ft_print_border(int length);
void	ft_print_middle(int length);
void	ft_print_line(char line[], int length);

void	rush(int x, int y)
{
	int i;

	i = 1;
	ft_print_border(x);
	while (i++ < y - 1)
	{
		ft_print_middle(x);
	}
	if (y > 1)
	{
		ft_print_border(x);
	}
}

void	ft_print_border(int length)
{
	int i;
	char line[length];

	i = 1;
	line[0] = 'A';
		while (i < length -1)
		{
			line[i++] = 'B';
		}
	if (length > 1)
	{
		line[length - 1] = 'C';
	}
	ft_print_line(line, length);
}

void	ft_print_middle(int length)
{
	int i;
	char line[length];

	line[0] = 'B';
	i = 1;
	while (i < length -1)
	{
		line[i++] = ' ';
	}
	line[length] = 'B';
	ft_print_line(line, length);
}

void	ft_print_line(char line[], int length)
{
	int i;

	i = -1;
	while (++i < length)
	{
		ft_putchar(line[i]);
	}
				ft_putchar('\n');
}

