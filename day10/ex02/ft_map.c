/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 08:34:15 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/13 08:49:14 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *n_tab;

	i = 0;
	n_tab = (int*)malloc(sizeof(int) * length);
	while (i < length)
	{
		n_tab[i] = f(tab[i]);
		i++;
	}
	return (n_tab);
}
