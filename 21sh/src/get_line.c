/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:24:49 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:25:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*re_malloc(char *line, size_t size)
{
	char				*tmp;

	tmp = ft_strnew(size + 50);
	if (size > 0)
	{
		tmp = ft_strcpy(tmp, line);
		free(line);
	}
	return (tmp);
}

int		get_line(int fd, char **line)
{
	static unsigned int	k;
	char				buff;
	char				*l;

	l = NULL;
	read(fd, &buff, 1);
	while (buff != '\n' && buff != '\0')
	{
		if (k + 1 % 50 == 0 || k == 0)
			l = re_malloc(l, k);
		l[k] = buff;
		if (buff != 0)
			k++;
		read(fd, &buff, 1);
	}
	*line = l;
	if (k > 0)
	{
		k = 0;
		return (1);
	}
	else
		line = NULL;
	return (0);
}
