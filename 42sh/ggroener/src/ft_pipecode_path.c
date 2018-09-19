/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipecode_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:58:10 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 12:58:11 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_pipecode_path(t_pipe **tmp, t_data *env, int flag)
{
	int		ret;

	ret = 0;
	(void)env;
	if ((*tmp)->code == 0)
		ret = ft_semicol(tmp, env);
	else if ((*tmp)->code == 1)
		ret = ft_and(tmp, env);
	else if ((*tmp)->code == 2)
		ret = ft_or(tmp, env);
	else if ((*tmp)->code == 3)
		ret = ft_pipe(tmp, env);
	else if ((*tmp)->code == 4)
		ret = ft_ar_lft(tmp, env);
	else if ((*tmp)->code == 5)
		ret = ft_ar_rgt(tmp, env);
	else if ((*tmp)->code == 6)
		ret = ft_db_ar_rgt(tmp, env);
	else if ((*tmp)->code == 7)
		ret = ft_db_ar_lft(tmp, env, flag);
	return (ret);
}
