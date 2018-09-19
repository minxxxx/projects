/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:36:15 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:36:17 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_and(t_pipe **and, t_data *env)
{
	int		ret;

	ret = 0;
	if ((ret = ft_read_path((*and)->rgt, env, 1)) == 0)
		ret = ft_read_path((*and)->lft, env, 1);
	return (ret);
}
