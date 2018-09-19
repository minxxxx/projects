/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caption.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:10:45 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:20:13 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_caption_clear(int clear, int key, int on)
{
	static int	status;

	if ((key == GKEY_ZERO && clear == -1) || on)
	{
		status = 1;
		return (1);
	}
	else if (clear)
	{
		if (status)
			ft_clear();
		status = 0;
		return (1);
	}
	return (0);
}

static void		ft_caption_line(int line, int k)
{
	ft_cmdgoto(k, line);
	ft_putstr_fd(" +", isatty(1));
	ft_putchar_loop_fd('-', isatty(1), 21);
	ft_putstr_fd("+ ", isatty(1));
}

static void		ft_caption_putstr(char *str, int line, int k)
{
	ft_cmdgoto(k, line);
	ft_putstr_fd(str, isatty(1));
}

int				ft_caption(int key, int clear)
{
	int		k;

	if (ft_caption_clear(clear, key, 0))
		return (0);
	if (key == GKEY_ZERO && ft_caption_clear(clear, key, 1))
	{
		k = ft_termsize(0) - 25;
		ft_cmdgoto(k, 0);
		ft_cmdput("mr");
		ft_caption_putstr("[File colour  :'.'     ]", 1, k);
		ft_caption_putstr("[Select all   :* /     ]", 2, k);
		ft_caption_putstr("[Move item    :+ -     ]", 3, k);
		ft_caption_putstr("[Select item  :spacebar]", 4, k);
		ft_caption_putstr("[Delete item  :del     ]", 5, k);
		ft_caption_putstr("[Move         :arrows  ]", 6, k);
		ft_caption_line(7, k);
		ft_cmdput("me");
		return (1);
	}
	return (0);
}
