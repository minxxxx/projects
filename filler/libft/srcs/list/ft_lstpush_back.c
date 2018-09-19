/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:33:01 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 04:38:53 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **l, void const *c, size_t s)
{
	t_list	*list;

	list = *l;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(c, s);
	}
	else
		*l = ft_lstnew(c, s);
}
