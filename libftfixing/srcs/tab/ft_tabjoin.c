/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:29:56 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 00:30:52 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabjoin(int *t1, int *t2)
{
	int		*tab;
	int		size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = ft_tablen(t1) + ft_tablen(t2);
	if ((tab = (int *)ft_memalloc(size * sizeof(int) + 1)) == NULL)
		return (NULL);
	while (t1[i])
	{
		tab[i] = t1[i];
		i++;
	}
	while (t2[j])
	{
		tab[i + j] = t2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
