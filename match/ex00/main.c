/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:44:29 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/12 13:42:34 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		match(char *s1, char *s2);

int		main(int argc, char **argv)
{
	int i;

	if (argc != 3)
		return (0);
	i = match(argv[1], argv[2]);
	ft_putchar(i + '0');
	return (0);
}
