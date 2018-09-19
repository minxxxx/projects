/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 11:40:29 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:20:03 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Checks that the file has the correct extension
*/

int	check_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("Error : Incorrect file format\n", 2);
		return (-1);
	}
	if (*(str + 1) != 's')
	{
		ft_putstr_fd("Error : Incorrect file format\n", 2);
		return (-1);
	}
	if (*(str + 2) != '\0')
	{
		ft_putstr_fd("Error : Incorrect file format\n", 2);
		return (-1);
	}
	return (0);
}

/*
** Ensures that the input is correct
*/

int	error_check(int argc, char **argv)
{
	char	*str;
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./asm file_name[.s]\n", 2);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error reading file : ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	str = ft_strchr(argv[1], '.');
	close(fd);
	return (check_str(str));
}
