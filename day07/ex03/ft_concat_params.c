/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:55:42 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 13:21:32 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		compute_size_p(int argc, char **argv)
{
	int s_argv;
	int i;
	int a;

	i = 1;
	a = 0;
	s_argv = 0;
	while (i < argc)
	{
		while (argv[i][a])
			while (argv[i][a])
				a++;
		s_argv += a;
		a = 0;
		i++;
	}
	return (s_argv);
}

void	print_tab(int argc, char **argv, char *s, int size_p)
{
	int i;
	int a;
	int b;

	i = 0;
	a = 1;
	b = 0;
	while (i < size_p)
	{
		while (a < argc)
		{
			while (argv[a][b])
			{
				s[i] = argv[a][b];
				b++;
				i++;
			}
			s[i] = '\n';
			i++;
			b = 0;
			a++;
		}
	}
	s[i] = '\0';
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*s;
	int		size_p;

	size_p = compute_size_p(argc, argv);
	s = (char*)malloc(sizeof(*s) * (size_p + argc - 1));
	print_tab(argc, argv, s, size_p);
	return (s);
}
