/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filled_lste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:17:59 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/09 16:18:01 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		lst_no_exist(t_edit **lst, t_hist **hst)
{
	t_edit		*new;
	t_hist		*new_hst;

	new_hst = NULL;
	new = (t_edit *)malloc(sizeof(t_edit));
	new->video = -1;
	new->next = NULL;
	new->prev = NULL;
	*lst = new;
	new_hst = (t_hist *)malloc(sizeof(t_hist));
	new_hst->valid = 1;
	new_hst->ptr = new;
	new_hst->prev = NULL;
	new_hst->next = *hst;
	if (*hst)
		(*hst)->prev = new_hst;
	*hst = new_hst;
}

static void		lst_exist(t_edit **lst, char *key)
{
	t_edit		*tmp;
	t_edit		*new;

	tmp = *lst;
	new = (t_edit *)malloc(sizeof(t_edit));
	new->c = *key;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (tmp->video == 0)
	{
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		new->next = tmp;
		new->prev = tmp->prev;
		if (new->prev == NULL)
			*lst = new;
		else
			tmp->prev->next = new;
		tmp->prev = new;
	}
	new->video = 0;
}

static void		lst_exist_noinit(t_edit **lst, char *key)
{
	(*lst)->c = *key;
	(*lst)->video = 0;
}

int				ft_filled_lste(char *key, t_edit **lst, t_hist **hst)
{
	if (!*lst)
		lst_no_exist(lst, hst);
	else if ((*lst)->video == -1)
		lst_exist_noinit(lst, key);
	else
		lst_exist(lst, key);
	return (0);
}
