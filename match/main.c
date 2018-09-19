/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:44:29 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/09 14:47:39 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	match(char *s1, char *s2);
int	nmatch(char *s1, char *S2);

int	main(int argc, char **argv)
{
	int i;

	if (argc != 3)
		return (0);
	i = nmatch(argv[1], argv[2]);
	ft_putchar(i + '0');
	return (0);
}
