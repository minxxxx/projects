/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:44:09 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/14 15:49:24 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*a;
	t_list	*b;

	list = *begin_list;
	if (!list || !(list->next))
		return (0);
	a = list->next;
	b = a->next;
	list->next = list;
	while (b)
	{
		list = a;
		a = b;
		b = b->next;
		a->next = list;
	}
	*begin_list = a;
}
