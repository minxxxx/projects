/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 02:26:47 by nle-bret          #+#    #+#             */
/*   Updated: 2015/12/09 05:36:10 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_save	*ft_create_fd(int fd_pnum)
{
	t_save		*fd;

	if ((fd = (t_save *)ft_memalloc(sizeof(t_save))) == NULL)
		return (NULL);
	fd->rest = ft_strnew(1);
	fd->fd_num = fd_pnum;
	fd->next = NULL;
	return (fd);
}

static int		ft_save(t_save **s, char *buf, char **line)
{
	char	*eol;
	char	*tmp;

	if ((eol = ft_strchr(buf, '\n')) != NULL && eol++)
	{
		if ((*s)->rest && ft_strchr((*s)->rest, '\n') == NULL)
			*line = ft_strjoin_free_s2((*s)->rest, ft_strcpy_limit(buf, '\n'));
		else
			*line = ft_strcpy_limit(buf, '\n');
		tmp = (*s)->rest;
		(*s)->rest = ft_strdup(eol);
		ft_strdel(&tmp);
		return (1);
	}
	else
	{
		tmp = (*s)->rest;
		if ((*s)->rest)
			(*s)->rest = ft_strjoin((*s)->rest, buf);
		else
			(*s)->rest = ft_strdup(buf);
		ft_strdel(&tmp);
	}
	return (0);
}

static t_save	*ft_get_list(t_save **s, int fd)
{
	t_save			*lst;

	if (!*s)
		*s = ft_create_fd(fd);
	lst = *s;
	while (lst->next && lst->fd_num != fd)
		lst = lst->next;
	if (lst->next == NULL && lst->fd_num != fd)
		lst->next = ft_create_fd(fd);
	lst = *s;
	while (lst && lst->fd_num != fd)
		lst = lst->next;
	return (lst);
}

static int		ft_verif_last_line(t_save *lst, char **line, int ret)
{
	if (ret != -1 && lst->rest && (*line = ft_strdup(lst->rest)) != NULL)
	{
		if (lst->rest && ft_strlen(lst->rest))
			ret = 1;
		else
			ret = 0;
		ft_strdel(&lst->rest);
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_save	*s;
	t_save			*lst;

	if (!line)
		return (-1);
	lst = ft_get_list(&s, fd);
	if (lst && lst->rest && ft_strchr(lst->rest, '\n') &&
			ft_save(&lst, lst->rest, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_save(&lst, buf, line))
			return (1);
	}
	return (ft_verif_last_line(lst, line, ret));
}
