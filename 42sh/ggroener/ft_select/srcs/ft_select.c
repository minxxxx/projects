/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:15:56 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/17 09:57:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				main(int argc, char **argv)
{
	static t_search	*s;
	static t_choice	*c;

	if (argc < 2 || ft_init())
	{
		if (argc < 2)
			ft_putstr("Error: Too few arguments.\n");
		return (-1);
	}
	s = NULL;
	c = ft_choice(argc - 1, argv + 1);
	ft_signal(0);
	ft_cmdput("ti");
	ft_cmdput("cl");
	ft_caption(GKEY_ZERO, -1);
	if (ft_select(&c, &s, &argc, 0) == GKEY_RTN)
	{
		ft_signal(-1);
		ft_putchoice(argc, &c, 1);
	}
	else
		ft_signal(0);
	return (0);
}

static void		ft_select_deleg(t_choice **c, int *argc, int key, int *pos)
{
	if (key == GKEY_UP)
		*pos -= 1;
	else if (key == GKEY_DOWN)
		*pos += 1;
	if (*pos < 0)
		*pos = *argc - 2;
	else
		*pos = *pos % (*argc - 1);
	ft_putcirc(*argc, c, pos, key);
	return ;
}

static int		ft_select_search(t_choice **c, t_search **s, char *a, int *pos)
{
	int			key;
	int			result;
	static int	keep;

	result = 0;
	key = 0;
	if (s == NULL && *s == NULL && (*s)->str == NULL)
		keep = *pos;
	if (allowed_keys(key, s))
	{
		result = 1;
		free((*s)->str);
		free(*s);
		if (key == GKEY_ESC)
			*pos = keep;
	}
	else if (ft_search(c, s, a))
	{
		if (*s != NULL && (*s)->str != NULL && (*s)->nbr > -1 && (result = 1))
			*pos = (*s)->nbr;
	}
	return (result);
}

static void		ft_select_search_view(t_search *s, int argc, int search)
{
	int		k;

	if ((k = ft_termsize(1)) && s != NULL && s->str != NULL)
	{
		if (ft_decal(argc, k))
		{
			ft_cmdgoto(1, k - 1);
			ft_cmdput("mr");
			ft_putstr_fd("\033[2;49;90m", isatty(0));
		}
		else
		{
			k = (k < argc) ? 0 : (k - argc) / 2 + (k & 2);
			ft_cmdgoto(2, k + argc + 1);
		}
		ft_putstr_fd("Search word: ", isatty(0));
		ft_putstr_fd(s->str, isatty(0));
		if (ft_strlen(s->str) < 10)
			ft_putchar_fd('_', isatty(0));
	}
	else if (search)
	{
		ft_clear();
		ft_putcirc(0, NULL, NULL, 0);
	}
}

int				ft_select(t_choice **c, t_search **s, int *argc, int search)
{
	static int	pos = 0;
	static int	key = 0;
	static char	*a;

	ft_putcirc(*argc, c, &pos, 0);
	while (ft_cmdgoto(0, 0) && (a = ft_getch()))
	{
		if (!(key = ft_getkey(a)))
			break ;
		search = ft_select_search(c, s, a, &pos);
		if (a != NULL)
			free(a);
		if ((!search && key == GKEY_BSP) || key == GKEY_DEL)
			ft_delmenu(argc, c, &pos);
		if (!search && (GKEY_ESC == key || key == GKEY_RTN))
			break ;
		else if (!search && key == GKEY_ESP && ft_sound(key) && ++pos)
			c[0][pos - 1].check = (c[0][pos - 1].check + 1) % 2;
		ft_select_deleg(c, argc, key, &pos);
		ft_select_search_view(*s, *argc, search);
	}
	return (key);
}
