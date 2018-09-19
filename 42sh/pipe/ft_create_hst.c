/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_hst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:14:01 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/09 16:14:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void			add_link_tedit(char c, t_edit **lst)
{
	t_edit		*tmp;
	t_edit		*new;

	tmp = NULL;
	new = (t_edit *)malloc(sizeof(t_edit));
	new->c = c;
	new->video = 0;
	new->next = NULL;
	new->prev = NULL;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

static t_edit		*filled_t_edit(char **line)
{
	char		*str;
	int			i;
	t_edit		*lst;

	lst = NULL;
	str = *line;
	i = 0;
	while (str[i] != '\0')
	{
		add_link_tedit(str[i], &lst);
		i++;
	}
	return (lst);
}

static void			add_line_hst(t_hist **hst, char **line)
{
	t_hist		*tmp_hst;
	t_hist		*new_hst;
	t_edit		*new_edit;

	tmp_hst = NULL;
	new_hst = (t_hist *)malloc(sizeof(t_hist));
	new_edit = filled_t_edit(line);
	if (!*hst)
	{
		*hst = new_hst;
		new_hst->next = NULL;
	}
	else
	{
		new_hst->next = *hst;
		(*hst)->prev = new_hst;
		*hst = new_hst;
	}
	new_hst->valid = 0;
	new_hst->prev = NULL;
	new_hst->ptr = new_edit;
}

int					ft_create_hst(t_hist **hst, char **env)
{
	char		*line;
	int			fd;
	char		*file;

	(void)env;
	line = NULL;
	file = ft_strjoin(getenv("HOME"), FT_FILE);
	fd = open(file, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRWXG);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		add_line_hst(hst, &line);
		ft_bzero(line, ft_strlen(line));
		free(line);
	}
	close(fd);
	free(file);
	return (0);
}
