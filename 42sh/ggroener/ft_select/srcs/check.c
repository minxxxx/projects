/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:14:00 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:14:03 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_check_move(int key, t_choice **c, int pos)
{
	int		result;
	int		check;
	char	*str;

	result = 0;
	str = c[0][pos + 1].str;
	check = c[0][pos + 1].check;
	if (key == GKEY_PLUS && c[0][pos + 1].str != NULL && (result = 1))
	{
		c[0][pos + 1].str = c[0][pos].str;
		c[0][pos + 1].check = c[0][pos].check;
	}
	else if (key == GKEY_MINUS && pos > 0 && (result = 1))
	{
		str = c[0][pos - 1].str;
		check = c[0][pos - 1].check;
		c[0][pos - 1].str = c[0][pos].str;
		c[0][pos - 1].check = c[0][pos].check;
	}
	if (result && str != NULL)
	{
		c[0][pos].str = str;
		c[0][pos].check = check;
	}
	return (result);
}

static int	ft_check_overflow(int argc, int key, int pos, int pos2)
{
	int		k;
	int		l;

	k = ft_columns(argc + 1);
	l = ft_termsize(1);
	if (ft_decal(argc, l))
		l--;
	if (key == 0 && ft_columns(pos + 1) < k)
	{
		if ((pos + l) >= argc && (pos % l) == (l - 1))
			pos2 -= l;
	}
	else if (key == 1 && !pos)
		pos2 = argc - 1;
	else if (key == 1 && pos == 1 && (argc % l) == 1)
		pos2 += l;
	return (pos2);
}

static int	ft_check_target(int argc, int key, int *pos)
{
	int		k;
	int		l;
	int		pos2;

	if (key != GKEY_RIGHT && key != GKEY_LEFT)
		return (0);
	k = ft_columns(argc);
	l = ft_termsize(1);
	if (argc > l)
	{
		pos2 = *pos + ((k - 1) * l) - 1;
		if (key == GKEY_RIGHT && (*pos + l) < argc)
			*pos += l;
		else if (key == GKEY_RIGHT)
			*pos = ft_check_overflow(argc, 0, *pos, *pos % l + 1);
		else if (key == GKEY_LEFT && *pos - l >= 0)
			*pos -= l;
		else if (key == GKEY_LEFT)
			*pos = ft_check_overflow(argc, 1, *pos, pos2);
	}
	return (1);
}

void		ft_check(int argc, int key, t_choice **choice, int *pos)
{
	int		k;

	k = -1;
	if (ft_check_target(argc - 1, key, pos))
		return ;
	while ((key == GKEY_STAR || key == GKEY_DIV) && choice[0][++k].str)
		choice[0][k].check = (key == GKEY_STAR) ? 1 : 0;
	while ((key == GKEY_PLUS || key == GKEY_MINUS) && choice[0][++k].str)
	{
		if (k == *pos)
		{
			if (ft_check_move(key, choice, *pos))
				*pos += (key == GKEY_PLUS) ? 1 : -1;
			break ;
		}
	}
	if (key == GKEY_ESP || key == GKEY_DEL || key == GKEY_BSP)
	{
		if (key != GKEY_ESP)
			ft_clear();
	}
	return ;
}
