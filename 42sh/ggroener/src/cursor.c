/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 16:31:00 by khansman          #+#    #+#             */
/*   Updated: 2016/09/11 11:40:02 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cursor(void)
{
	struct termios	*new;
	static int		k;

	new = NULL;
	if (k != 0)
	{
		new->c_lflag = 536871320;
		k = 0;
	}
	else
	{
		new->c_lflag = ECHONL;
		k = 1;
	}
}
