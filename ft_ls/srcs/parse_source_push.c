/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_source_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:22:57 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:22:59 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	insert(t_env *env, t_source *ls, t_source *cs)
{
	if (env->f)
		return (0);
	if (env->t && cs->sort_date != ls->sort_date)
	{
		if (env->r)
			return (cs->sort_date < ls->sort_date);
		else
			return (cs->sort_date > ls->sort_date);
	}
	else
	{
		if (env->r)
			return (ft_strcmp(cs->display_path, ls->display_path) > 0);
		else
			return (ft_strcmp(cs->display_path, ls->display_path) < 0);
	}
}

static void	swap(t_env *env, t_source *lst, t_source *source, t_source *prv)
{
	source->next = lst;
	if (prv)
		prv->next = source;
	else
		env->sources = source;
}

void		parse_source_push(t_env *env, t_source *source)
{
	t_source	*lst;
	t_source	*prv;

	if (!(env->sources))
	{
		env->sources = source;
		return ;
	}
	lst = env->sources;
	prv = NULL;
	while (lst)
	{
		if (insert(env, lst, source))
		{
			swap(env, lst, source, prv);
			return ;
		}
		if (!lst->next)
		{
			lst->next = source;
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
