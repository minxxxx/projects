/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:12:40 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 12:12:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				ft_read_path(t_pipe *tree, t_data *env, int flag)
{
	int		temp;

	temp = 0;
	if (!tree)
		return (-1);
	if (tree)
	{
		if (tree->code < COM)
			temp = ft_pipecode_path(&tree, env, flag);
		else if (tree->code == COM)
			temp = ft_execve(tree->name, tree->argv, env);
	}
	return (temp);
}
