/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 13:14:14 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 13:34:24 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		compute_w(char *str, int *w_count)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			w++;
		while (str[i] != ' ')
		{
			w_size[w - 1] = w_size[w - 1] + 1;
			i++;
		}
		while (str[i] == ' ')
			i++;
	}
	return (w);
}

char	**ft_split_whitespaces(char *str)
{
	int		w_count;
	int		tab[10];
	char	*t;
	char	**s;
	int		i;

	i = 0;
	w_count = compute_n_w(str, tab);
	*s = (char*)malloc(sizeof(**s) * (w_count + 1));
	while (i < w_count)
	{
		s[i] = (char*)malloc(sizeof(*t) * (tab[i] + 1));
		i++;
	}
}
