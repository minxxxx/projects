/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:16:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:16:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void			free_pipe_list(t_pipe **lst)
{
	t_pipe	*tmp;
	int		i;

	i = 0;
	while (*lst)
	{
		free((*lst)->name);
		tmp = (*lst)->next;
		if ((*lst)->argv)
		{
			while ((*lst)->argv[i] != '\0')
			{
				free((*lst)->argv[i]);
				i++;
			}
			i = 0;
			free((*lst)->argv);
		}
		free(*lst);
		*lst = tmp;
	}
}

static int			add_to_argv(t_pipe **lst)
{
	t_pipe	*tmp;
	t_pipe	*tmp2;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp->prior > 2 && tmp->next && tmp->next->prior == 4 && ++i)
		tmp = tmp->next;
	if (((*lst)->argv = (char **)malloc((i + 2) * sizeof(char *))))
	{
		(*lst)->argv[i + 1] = NULL;
		(*lst)->argv[0] = ft_strdup((*lst)->name);
		i = 1;
		tmp = *lst;
		while (tmp->prior > 2 && tmp->next && tmp->next->prior == 4)
		{
			(*lst)->argv[i] = tmp->next->name;
			i++;
			tmp2 = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp2;
		}
	}
	return (0);
}

static int			clean_pipe_list(t_pipe **lst)
{
	t_pipe	*tmp;

	tmp = *lst;
	while (tmp)
	{
		add_to_argv(&tmp);
		tmp = tmp->next;
	}
	return (1);
}

static int			check_pipe_list(t_pipe **lst)
{
	t_pipe	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->nbr = i;
		i++;
		if (tmp->code == AR_LEFT || tmp->code == AR_RIGHT
			|| tmp->code == DB_AR_RIGHT)
		{
			if (!tmp->argv[1])
			{
				ft_putstr_fd("Redirection error near \" ", 2);
				ft_putstr_fd(tmp->name, 2);
				ft_putstr_fd("\"\n", 2);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	if (ft_check_pipes(lst) == 0)
		return (0);
	return (1);
}

int					ft_lexer(char *str, t_data *env)
{
	int		ret;
	t_pipe	*lst;
	t_pipe	*path;
	int		i;

	ret = 0;
	i = 0;
	lst = ft_make_pipelst(str);
	clean_pipe_list(&lst);
	if (!check_pipe_list(&lst))
	{
		free_pipe_list(&lst);
		return (0);
	}
	path = ft_create_path(&lst);
	ret = ft_read_path(path, env, 1);
	free_pipe_list(&lst);
	return (1);
}
