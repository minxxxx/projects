/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:18:34 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:18:37 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_search_deleg(t_search **list, int key)
{
	int					ret;

	ret = -1;
	if (*list == NULL)
		return (ret);
	if (key == GKEY_RTN)
	{
		if (list[0][0].str != NULL)
			free(list[0][0].str);
		free(*list);
		*list = NULL;
	}
	else if (key == GKEY_ESC && !(ret = 0))
	{
		if (list[0][0].str != NULL)
			free(list[0][0].str);
		free(*list);
		*list = NULL;
	}
	return (ret);
}

static t_choice	*ft_search_while(t_choice **ch, char *str, int *nbr)
{
	char				*search;
	t_choice			*ptr;

	ptr = *ch;
	search = ft_strjoin("*", str);
	if (search && (search = ft_strfjoin1(&search, "*", 1)))
	{
		while (ch[0][*nbr].str != NULL)
		{
			if (ft_match(ch[0][*nbr].str, search))
			{
				ptr = (*ch + *nbr);
				return (ptr);
			}
			*nbr += 1;
		}
	}
	if (search)
		free(search);
	*nbr = 0;
	return (ptr);
}

static t_search	*ft_search_create(t_choice **ch, char *str, int *nbr)
{
	t_search			*list;

	list = (t_search *)malloc(sizeof(t_search));
	list[0].str = ft_strtrim(str);
	list[0].nbr = *nbr;
	list[0].first = ft_search_while(ch, str, nbr);
	return (list);
}

int				ft_search(t_choice **o, t_search **t, char *c)
{
	int					nbr;
	int					key;
	char				*str;

	nbr = 0;
	str = ft_ctoa(*c);
	key = ft_getkey(c);
	ft_search_deleg(t, key);
	if (key != GKEY_RTN && key != GKEY_ESC)
	{
		if (*t == NULL && key == -1 && ft_isprint(*c) && *(c + 1) == 0)
			*t = ft_search_create(o, str, &nbr);
		else if (*t != NULL && t[0][0].str != NULL)
		{
			if (key == GKEY_BSP && (nbr = ft_strlen(t[0][0].str)))
				t[0][0].str = ft_strfsub(&t[0][0].str, 0, nbr - 1, 1);
			else if (ft_strlen(t[0][0].str) < 10 && ft_isprint(*c))
				t[0][0].str = ft_strfjoin1(&t[0][0].str, str, 1);
			if (!(nbr = 0) && t[0][0].str != NULL)
				t[0][0].first = ft_search_while(o, t[0][0].str, &t[0][0].nbr);
		}
	}
	if (str != NULL)
		free(str);
	return (1);
}
