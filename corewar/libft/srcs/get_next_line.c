/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 11:32:54 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/23 09:03:41 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *p, size_t size)
{
	char	*temp;
	int		i;

	temp = p;
	if (!(p = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (temp[i])
	{
		p[i] = temp[i];
		i++;
	}
	free(temp);
	return (p);
}

char	get_char(const int fd)
{
	static char	buff[BUFF_SIZE];
	static char	*p;
	static int	len = 0;
	char		c;

	if (len == 0)
	{
		len = read(fd, buff, BUFF_SIZE);
		p = (char *)&buff;
		if (len == 0)
			return ('\0');
	}
	c = *p;
	p++;
	len--;
	return (c);
}

int		get_next_line(int fd, char **line)
{
	int		i;
	char	c;
	char	*temp;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	c = get_char(fd);
	while (c != '\n' && c != '\0' && temp != NULL)
	{
		temp[i++] = c;
		c = get_char(fd);
		if (i % (BUFF_SIZE + 1) == 0)
			temp = ft_realloc(temp, i + BUFF_SIZE + 1);
	}
	if (temp != NULL)
		temp[i] = '\0';
	if (temp == NULL || (c == '\0' && temp[0] == '\0'))
	{
		free(temp);
		return (0);
	}
	*line = temp;
	return (1);
}
