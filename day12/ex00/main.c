/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 12:55:32 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/15 13:10:54 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int		f;
	int		r;
	char	b[BUF_SIZE + 1];

	if (argc == 1)
	{
		ft_iferror("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_iferror("Too many arguments.\n");
		return (0);
	}
	f = open(argv[1], O_RDONLY);
	while ((r = read(f, b, BUF_SIZE)))
	{
		b[r] = '\0';
		ft_putstr(b);
	}
	close(f);
	return (0);
}
