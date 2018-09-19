/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:03:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 12:03:06 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		check_left(t_pipe **tmp, t_pipe **save)
{
	if (!(*tmp)->lft)
	{
		(*tmp)->lft = *save;
		(*save)->top = *tmp;
	}
	else
		*tmp = (*tmp)->lft;
}

static void		check_right(t_pipe **tmp, t_pipe **save)
{
	if (!(*tmp)->rgt)
	{
		(*tmp)->rgt = *save;
		(*save)->top = *tmp;
	}
	else
		*tmp = (*tmp)->rgt;
}

static void		add_pipe_path(t_pipe **tree, t_pipe *save)
{
	t_pipe		*tmp;

	tmp = NULL;
	if (!save)
		return ;
	if (!*tree)
		*tree = save;
	else
	{
		tmp = *tree;
		while (!save->top)
		{
			if (save->nbr < tmp->nbr)
				check_right(&tmp, &save);
			else
				check_left(&tmp, &save);
		}
	}
}

t_pipe			*ft_create_path(t_pipe **lst)
{
	t_pipe		*tree;
	t_pipe		*save;
	t_pipe		*tmp;

	tree = NULL;
	tmp = *lst;
	save = *lst;
	while (save)
	{
		save = NULL;
		while (tmp)
		{
			if (!save && tmp->stat == 0)
				save = tmp;
			else if (save && tmp->prior <= save->prior && tmp->stat == 0)
				save = tmp;
			tmp = tmp->next;
		}
		if (save)
			save->stat = 1;
		add_pipe_path(&tree, save);
		tmp = *lst;
	}
	return (tree);
}
