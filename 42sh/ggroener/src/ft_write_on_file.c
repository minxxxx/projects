/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_on_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 10:11:53 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 10:11:54 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		check_lst(t_edit **lst)
{
	t_edit		*tmp;
	int			i;
	int			mark;

	mark = 0;
	tmp = *lst;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp->next && tmp->c != '\0')
	{
		if (tmp->c != ' ' && tmp->c != '\t')
		{
			mark = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (mark != 1)
		return (-1);
	return (0);
}

int				ft_write_on_file(t_edit **lst, char **env)
{
	t_edit		*tmp;
	int			fd;
	char		*file;

	(void)env;
	tmp = *lst;
	file = ft_strjoin(getenv("HOME"), FT_FILE);
	if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
		return (-1);
	if (check_lst(lst) == -1)
		return (-2);
	while (tmp != NULL)
	{
		if (tmp->c)
			write(fd, &tmp->c, 1);
		tmp = tmp->next;
	}
	write(fd, "\n", 1);
	close(fd);
	FREE_(file);
	return (0);
}
