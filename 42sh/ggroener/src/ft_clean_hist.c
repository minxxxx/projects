/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_hist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 10:32:20 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 10:32:21 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**Take out this function if not needed
*/

static void		clean_lst_e(t_edit **lst)
{
	t_edit		*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp->next != NULL)
	{
		tmp->video = 0;
		tmp->c = '\0';
		tmp = tmp->next;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		free(*lst);
		*lst = tmp;
	}
	tmp->video = 0;
	tmp->c = '\0';
	tmp->next = NULL;
	tmp->prev = NULL;
	free(tmp);
	*lst = NULL;
	tmp = NULL;
}

void			ft_clean_thist(t_hist **hst)
{
	t_hist		*tmp;

	tmp = NULL;
	if (!*hst)
		return ;
	tmp = *hst;
	while (tmp->next != NULL)
	{
		clean_lst_e(&tmp->ptr);
		tmp->valid = 0;
		tmp = tmp->next;
		(*hst)->next = NULL;
		(*hst)->prev = NULL;
		free((*hst));
		*hst = tmp;
	}
	clean_lst_e(&tmp->ptr);
	tmp->valid = 0;
	(*hst)->next = NULL;
	(*hst)->prev = NULL;
	free((*hst));
	*hst = NULL;
	tmp = NULL;
}
