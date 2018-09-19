/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 10:06:53 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/09/10 13:39:28 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_doflag(char c)
{
	if (c == 'n')
		ft_putchar(10);
	if (c == '\\')
		ft_putchar(92);
	if (c == 'a')
		write(1, "\a", 1);
	if (c == 'b')
		ft_putchar(8);
	if (c == 'e')
		ft_putchar(27);
	if (c == 'f')
		ft_putchar(12);
	if (c == 'r')
		ft_putchar(13);
	if (c == 't')
		ft_putchar(9);
	if (c == 'v')
		ft_putchar(11);
}

void		ft_dostuff(char c)
{
	if (c == 'n')
		ft_putstr("\e[47m%\e[36m\e[0m");
}

static void	helper(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == 92)
		{
			i++;
			ft_doflag(av[i++]);
		}
		if (av[i] != '"')
			ft_putchar(av[i]);
		i++;
	}
}

void		ft_echo(char **av)
{
	int	x;
	int	flag;

	flag = 0;
	x = 0;
	while (av[x++])
		if (av[x])
		{
			if (!ft_strcmp(av[x], "-n"))
				flag = 1;
			else
				helper(av[x]);
			(av[x][0] != '-' && av[x + 1]) ? ft_putstr(" ") : (void)flag;
		}
	if (flag == 1)
		ft_dostuff(av[1][1]);
	ft_putchar('\n');
}
