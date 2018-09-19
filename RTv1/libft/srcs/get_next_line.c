/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 08:32:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/05 09:03:25 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_line(int const fd, char **stock)
{
	char	*buff;
	int		ret;
	char	*temp;

	if (!(buff = ft_strnew(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin(*stock, buff);
		free(*stock);
		*stock = temp;
	}
	free(buff);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char			*str = NULL;
	char				*bn;
	int					ret;

	if ((!str && (str = ft_strnew(sizeof(*str))) == NULL) || !line
		|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	bn = ft_strchr(str, '\n');
	while (bn == NULL)
	{
		ret = read_line(fd, &str);
		if (ret == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (ret < 0)
			return (-1);
		else
			bn = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(bn));
	str = ft_strdup(bn + 1);
	return (1);
}
