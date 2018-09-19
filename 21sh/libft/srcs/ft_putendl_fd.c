/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:10:17 by ggroener          #+#    #+#             */
/*   Updated: 2016/08/07 10:47:13 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Old code, Using Kalilo version rather
**void	ft_putendl_fd(char const *s, int fd)
**{
**	ft_putstr_fd(s, fd);
**	ft_putchar_fd('\0', fd);
**}
*/

void	ft_putendl_fd(char const *s, int fd)
{
	int	k;

	k = 0;
	while (s[k] != '\0')
		k++;
	write(fd, s, k);
	write(fd, "\n", 1);
}
