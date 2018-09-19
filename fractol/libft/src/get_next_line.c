/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 10:17:16 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/10 17:09:19 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*read_line(int const fd, char *string, int *read_byte)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char *) * BUFF_SIZE);
	*read_byte = read(fd, tmp, BUFF_SIZE);
	tmp[*read_byte] = '\0';
	string = ft_strjoin(string, tmp);
	return (string);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*str;

	ret = 1;
	if (line < 0 || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')) != 0)
		{
			*str = '\0';
			*line = ft_strdup(buf);
			ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		else
			*line = ft_strdup(buf);
		buf = read_line(fd, buf, &ret);
	}
	return (ret);
}
