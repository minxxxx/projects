/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:14:19 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:14:20 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_clear(void)
{
	int		k;

	k = ft_termsize(1);
	while (k > 0)
	{
		ft_cmdgoto(0, k);
		ft_cmdput("dl");
		k--;
	}
}

void	ft_clear_screen(void)
{
	int		k;
	int		l;

	k = 0;
	while (k < ft_termsize(0))
	{
		l = 0;
		while (l < ft_termsize(1))
		{
			ft_cmdgoto(k, l);
			ft_putchar_fd(' ', isatty(1));
			l++;
		}
		k++;
	}
}
