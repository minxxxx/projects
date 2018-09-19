/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigleton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 16:33:29 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/10 16:33:30 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**Take out this function if not needed
*/

int			ft_sigleton(int i)
{
	static int		value = 0;

	if (i == 0)
		return (value);
	else if (i == -1)
		value = 0;
	else
		value = i;
	return (value);
}
