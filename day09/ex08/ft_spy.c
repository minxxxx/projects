/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 23:18:54 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 08:51:17 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_check(char *str)
{
	char	*atc;
	char	*p;
	char	*pres;
	int		i;
	int		a;

	atc = "attack";
	p = "powers";
	pres = "president";
	i = 0;
	a = 0;
	if (ft_strcmp(str, atc) == 0)
		ft_putstr("Alert!!!\n");
	if (ft_strcmp(str, p) == 0)
		ft_putstr("Alert!!\n");
	if (ft_strcmp(str, pres) == 0)
		ft_putstr("Alert!!!\n");
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	char	str[1000];
	int		i;
	int		a;
	int		b;

	i = 0;
	while (i < argc)
	{
		a = 0;
		b = 0;
		while (argv[i][a])
		{
			if (argv[i][a] != ' ')
			{
				str[b] = argv[i][a];
				b++;
			}
			a++;
		}
		str[a] = '\0';
		ft_strlowcase(str);
		ft_check(str);
		i++;
	}
	return (0);
}
