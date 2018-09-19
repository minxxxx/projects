/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semicol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:13:43 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:13:50 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_semicol(t_pipe **tmp, t_data *env)
{
	ft_read_path((*tmp)->rgt, env, 1);
	ft_read_path((*tmp)->lft, env, 1);
	return (0);
}
