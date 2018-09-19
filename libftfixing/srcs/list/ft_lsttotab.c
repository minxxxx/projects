/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:17 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:18:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	**ft_lsttotab(t_list *l)
{
	void	**tab;
	size_t	size;
	size_t	i;
	t_list	*list;

	list = l;
	size = ft_lstsize(l);
	if ((tab = (void **)ft_memalloc(size * sizeof(void *) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size && list)
	{
		if ((tab[i] = (void *)ft_memalloc(list->content_size)) == NULL)
			return (NULL);
		tab[i] = memcpy(tab[i], list->content, list->content_size);
		list = list->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
