/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_pipelst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:52:18 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 12:52:22 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		add_end_2(char *str, int prior, int code, t_pipe **start)
{
	t_pipe	*tmp;

	tmp = *start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_pipe *)malloc(sizeof(t_pipe));
	tmp->next->name = ft_strdup(str);
	tmp->next->code = code;
	tmp->next->prior = prior;
	tmp->next->next = NULL;
	tmp->next->top = NULL;
	tmp->next->lft = NULL;
	tmp->next->rgt = NULL;
	tmp->next->argv = NULL;
	tmp->next->stat = 0;
	tmp->next->nbr = 0;
}

static void		add_end(char *str, int prior, int code, t_pipe **start)
{
	if (!*start)
	{
		*start = (t_pipe *)malloc(sizeof(t_pipe));
		(*start)->name = ft_strdup(str);
		(*start)->code = code;
		(*start)->prior = prior;
		(*start)->next = NULL;
		(*start)->top = NULL;
		(*start)->lft = NULL;
		(*start)->rgt = NULL;
		(*start)->nbr = 0;
		(*start)->argv = NULL;
		(*start)->stat = 0;
	}
	else
		add_end_2(str, prior, code, start);
}

static void		make_list_item(char *str, t_pipe **start)
{
	if (str[0] == ';')
		add_end(str, 0, SEMICOL, start);
	else if (str[0] == '>' && str[1] == '>')
		add_end(str, 3, DB_AR_RIGHT, start);
	else if (str[0] == '|' && str[1] == '|')
		add_end(str, 1, OR, start);
	else if (str[0] == '&' && str[1] == '&')
		add_end(str, 1, AND, start);
	else if (str[0] == '>')
		add_end(str, 3, AR_RIGHT, start);
	else if (str[0] == '<' && str[1] == '<')
		add_end(str, 3, DB_AR_LEFT, start);
	else if (str[0] == '<')
		add_end(str, 3, AR_LEFT, start);
	else if (str[0] == '|' && str[1] == '\0')
		add_end(str, 2, PIPE, start);
	else
		add_end(str, 4, COM, start);
}

t_pipe			*ft_make_pipelst(char *str)
{
	char	*s;
	char	**arr;
	t_pipe	*start;
	int		i;

	i = 0;
	start = NULL;
	s = ft_strtrim(str);
	free(str);
	arr = ft_split(s);
	free(s);
	while (arr[i] != '\0')
	{
		make_list_item(arr[i], &start);
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	return (start);
}
