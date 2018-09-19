/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 16:24:28 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/09 16:24:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		put_fd(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

int		ft_tputs(char *str)
{
	if (tputs(tgetstr(str, NULL), 1, put_fd) == -1)
		return (-1);
	return (0);
}
